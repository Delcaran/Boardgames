using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ArkhamHorrorCore.Tests
{
    [TestClass()]
    public class MonsterTests
    {
        [TestMethod()]
        [DeploymentItem("Resources\\")]
        public void MonsterLoad()
        {
            Monster monster = null;
            string desc = "";

            desc = "Cultist";
            monster = new Monster("Cultist.xml");
            Assert.AreEqual("Cultist", monster.Name["eng"], true, desc + ": wrong name");
            Assert.AreEqual(6, monster.Available, desc + ": wrong available number");
            Assert.AreEqual(Movement.Normal, monster.Movement, desc + ": wrong movement");
            Assert.AreEqual(Dimension.Moon, monster.Dimension, desc + ": wrong dimension");
            Assert.AreEqual(-3, monster.Awareness, desc + ": wrong awareness");
            Assert.AreEqual(1, monster.Toughness, desc + ": wrong toughness");
            Assert.AreEqual(1, monster.CombatRating, desc + ": wrong combat rating");
            Assert.AreEqual(1, monster.CombatDamage, desc + ": wrong combat damage");

            desc = "GodBloodyTongue";
            monster = new Monster("God of the Bloody Tongue.xml");
            Assert.AreEqual("God of the Bloody Tongue", monster.Name["eng"], true, desc + ": wrong name");
            Assert.AreEqual(Movement.Normal, monster.Movement, desc + ": wrong movement");
            Assert.AreEqual(Dimension.Triangle, monster.Dimension, desc + ": wrong dimension");
            Assert.AreEqual(3, monster.HorrorDamage, desc + ": wrong horror damage");
            Assert.AreEqual(-3, monster.HorrorRating, desc + ": wrong horror rating");
            Assert.AreEqual(true, monster.Abilities.ContainsKey(MonsterAbility.Endless), desc + ": has no Endless ability");
            Assert.AreEqual(0, monster.Abilities[MonsterAbility.Endless], desc + ": Endless has value");
            Assert.AreEqual(true, monster.Abilities.ContainsKey(MonsterAbility.Overwhelming), desc + ": has no Overwhelming ability");
            Assert.AreEqual(1, monster.Abilities[MonsterAbility.Overwhelming], desc + ": wrong Overwhelming value");
        }
    }
}