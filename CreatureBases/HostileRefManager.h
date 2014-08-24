
#ifndef _HOSTILEREFMANAGER
#define _HOSTILEREFMANAGER

#include "Common.h"
#include "ObjectGuid.h"
#include "Utilities/LinkedReference/RefManager.h"

class Unit;
class ThreatManager;
class HostileReference;
struct SpellEntry;

//=================================================

class HostileRefManager : public RefManager<Unit, ThreatManager>
{
    public:
        explicit HostileRefManager(Unit* pOwner);
        ~HostileRefManager();

        Unit* getOwner() { return iOwner; }

        // send threat to all my hateres for the pVictim
        // The pVictim is hated than by them as well
        // use for buffs and healing threat functionality
        void threatAssist(Unit* pVictim, float threat, SpellEntry const* threatSpell = 0, bool pSingleTarget = false);

        void addThreatPercent(int32 pValue);

        // The references are not needed anymore
        // tell the source to remove them from the list and free the mem
        void deleteReferences();

        // Remove specific faction references
        void deleteReferencesForFaction(uint32 faction);

        HostileReference* getFirst() { return ((HostileReference*) RefManager<Unit, ThreatManager>::getFirst()); }

        void updateThreatTables();

        void setOnlineOfflineState(bool pIsOnline);

        // set state for one reference, defined by Unit
        void setOnlineOfflineState(Unit* pCreature, bool pIsOnline);

        // delete one reference, defined by Unit
        void deleteReference(Unit* pCreature);

        // redirection threat data
        void SetThreatRedirection(ObjectGuid guid, uint32 pct)
        {
            m_redirectionTargetGuid = guid;
            m_redirectionMod = pct / 100.0f;
        }

        void ResetThreatRedirection()
        {
            m_redirectionTargetGuid.Clear();
            m_redirectionMod = 0.0f;
        }

        float GetThreatRedirectionMod() const { return m_redirectionMod; }
        Unit*  GetThreatRedirectionTarget() const;

    private:
        Unit* iOwner;                                       // owner of manager variable, back ref. to it, always exist

        float      m_redirectionMod;
        ObjectGuid m_redirectionTargetGuid;
};
//=================================================
#endif
