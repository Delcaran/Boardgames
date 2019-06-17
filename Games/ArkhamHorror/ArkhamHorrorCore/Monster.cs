using System;
using System.Collections.Generic;
using System.Xml;

namespace ArkhamHorrorCore
{
    public enum Dimension
    {
        Plus,
        Slash,
        Circle,
        Moon,
        Hexagon,
        Square,
        Triangle
    };

    public enum Movement
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

    public enum MonsterAbility
    {
        Ambush,
        Elusive,
        Endless,
        MagicalImmunity,
        MagicalResistance,
        Nightmarish,
        Overwhelming,
        PhysicalImmunity,
        PhysicalResistance,
        WeaponImmunity,
        Mask,
        Spawn
    }


    public class Monster
    {
        // Description
        private readonly Dictionary<string, string> _name; // <language, name>
        private readonly Dictionary<string, string> _text; // <language, text>
        private readonly int _available;
        private readonly Dictionary<MonsterAbility, int> _abilities; // <name, value>

        // Movement
        private readonly Movement _movement;
        private readonly Dimension _dimension;
        private readonly int _awareness; // modifier to Evade Check (top right)

        // Combat
        private readonly int _toughness; // difficulty of Combat Check (blood drops)
        private readonly bool _hasHorrorRating; // if True investigator must make Horror Check
        private readonly int _horrorRating; // modifier to Horror Check (lower left)
        private readonly int _horrorDamage; // Sanity damage on failed Horror Check (lower left)
        private readonly int _combatRating; // modifier to Combat Check (lower right)
        private readonly int _combatDamage; // Stamina damage on failed Combat Check (red hearts)

        public int CombatDamage
        {
            get
            {
                return _combatDamage;
            }
        }

        public int CombatRating
        {
            get
            {
                return _combatRating;
            }
        }

        public int HorrorDamage
        {
            get
            {
                return _horrorDamage;
            }
        }

        public int HorrorRating
        {
            get
            {
                return _horrorRating;
            }
        }

        public bool HasHorrorRating
        {
            get
            {
                return _hasHorrorRating;
            }
        }

        public int Toughness
        {
            get
            {
                return _toughness;
            }
        }

        public int Awareness
        {
            get
            {
                return _awareness;
            }
        }

        public Dictionary<MonsterAbility, int> Abilities
        {
            get
            {
                return _abilities;
            }
        }

        public int Available
        {
            get
            {
                return _available;
            }
        }

        public Dictionary<string, string> Text
        {
            get
            {
                return _text;
            }
        }

        public Dictionary<string, string> Name
        {
            get
            {
                return _name;
            }
        }

        public Dimension Dimension
        {
            get
            {
                return _dimension;
            }
        }

        public Movement Movement
        {
            get
            {
                return _movement;
            }
        }

        public Monster(string xml)
        {
            // Init
            _available = 0;
            _hasHorrorRating = false;
            _name = new Dictionary<string, string>();
            _text = new Dictionary<string, string>();
            _abilities = new Dictionary<MonsterAbility, int>();

            // Load data from XML
            XmlDocument monsterDocument = new XmlDocument();
            try
            {
                monsterDocument.Load(xml);
            }
            catch(System.IO.FileNotFoundException e)
            {
                Console.WriteLine("Error loading XML");
                Console.WriteLine(e.ToString());
                return;
            }
            XmlNode root = monsterDocument.FirstChild;
            if(root.HasChildNodes)
            {
                for(int i=0; i < root.ChildNodes.Count; i++)
                {
                    XmlNode node = root.ChildNodes[i];
                    switch(node.Name.ToLower())
                    {
                        case "number":
                            for(int exp=0; exp<node.ChildNodes.Count; ++exp)
                            {
                                // TODO: filter for unwanted expansions
                                int monstersInThisExpansion = 0;
                                Int32.TryParse(node.ChildNodes[exp].InnerText, out monstersInThisExpansion);
                                _available += monstersInThisExpansion;
                            }
                            break;
                        case "name":
                            for (int l = 0; l < node.ChildNodes.Count; ++l)
                            {
                                string lang = node.ChildNodes[l].Name.ToLower();
                                string name = node.ChildNodes[l].InnerText;
                                _name.Add(node.ChildNodes[l].Name.ToLower(), node.ChildNodes[l].InnerText);
                            }
                            break;
                        case "movement":
                            foreach(Movement val in Enum.GetValues(typeof(Movement)))
                            {
                                if(val.ToString() == node.InnerText)
                                {
                                    _movement = val;
                                    break;
                                }
                            }
                            break;
                        case "awareness":
                            int tmp = 0;
                            Int32.TryParse(node.InnerText, out tmp);
                            _awareness = tmp;
                            break;
                        case "dimension":
                            foreach (Dimension val in Enum.GetValues(typeof(Dimension)))
                            {
                                if (val.ToString() == node.InnerText)
                                {
                                    _dimension = val;
                                    break;
                                }
                            }
                            break;
                        case "toughness": Int32.TryParse(node.InnerText, out _toughness); break;
                        case "combat":
                            for (int j = 0; j < node.ChildNodes.Count; ++j)
                            {
                                switch (node.ChildNodes[j].Name.ToLower())
                                {
                                    case "rating": Int32.TryParse(node.ChildNodes[j].InnerText, out _combatRating); break;
                                    case "damage": Int32.TryParse(node.ChildNodes[j].InnerText, out _combatDamage); break;
                                    default: Console.WriteLine("Unknow combat parameter " + node.ChildNodes[j].Name); break;
                                }
                            }
                            break;
                        case "horror":
                            _hasHorrorRating = true;
                            for (int j = 0; j < node.ChildNodes.Count; ++j)
                            {
                                switch(node.ChildNodes[j].Name.ToLower())
                                {
                                    case "rating": Int32.TryParse(node.ChildNodes[j].InnerText, out _horrorRating); break;
                                    case "damage": Int32.TryParse(node.ChildNodes[j].InnerText, out _horrorDamage); break;
                                    default: Console.WriteLine("Unknow horror parameter " + node.ChildNodes[j].Name); break;
                                }
                            }
                            break;
                        case "abilities":
                            for (int a = 0; a < node.ChildNodes.Count; ++a)
                            {
                                string abilityString = node.ChildNodes[a].Name.ToLower();
                                foreach (MonsterAbility ability in Enum.GetValues(typeof(MonsterAbility)))
                                {
                                    if (ability.ToString().ToLower() == abilityString)
                                    {
                                        int value = 0;
                                        Int32.TryParse(node.ChildNodes[a].InnerText, out value);
                                        _abilities.Add(ability, value);
                                        break;
                                    }
                                }
                            }
                            break;
                        case "text":
                            for (int l = 0; l < node.ChildNodes.Count; ++l)
                            {
                                _text.Add(node.ChildNodes[l].Name.ToLower(), node.ChildNodes[l].InnerText);
                            }
                            break;
                        default: Console.WriteLine("Unknown parameter " + node.Name); break;
                    }
                }
            }
        }
    }
}
