namespace Snake
{
    class Point
    {
        public Point(int x, int y, char sym)
        {
            this.x = x;
            this.y = y;
            this.sym = sym;
        }
        public Point(Point p)
        {
            this.x = p.x;
            this.y = p.y;
            this.sym = p.sym;
        }
        public int X
        {
            get { return x; }
        }
        public int Y
        {
            get { return y; }
        }
        public char SYM
        {
            get { return sym; }
        }
        public void Draw()
        {
            Console.SetCursorPosition(x, y);
            Console.Write(sym);
        }
        public void Move(int offset, Direction direction)
        {
            if (direction == Direction.RIGHT)
            {
                x += offset;
            }
            else if (direction == Direction.LEFT)
            {
                x -= offset;                
            }
            else if (direction == Direction.UP)
            {
                y -= offset;                
            }
            else if (direction == Direction.DOWN)
            {
                y += offset;                
            }
        }
        public override string ToString()
        {
            return x + ", " + y + ", " + sym;
        }
        private int x;
        private int y;
        private char sym;
    }
}