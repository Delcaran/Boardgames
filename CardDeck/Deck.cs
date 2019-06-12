using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CardDeck
{
    public abstract class Deck
    {
        private SortedList<int, Card> _cards;

        public Deck()
        {
        }

        // shuffle with Durstenfeld's algorithm
        public void Shuffle()
        {
            Random random = new Random();
            for(int i = 0; i < _cards.Count - 1; ++i)
            {
                int r = random.Next(i, _cards.Count);
                Card temp = _cards[r];
                _cards[r] = _cards[i];
                _cards[i] = temp;
            }
        }

        public SortedList<int, Card> Draw(int num)
        {
            SortedList<int, Card> cards = new SortedList<int, Card>();
            for(int i = 0; i < Math.Min(num, _cards.Count); ++i)
            {
                cards.Add(i, _cards[i]);
                _cards.Remove(i);
            }
            return cards;
        }
    }
}
