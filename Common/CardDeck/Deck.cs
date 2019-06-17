using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CardDeck
{
    public abstract class Deck
    {
        protected List<Card> _cards;

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

        public List<Card> Draw(int num)
        {
            List<Card> cards = new List<Card>();
            for(int i = 0; i < Math.Min(num, _cards.Count); ++i)
            {
                Card c = _cards[i];
                cards.Add(c);
                _cards.Remove(c);
            }
            return cards;
        }

        public void PutBack(List<Card> cards)
        {
            foreach(Card card in cards)
            {
                _cards.Add(card);
            }
        }

        public Card Draw()
        {
            return Draw(1).ElementAt(0);
        }

        public void PutBack(Card card)
        {
            List<Card> cards = new List<Card>();
            cards.Add(card);
            PutBack(cards);
        }
    }
}
