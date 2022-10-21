namespace Snake
{
    class Program
    {
        static void Main(string[] args)
        {
            //Console.SetBufferSize(80,25);

            //Отрисовка рамочки
            HorizontalLine topLine = new HorizontalLine(xLeft: 0, xRight: 78, y: 0, sym: '+');
            HorizontalLine bottomLine = new HorizontalLine(xLeft: 0, xRight: 78, y: 24, sym: '+');
            VerticalLine leftLine = new VerticalLine(yTop: 0, yBottom: 24, x: 0, sym: '+');
            VerticalLine rightLine = new VerticalLine(yTop: 0, yBottom: 24, x: 78, sym: '+');
            topLine.Draw();
            bottomLine.Draw();
            leftLine.Draw();
            rightLine.Draw();

            //Отрисовка точек
            Point p = new Point(x: 4, y: 5, sym: '*');
            Snake snake = new Snake(p, 4, Direction.RIGHT);
            snake.Draw();

            FoodCreator foodCreator = new FoodCreator(mapWidth: 80, mapHeight: 25, sym: '$');
            Point food = foodCreator.CreateFood();
            food.Draw();

            while(true)
            {
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