namespace Snake
{
    class FoodCreator
    {
        int mapWidth;
        int mapHeight;
        char sym;
        Random random = new Random();
        public FoodCreator(int mapWidth, int mapHeight, char sym)
        {
            this.mapHeight = mapHeight;
            this.mapWidth = mapWidth;
            this.sym = sym;

        }
        public Point CreateFood()
        {
            int x = random.Next(2, mapWidth - 2);
            int y = random.Next(2, mapHeight - 2);
            return new Point(x,y,sym);
        }
    }
}