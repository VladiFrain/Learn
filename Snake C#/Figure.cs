namespace Snake
{
    class Figure
    {
        protected List<Point> pList = new List<Point>();
        public void Drow()
        {
            foreach(var p in pList)
            {
                p.Draw();
            }
        }
    }
}