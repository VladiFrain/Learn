namespace Snake
{
    class Program
    {
        static void Main(string[] args)
        {
            //Console.SetBufferSize(80,25);

            //Отрисовка рамочки
            Walls walls = new Walls(80,25);
            walls.Draw();            

            //Отрисовка точек
            Point p = new Point(x: 4, y: 5, sym: '*');
            Snake snake = new Snake(p, 4, Direction.RIGHT);
            snake.Draw();

            FoodCreator foodCreator = new FoodCreator(mapWidth: 80, mapHeight: 25, sym: '$');
            Point food = foodCreator.CreateFood();
            food.Draw();

            while(true)
            {
                if(walls.IsHit(snake) || snake.IsHitTail())
                {
                    break;
                }
                if(snake.Eat(food))
                {
                    food = foodCreator.CreateFood();
                    food.Draw();
                }
                else{
                    snake.Move();
                }

                Thread.Sleep(100);

                if(Console.KeyAvailable)
                {
                    ConsoleKeyInfo key = Console.ReadKey();
                    snake.HadleKey(key.Key);
                }
            }      
        }
    }
}