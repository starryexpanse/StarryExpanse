For safety, this file contains check() calls after every nullable result. You can replace this
with your own non-fatal check if you like.

# Getting controller

```
auto controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
check(controller);
```

# Getting HUD

```
auto hud = Cast<AStarryExpanseHUD>(controller->GetHUD());
check(hud);
```

# Getting GameState

```
auto gs = Cast<ARivenGameState>(GetWorld()->GetGameState());
check(gs);
```

# Getting GameMode

```
auto gameMode = GetWorld()->GetAuthGameMode();
```

or


```
auto gameMode = Cast<AStarryExpanseGameMode>(GetWorld()->GetAuthGameMode());
check(gameMode);
```

# Getting GameInstance

```
auto ginst = Cast<URivenGameInstance>(GetWorld()->GetGameInstance());
check(ginst);
```