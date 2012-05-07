int CoinValues[] =
  { 5, 10, 20, 50, 100, 200 };

vector<unsigned> Coins;

int TargetValue;

int MemTable[1005];

int
fn(value)
{
  if (value == 0)
  {
    return 0;
  }
  if (value < 0)
  {
    return MAX_VAL;
  }
  if (MemTable[value] == NOT_COMPUTED)
  {
    int minCoins = MAX_VAL;
    FOREACH(i, Coins.size())
    {
      int coins = MinCoinsForValue(value - Coins[i]);
      if (coins < minCoins)
      {
        minCoins = coins;
      }
    }
    MemTable[value] = 1 + minCoins;
  }

  return MemTable[value];
}