using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArkhamHorrorCore
{
    enum Phases
    {
        Upkeep,
        Movement,
        ArkhamEncounters,
        OtherWorldEncounters,
        Mythos
    }

    class Core
    {
        private SortedList<int, Investigator> _investigators;
        private List<Monster> _monsters;
        private int _currentPlayer;
        private int _currentRound;
        private int _terrorLevel;
        private int _portals;

        public void UpkeepPhase()
        {
            foreach(Investigator investigator in _investigators.Values)
            {
                // Refresh Exausted Cards
                // Perform Upkeep Actions
                // Adjust Skills
            }
        }

        public void MovementPhase()
        {
            foreach (Investigator investigator in _investigators.Values)
            {
                /*
                // in Arkham?
                    // Set movement points

                    // In any order:
                        // move to adjacent street/location
                            // remove explored marker
                            // must evade or movement ends + fight
                        // activate item
                        // trade (if same location)

                    // ends in area with monster?
                        // must evade or move
                            // unconsciuous? -> Hospital
                            // insane? -> Asylum
                    // end in area with clue?
                        // may pick it up
                 // in other worlds?
                    // if left move to right
                    // if right any gate and explored marker
              */
            }
        }

        public void ArkhamEncountersPhase()
        {
            foreach (Investigator investigator in _investigators.Values)
            {
                /*
                // if location
                    // if no gate
                        // have encounter
                            // shuffle location deck
                            // draw
                            // resolve all actions of location
                                // if monster appear
                                    // must evade or fight
                                    // if monster evaded -> put in cup
                                // if gate appear
                                    // drawn in gate and delayed
                        // location special ability
                // if gate
                    // if no explored marker
                        // in first area of gate
                    // if explored marker
                        // close or seal
                  */
            }
        }

        public void OtherWorldsEncountersPhase()
        {
            foreach (Investigator investigator in _investigators.Values)
            {
            }
        }

        public void MythosPhase()
        {
            // Open Gate
            // Spawn Monster at gate
            // Place clue token
            // Move monsters
            // Activate mythos ability
        }

        public void Fight(Monster monster, Investigator investigator, int mods)
        {
            int dice = investigator.Fight + mods + monster.CombatRating;
            Random rand = new Random();
            int successes = 0;
            int successThreshold = 5;
            if (investigator.Blessed)
            {
                successThreshold = 4;
            }
            else if (investigator.Cursed)
            {
                successThreshold = 6;
            }
            for (int die = 0; die < dice; ++die)
            {
                if (rand.Next(1, 7) >= successThreshold)
                {
                    ++successes;
                }
            }
            if (successes < monster.Toughness)
            {
                investigator.damageStamina(monster.CombatDamage);
            }
            else
            {
                _monsters.Remove(monster);
            }
        }
    }
}
