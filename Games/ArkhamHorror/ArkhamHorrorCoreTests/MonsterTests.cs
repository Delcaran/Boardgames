using Microsoft.VisualStudio.TestTools.UnitTesting;
using ArkhamHorrorCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArkhamHorrorCore.Tests
{
    [TestClass()]
    public class MonsterTests
    {
        [TestMethod()]
        public void MonsterTest()
        {
            Monster cultist = new Monster("A:\\Repo\\Tabletop\\ArkhamHorrorCore\\Resources\\Monsters\\Cultist.xml");
            Assert.AreEqual("Cultist", cultist.Name["eng"], true, "Cultist: wrong name");
            Assert.AreEqual(6, cultist.Available, "Cultist: wrong available number");
            Assert.AreEqual(-3, cultist.Awareness, "Cultist: wrong awareness");
            Assert.AreEqual(1, cultist.Toughness, "Cultist: wrong toughness");
            Assert.AreEqual(1, cultist.CombatRating, "Cultist: wrong combat rating");
            Assert.AreEqual(1, cultist.CombatDamage, "Cultist: wrong combat damage");

            Monster god = new Monster("A:\\Repo\\Tabletop\\ArkhamHorrorCore\\Resources\\Monsters\\God of the Bloody Tongue.xml");
        }
    }
}