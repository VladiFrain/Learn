namespace Snake
{
    class Point
    {
        private int x;
        private int y;
        public char sym;
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
        public void Clear()
        {
            sym = ' ';
            Draw();
        }
        public override string ToString()
        {
            return x + ", " + y + ", " + sym;
        }
        public bool IsHit(Point p)
        {
            return p.x == this.x && p.y == this.y;
        }
    }
}