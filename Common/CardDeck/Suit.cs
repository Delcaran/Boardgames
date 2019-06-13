using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CardDeck
{
    public class Suit
    {
        private string _name; // eg: hearts or coppe

        public string Name
        {
            get
            {
                return _name;
            }

            set
            {
                _name = value;
            }
        }

        public Suit(string name)
        {
            Name = name;
        }
    }
}
