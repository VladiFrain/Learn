class ComputerClub
{
    private int _money = 0;
    private List<Computer> _computers = new List<Computer>();
    private Queue<Client> _clients = new Queue<Client>();

    public ComputerClub(int computersCount)
    {
        Random rand = new Random();

        for (int i = 0; i < computersCount; i++)
        {
            _computers.Add(new Computer(rand.Next(5, 15)));
        }

        CreateNewClients(25, rand);
    }

    public void CreateNewClients(int count, Random rand)
    {
        for (int i = 0; i < count; i++)
        {
            _clients.Enqueue(new Client(rand.Next(100, 251), rand));
        }
    }

    public void Work()
    {
        while (_clients.Count > 0)
        {
            Client newClient = _clients.Dequeue();
            Console.WriteLine($"Баланс клуба {_money} руб. Ждём нового клиента.");
            Console.WriteLine($"У вас новый клиент, и он хочет купить {newClient.DesiredMinutes} минут.");
            ShowAllComputersState();

            Console.Write("\nВы предлагаете ему компьютер под номером: ");
            string userInput = Console.ReadLine();
            if (int.TryParse(userInput, out int computerNumber))
            {
                computerNumber -= 1;

                if (computerNumber >= 0 && computerNumber < _computers.Count)
                {
                    if (_computers[computerNumber].IsTaken)
                    {
                        Console.WriteLine("Вы пытаетесь посадить клиента, за компьютер, который занят. Он разозлился и ушёл.");
                    }
                    else
                    {
                        if (newClient.CheckSolvency(_computers[computerNumber]))
                        {
                            Console.WriteLine($"Клиент пересчитал деньги, оплатил и сел за компьютер {computerNumber + 1}");
                            _money += newClient.Pay();
                            _computers[computerNumber].BecomeTaken(newClient);
                        }
                        else
                        {
                            Console.WriteLine("У клиента не хватило денег и он ушёл.");
                        }
                    }
                }
                else
                {
                    Console.WriteLine("Вы сами не знаете за какой компьютер посадить клиента. Он разозлился и ушёл.");
                }
            }
            else
            {
                CreateNewClients(1, new Random());
                Console.WriteLine("Неверный ввод! Повторите снова.");
            }

            Console.WriteLine("Чтобы перейти к следующему клиенту нажмите любую клавишу.");
            Console.ReadKey();
            Console.Clear();
            SpendOneMinute();
        }
    }

    public void ShowAllComputersState()
    {
        Console.WriteLine("\nСписок всех компьютеров:");
        for (int i = 0; i < _computers.Count; i++)
        {
            Console.Write(i + 1 + " - ");
            _computers[i].ShowState();
        }
    }

    private void SpendOneMinute()
    {
        foreach (var computer in _computers)
        {
            computer.SpendOneMinte();
        }
    }
}