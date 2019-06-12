using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArkhamHorrorCore
{
    enum Encounter
    {
        Spell,
        Stamina,
        Clue,
        Money,
        Skill,
        Sanity,
        Ally,
        CommonItem,
        UniqueItem,
        Monster
    }

    class Location
    {
        private readonly string _name;
        private readonly Encounter _encounter1;
        private readonly Encounter _encounter2;
        private readonly Neighborhood _deck;
        private readonly bool _unstable;
    }
}
