
#ifndef MANGOS_MASS_MAIL_MGR_H
#define MANGOS_MASS_MAIL_MGR_H

#include "Common.h"
#include "Mail.h"
#include "Policies/Singleton.h"

#include <memory>

/**
 * A class to represent the mail send factory to multiple (often all existing) characters.
 *
 * Note: implementation not persistence for server shutdowns
 */
class MassMailMgr
{
    public:                                                 // Constructors
        MassMailMgr() {}

    public:                                                 // Accessors
        void GetStatistic(uint32& tasks, uint32& mails, uint32& needTime) const;

    public:                                                 // modifiers
        typedef UNORDERED_SET<uint32> ReceiversList;

        /**
         * And new mass mail task for raceMask filter applied to characters list.
         *
         * @param mailProto     prepared mail for clone and send to characters, will deleted in result call.
         * @param raceMask      mask of races that must receive mail.
         *
         * Note: this function safe to be called from Map::Update content/etc, real data add will executed in next tick after query results ready
         */
        void AddMassMailTask(MailDraft* mailProto, MailSender sender, uint32 raceMask);

        /**
         * And new mass mail task with SQL query text for fill receivers list.
         *
         * @param mailProto     prepared mail for clone and send to characters, will deleted in result call
         * @param queryStr      SQL query for get guid list of receivers, first field in query result must be uint32 low guids list.
         *
         * Note: this function safe to be called from Map::Update content/etc, real data add will executed in next tick after query results ready
         */
        void AddMassMailTask(MailDraft* mailProto, MailSender sender, char const* queryStr);

        /**
         * And new mass mail task and let fill receivers list returned as result.
         *
         * @param mailProto     prepared mail for clone and send to characters, will deleted in result call
         * @returns reference to receivers list for it fill in caller code.
         *
         * Note: this function NOT SAFE for call from Map::Update content/etc
         */
        ReceiversList& AddMassMailTask(MailDraft* mailProto, MailSender sender)
        {
            m_massMails.push_back(MassMail(mailProto, sender));
            return m_massMails.rbegin()->m_receivers;
        }

        /**
         * Next step in mass mail activity, send some amount mails from queued tasks
         */
        void Update(bool sendall = false);

    private:

        /// Mass mail task store mail prototype and receivers list who not get mail yet
        struct MassMail
        {
            explicit MassMail(MailDraft* mailProto, MailSender sender)
                : m_protoMail(mailProto), m_sender(sender)
            {
                MANGOS_ASSERT(mailProto);
            }

            MassMail(MassMail const& massmail)
                : m_protoMail(const_cast<MassMail&>(massmail).m_protoMail), m_sender(massmail.m_sender)
            {
            }

            /// m_protoMail is owned by MassMail, so at copy original MassMail field set to NULL
            std::auto_ptr<MailDraft> m_protoMail;

            MailSender m_sender;
            ReceiversList m_receivers;
        };

        typedef std::list<MassMail> MassMailList;

        /// List of current queued mass mail tasks
        MassMailList m_massMails;
};

#define sMassMailMgr MaNGOS::Singleton<MassMailMgr>::Instance()

#endif
/*! @} */
