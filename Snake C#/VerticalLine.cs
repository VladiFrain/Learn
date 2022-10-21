namespace Snake
{
    class VerticalLine : Figure
    {
        public VerticalLine(int yTop, int yBottom, int x, char sym)
        {
            for (int y = yTop; y <= yBottom; y++)
            {
                Point p = new Point(x,y,sym);
                pList.Add(p);
            }
        }
    }
}