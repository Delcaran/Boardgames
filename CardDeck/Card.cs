using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CardDeck
{
    public abstract class Card
    {
        private int _rank; // positional value of the card: eg in Briscola, 3 is lower than Ace and higher than King
        private int _value; // points: eg in Briscola 3 is worth 10 points
        private readonly Suit _suit; // hearts, tiles, clovers, pikes / cups, coins, clubs, swords
        private readonly string _name;

        public Card(string name, Suit suit, int value = 0, int rank = 0)
        {
            _name = name;
            _suit = suit;
            _value = value;
            _rank = rank;
        }

        public Suit Suit
        {
            get
            {
                return _suit;
            }
        }

        public int Value
        {
            get
            {
                return _value;
            }

            set
            {
                this._value = value;
            }
        }

        public int Rank
        {
            get
            {
                return _rank;
            }

            set
            {
                _rank = value;
            }
        }

        public string Name
        {
            get
            {
                return _name;
            }
        }
    }
}
