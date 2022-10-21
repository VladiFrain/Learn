namespace Snake
{
    class Figure
    {
        protected List<Point> pList = new List<Point>();
        public void Draw()
        {
            foreach(var p in pList)
            {
                p.Draw();
            }
        }
        internal bool IsHit(Figure figure)
        {
            foreach(var p in pList)
            {
                if(figure.IsHit(p))
                {
                    return true;
                }
            }
            return false;
        }
        private bool IsHit(Point point)
        {
            foreach(var p in pList)
            {
                if(p.IsHit(point))
                {
                    return true;
                }
            }
            return false;
        }
    }
}