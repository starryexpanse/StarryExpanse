import cog

def p(x):
    # Easy hack to make the line endings consistently DOS-style
    cog.outl(x)

vars = [

    # This intends to be a list of every "world state" variable in the game. It should ideally contain
    # the exact amount of information needed to restore the game from a save, no more and no less.
    # 
    # Data duplication is generally bad here. We want there to be as few variables as possible
    # to avoid the accidental achievement of an impossible state. For instance, instead of having both
    # a PagesAreRippedOut variable and a CatherineIsFree variable, let's just have a CatherineIsFree
    # variable, so we don't have to worry about whether two pieces of data that should always match, match.
    #
    # Each of these tuples is of the form (type, name, defaultValue). The first entry is the C++ type,
    # the second entry is the name of the variable (must have no spaces), and the third entry is
    # the default value it should take on. These default values are assigned during the "Restore
    # New Game Defaults" function.

    ##################################################################
    # Shared (In the loosest sense of the word)
    ##################################################################

    ['ELoadGroups', 'CurrentLoadGroup', 'ELoadGroups::TFissureDistrict'],
    ['EMarionettist', 'CurrentMarionettist', 'EMarionettist::NoMarionettist'],

    ['bool', 'CurrentZoomedLinkingBookIsOpen', 'false'],
    ['bool', 'GehnIsTrapped', 'false'],
    ['bool', 'HaveTrapBook', 'true'],                       # True because you have it before Cho shoots you and takes it
    ['bool', 'CatherineIsFree', 'false'],

    ['FTransform', 'CharacterTransform', 'FTransform::Identity'],

      # Randomly generated at startup
      # Valid Values: 0-4
        ['int32', 'TelescopeCodeA', '-1'],
        ['int32', 'TelescopeCodeB', '-1'],
        ['int32', 'TelescopeCodeC', '-1'],
        ['int32', 'TelescopeCodeD', '-1'],
        ['int32', 'TelescopeCodeE', '-1'],

      # Randomly generated upon Gehn being trapped
      # Valid Values: 0-2
        ['int32', 'PrisonCodeA', '-1'],
        ['int32', 'PrisonCodeB', '-1'],
        ['int32', 'PrisonCodeC', '-1'],
        ['int32', 'PrisonCodeD', '-1'],
        ['int32', 'PrisonCodeE', '-1'],

      # Randomly generated at startup
      # Valid Values: 0-24
        ['int32', 'DomeCodeA', '-1'],
        ['int32', 'DomeCodeB', '-1'],
        ['int32', 'DomeCodeC', '-1'],
        ['int32', 'DomeCodeD', '-1'],
        ['int32', 'DomeCodeE', '-1'],

    ##################################################################
    # J
    ##################################################################
    ['ESubPosRot', 'SubPosRot', 'ESubPosRot::Plat_N'],
    ['bool', 'J_SeenCreepyGirl', 'false'],
    ['int32', 'J_WahrkElevatorPosition', '0'], # valid : 0, 1, 2

    ##################################################################
    # O
    ##################################################################
    ['bool', 'O_OvenIsOn', 'false'],
    ['bool', 'O_CageIsUp', 'true'],
    ['int32', 'O_TimesGehnSignaled', '0'],

    ##################################################################
    # T
    ##################################################################
    ['bool', 'T_NewTemple_DoorMain_Open', 'false'],
    ['bool', 'T_NewTemple_DoorSide_Open', 'false'],
    ['bool', 'T_FissurePlateau_CageLever_Closed', 'true'],
    ['bool', 'T_FissurePlateau_ChoStillPassedOut', 'true'],

    ##################################################################
    # S
    ##################################################################
    ['bool', 'S_SeenScribe', 'false'],

    ##################################################################
    # B
    ##################################################################
    ['bool', 'B_GehnHasVisited', 'false'],
]