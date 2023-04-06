class Computer
{
    private Client _client;
    private int _minutesRemaining;

    public bool IsTaken
    {
        get
        {
            return _minutesRemaining > 0;
        }
    }

    public int PricePerMinute { get; private set; }

    public Computer(int pricePerMinute)
    {
        PricePerMinute = pricePerMinute;
    }

    public void BecomeTaken(Client client)
    {
        _client = client;
        _minutesRemaining = client.DesiredMinutes;
    }

    public void BecomeEmpty()
    {
        _client = null;
    }

    public void SpendOneMinte()
    {
        _minutesRemaining--;
    }

    public void ShowState()
    {
        if (IsTaken)
        {
            Console.WriteLine($"Компьютер занят, осталось минут: {_minutesRemaining}");
        }
        else
        {
            Console.WriteLine($"Компьютер свободен, цена за минуту: {PricePerMinute}");
        }
    }
}