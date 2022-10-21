namespace Snake
{
    class Snake : Figure
    {
        Direction direction;
        public Snake(Point tail, int length, Direction direction)
        {
            this.direction = direction;
            for (int i = 0; i < length; i++)
            {
                Point p = new Point(tail);
                p.Move(i, this.direction);
                pList.Add(p);
            }
        }
        internal void Move()
        {
            Point tail = pList.First();
            pList.Remove(tail);
            Point head = GetNextPoint();
            pList.Add(head);
            tail.Clear();
            head.Draw();
        }

        public Point GetNextPoint()
        {
            Point head = pList.Last();
            Point nextPoint = new Point(head);
            nextPoint.Move(1,direction);
            return nextPoint;
        }
        public void HadleKey(ConsoleKey key)
        {
            if (key == ConsoleKey.LeftArrow)
            {
                direction = Direction.LEFT;
            }
            else if (key == ConsoleKey.RightArrow)
            {
                direction = Direction.RIGHT;
            }
            else if (key == ConsoleKey.UpArrow)
            {
                direction = Direction.UP;
            }
            else if (key == ConsoleKey.DownArrow)
            {
                direction = Direction.DOWN;
            }
        }
    }
}