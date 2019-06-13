using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArkhamHorrorCore
{
    enum Dimension
    {
        Plus,
        Slash,
        Circle,
        Moon,
        Hexagon,
        Square,
        Triangle
    };

    enum DimensionColor
    {
        Black,
        White
    }

    enum Movement
    {
        Normal, // black
        Stationary, // yellow
        Fast, // red
        Unique, //green
        Flying, // blue
        Stalker, // purple
        Acquatic, // orange
        None
    };

    struct MonsterAbility
    {
        private readonly string _name;
        private readonly int _value;
    }

    public class Monster
    {
        // Description
        private readonly string _name;
        private readonly string _text;
        private readonly List<MonsterAbility> _abilities;

        // Movement
        private readonly Movement _movement;
        private readonly Dimension _dimension;
        private readonly DimensionColor _dimensionColor;
        private readonly int _awareness; // modifier to Evade Check (top right)

        // Combat
        private readonly int _toughness; // difficulty of Combat Check (blood drops)
        private readonly bool _hasHorrorRating; // if True investigator must make Horror Check
        private readonly int _horrorRating; // modifier to Horror Check (lower left)
        private readonly int _horrorDamage; // Sanity damage on failed Horror Check (lower left)
        private readonly int _combatRating; // modifier to Combat Check (lower right)
        private readonly int _combatDamage; // Stamina damage on failed Combat Check (red hearts)
    }
}
