namespace Snake
{
    class Walls
    {
        private List<Figure> wallList = new List<Figure>();
        public Walls(int mapWidth, int mapHeight)
        {
            HorizontalLine topLine = new HorizontalLine(xLeft: 0, xRight: mapWidth, y: 0, sym: '+');
            HorizontalLine bottomLine = new HorizontalLine(xLeft: 0, xRight: mapWidth, y: mapHeight, sym: '+');
            VerticalLine leftLine = new VerticalLine(yTop: 0, yBottom: mapHeight, x: 0, sym: '+');
            VerticalLine rightLine = new VerticalLine(yTop: 0, yBottom: mapHeight, x: mapWidth, sym: '+');
            wallList.Add(topLine);
            wallList.Add(bottomLine);
            wallList.Add(leftLine);
            wallList.Add(rightLine);
        }
        public bool IsHit(Figure figure)
        {
            foreach(var wall in wallList)
            {
                if(wall.IsHit(figure))
                {
                    return true;
                }
            }
            return false;
        }
        public void Draw()
        {
            foreach(var wall in wallList)
            {
                wall.Draw();
            }
        }
    }
}