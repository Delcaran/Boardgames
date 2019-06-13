using System;
using System.Collections.Generic;
using Utils;

namespace ArkhamHorrorCore
{
    public enum Statistic
    {
        Speed,
        Sneak,
        Fight,
        Will,
        Lore,
        Luck
    }

    public enum InvestigatorAbility
    {
        AbleSeaman,
        AbnormalFocus,
        Adventurer,
        Archaeology,
        BailOut,
        BeenThroughHell,
        BlessedistheChild,
        BloodIsPower,
        BloodMoney,
        BreakingTheLimits,
        BuryThemDeep,
        CarefulReader,
        CleanTakedown,
        Connections,
        CriminalRecord,
        DarkInsight,
        DeadManStomp,
        ExpenseAccount,
        ExperiencedDreamer,
        FamilyCurse,
        FriendIndeed,
        GuardianAngel,
        GuardianOfTheVeil,
        Heirloom,
        Hero,
        Holdout,
        HometownAdvantage,
        Hunches,
        Improv,
        InTheStars,
        Inspiring,
        Intuitive,
        Investigation,
        IronWill,
        JackOfAllTrades,
        KillerInstincts,
        KnowledgeIsPower,
        Leadership,
        MagicalGift,
        MemoriesOfConquest,
        Minor,
        OddJobs,
        OminousDreams,
        OnTheForce,
        OneManArmy,
        Physician,
        Precognition,
        PsychicSensitivity,
        Psychology,
        QuickWitted,
        Research,
        Resilient,
        SchoolofHardKnocks,
        Science,
        Scrounge,
        SecretRites,
        SecretsOfTheDead,
        SettleDown,
        ShrewdDealer,
        Slippery,
        StrangeLuck,
        Streetwise,
        StrongBody,
        StrongMind,
        Studious,
        Synergy,
        TaintedBlood,
        TeamPlayer,
        ThickSkulled,
        ThirdEye,
        TrustFund,
        TrustedSister,
        YinandYang,
        WitchBlood
  }

    public class Investigator
    {
        // Statistics
        private int _sanity;
        private int _stamina;
        private int _focus;
        private int _focusLeft;
        private int _speedSneakMin;
        private int _speed;
        private int _sneak;
        private int _speedSneakMax;
        private int _fightWillMin;
        private int _fight;
        private int _will;
        private int _fightWillMax;
        private int _loreLuckMin;
        private int _lore;
        private int _luck;
        private int _loreLuckMax;

        // Abilities
        private List<InvestigatorAbility> _abilities;

        // Possessions
        private int _money;
        private int _clues;

        private Location _location;

        private void ChangeStat(Statistic stat, int val)
        {
            int value = Math.Min(val, _focusLeft);
            switch(stat)
            {
                case Statistic.Speed:
                    _speed += value;
                    _sneak -= value;
                    break;
                case Statistic.Sneak:
                    _speed -= value;
                    _sneak += value;
                    break;
                case Statistic.Fight:
                    _fight += value;
                    _will -= value;
                    break;
                case Statistic.Will:
                    _fight -= value;
                    _will += value;
                    break;
                case Statistic.Lore:
                    _lore += value;
                    _luck -= value;
                    break;
                case Statistic.Luck:
                    _lore -= value;
                    _luck += value;
                    break;
            }
            _speed = NumericUtils.Clamp(_speed, _speedSneakMin, _speedSneakMax);
            _sneak = NumericUtils.Clamp(_speed, _speedSneakMin, _speedSneakMax);
            _fight = NumericUtils.Clamp(_speed, _fightWillMin, _fightWillMax);
            _will = NumericUtils.Clamp(_speed, _fightWillMin, _fightWillMax);
            _lore = NumericUtils.Clamp(_speed, _loreLuckMin, _loreLuckMax);
            _luck = NumericUtils.Clamp(_speed, _loreLuckMin, _loreLuckMax);
            _focusLeft -= value;
        }
    }
}
