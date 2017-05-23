using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Input;

namespace GameOfLife
{
    class GroupOfCells : Cell
    {
        public GroupOfCells(Point position) : base(position)
        {
        }
        public void JustPoint(MouseState mouseState)
        {
            if (mouseState.LeftButton == ButtonState.Pressed || mouseState.RightButton == ButtonState.Pressed)
            {
                Point Point1 = new Point(mouseState.X, mouseState.Y);
                if (Bounds.Contains(Point1))

                {
                    // Make cells come alive with left-click, or kill them with right-click.
                    if (mouseState.LeftButton == ButtonState.Pressed)
                    {
                        IsAlive = true;
                        Game1.Paused = true;
                    }
                    else if (mouseState.RightButton == ButtonState.Pressed)
                        IsAlive = false;

                }
            }
        }
        
        public void HeavyweightSpaceship(MouseState mouseState)
        {
            if (mouseState.LeftButton == ButtonState.Pressed || mouseState.RightButton == ButtonState.Pressed)
            {
                Point Point1 = new Point(mouseState.X, mouseState.Y + 2 * Game1.CellSize);
                Point Point2 = new Point(mouseState.X, mouseState.Y - 2 * Game1.CellSize);
                Point Point3 = new Point(mouseState.X + Game1.CellSize, mouseState.Y - 2 * Game1.CellSize);
                Point Point4 = new Point(mouseState.X + Game1.CellSize, mouseState.Y + 2 * Game1.CellSize);
                Point Point5 = new Point(mouseState.X + 2 * Game1.CellSize, mouseState.Y + 2 * Game1.CellSize);
                Point Point6 = new Point(mouseState.X + 3 * Game1.CellSize, mouseState.Y + Game1.CellSize);
                Point Point7 = new Point(mouseState.X + 3 * Game1.CellSize, mouseState.Y - Game1.CellSize);
                Point Point8 = new Point(mouseState.X + 3 * Game1.CellSize, mouseState.Y - Game1.CellSize);
                Point Point9 = new Point(mouseState.X - Game1.CellSize, mouseState.Y + 2 * Game1.CellSize);
                Point Point10 = new Point(mouseState.X - 3 * Game1.CellSize, mouseState.Y + 2 * Game1.CellSize);
                Point Point11 = new Point(mouseState.X - 3 * Game1.CellSize, mouseState.Y + Game1.CellSize);
                Point Point12 = new Point(mouseState.X - 3 * Game1.CellSize, mouseState.Y + Game1.CellSize);
                Point Point13 = new Point(mouseState.X - 3 * Game1.CellSize, mouseState.Y + Game1.CellSize);
                Point Point14 = new Point(mouseState.X - 2 * Game1.CellSize, mouseState.Y + 2 * Game1.CellSize);
                Point Point15 = new Point(mouseState.X - 3 * Game1.CellSize, mouseState.Y);
                Point Point16 = new Point(mouseState.X - 2 * Game1.CellSize, mouseState.Y - Game1.CellSize);


                if (Bounds.Contains(Point1)
                    || Bounds.Contains(Point2)
                    || Bounds.Contains(Point3)
                    || Bounds.Contains(Point4)
                    || Bounds.Contains(Point5)
                    || Bounds.Contains(Point6)
                    || Bounds.Contains(Point7)
                    || Bounds.Contains(Point8)
                    || Bounds.Contains(Point9)
                    || Bounds.Contains(Point10)
                    || Bounds.Contains(Point11)
                    || Bounds.Contains(Point12)
                    || Bounds.Contains(Point13)
                    || Bounds.Contains(Point14)
                    || Bounds.Contains(Point15)
                    || Bounds.Contains(Point16))

                {
                    // Make cells come alive with left-click, or kill them with right-click.
                    if (mouseState.LeftButton == ButtonState.Pressed)
                    {
                        IsAlive = true;
                        Game1.Paused = true;
                    }
                    else if (mouseState.RightButton == ButtonState.Pressed)
                        IsAlive = false;

                }
            }           
        }


        public void BlinkerPuffer(MouseState mouseState)
        {
            if (mouseState.LeftButton == ButtonState.Pressed || mouseState.RightButton == ButtonState.Pressed)
            {
                Point Point1 = new Point(mouseState.X, mouseState.Y);
                Point Point2 = new Point(mouseState.X + Game1.CellSize, mouseState.Y);
                Point Point3 = new Point(mouseState.X - Game1.CellSize, mouseState.Y);
                Point Point4 = new Point(mouseState.X - 3 * Game1.CellSize, mouseState.Y);
                Point Point5 = new Point(mouseState.X - 4 * Game1.CellSize, mouseState.Y);
                Point Point6 = new Point(mouseState.X - 2 * Game1.CellSize, mouseState.Y - Game1.CellSize);
                Point Point7 = new Point(mouseState.X - 3 * Game1.CellSize, mouseState.Y - Game1.CellSize);
                Point Point8 = new Point(mouseState.X, mouseState.Y + Game1.CellSize);
                Point Point9 = new Point(mouseState.X - Game1.CellSize, mouseState.Y + Game1.CellSize);
                Point Point10 = new Point(mouseState.X - 2 * Game1.CellSize, mouseState.Y + Game1.CellSize);
                Point Point11 = new Point(mouseState.X - 3 * Game1.CellSize, mouseState.Y + Game1.CellSize);
                Point Point12 = new Point(mouseState.X - Game1.CellSize, mouseState.Y + 2 * Game1.CellSize);
                Point Point13 = new Point(mouseState.X - 2 * Game1.CellSize, mouseState.Y + 2 * Game1.CellSize);
                Point Point14 = new Point(mouseState.X, mouseState.Y - 5 * Game1.CellSize);
                Point Point15 = new Point(mouseState.X - Game1.CellSize, mouseState.Y - 5 * Game1.CellSize);
                Point Point16 = new Point(mouseState.X - 2 * Game1.CellSize, mouseState.Y - 5 * Game1.CellSize);
                Point Point17 = new Point(mouseState.X - 3 * Game1.CellSize, mouseState.Y - 5 * Game1.CellSize);
                Point Point18 = new Point(mouseState.X - 4 * Game1.CellSize, mouseState.Y - 5 * Game1.CellSize);
                Point Point19 = new Point(mouseState.X - 4 * Game1.CellSize, mouseState.Y - 6 * Game1.CellSize);
                Point Point20 = new Point(mouseState.X - 4 * Game1.CellSize, mouseState.Y - 7 * Game1.CellSize);
                Point Point21 = new Point(mouseState.X - 3 * Game1.CellSize, mouseState.Y - 8 * Game1.CellSize);
                Point Point22 = new Point(mouseState.X - Game1.CellSize, mouseState.Y - 9 * Game1.CellSize);
                Point Point23 = new Point(mouseState.X + Game1.CellSize, mouseState.Y - 8 * Game1.CellSize);
                Point Point24 = new Point(mouseState.X + Game1.CellSize, mouseState.Y - 6 * Game1.CellSize);
                Point Point25 = new Point(mouseState.X + Game1.CellSize, mouseState.Y + 4 * Game1.CellSize);
                Point Point26 = new Point(mouseState.X + 2 * Game1.CellSize, mouseState.Y + 4 * Game1.CellSize);
                Point Point27 = new Point(mouseState.X - Game1.CellSize, mouseState.Y + 5 * Game1.CellSize);
                Point Point28 = new Point(mouseState.X + 4 * Game1.CellSize, mouseState.Y + 5 * Game1.CellSize);
                Point Point29 = new Point(mouseState.X - 2 * Game1.CellSize, mouseState.Y + 6 * Game1.CellSize);
                Point Point30 = new Point(mouseState.X - 2 * Game1.CellSize, mouseState.Y + 7 * Game1.CellSize);
                Point Point31 = new Point(mouseState.X - 2 * Game1.CellSize, mouseState.Y + 8 * Game1.CellSize);
                Point Point32 = new Point(mouseState.X - Game1.CellSize, mouseState.Y + 8 * Game1.CellSize);
                Point Point33 = new Point(mouseState.X, mouseState.Y + 8 * Game1.CellSize);
                Point Point34 = new Point(mouseState.X + 1 * Game1.CellSize, mouseState.Y + 8 * Game1.CellSize);
                Point Point35 = new Point(mouseState.X + 2 * Game1.CellSize, mouseState.Y + 8 * Game1.CellSize);
                Point Point36 = new Point(mouseState.X + 3 * Game1.CellSize, mouseState.Y + 8 * Game1.CellSize);
                Point Point37 = new Point(mouseState.X + 4 * Game1.CellSize, mouseState.Y + 7 * Game1.CellSize);
    
                if (Bounds.Contains(Point1) || Bounds.Contains(Point2)
                    || Bounds.Contains(Point3) || Bounds.Contains(Point4)
                    || Bounds.Contains(Point5) || Bounds.Contains(Point6)
                    || Bounds.Contains(Point7) || Bounds.Contains(Point8)
                    || Bounds.Contains(Point9) || Bounds.Contains(Point10)
                    || Bounds.Contains(Point11) || Bounds.Contains(Point12)
                    || Bounds.Contains(Point13) || Bounds.Contains(Point14)
                    || Bounds.Contains(Point15) || Bounds.Contains(Point16)
                    || Bounds.Contains(Point17) || Bounds.Contains(Point18)
                    || Bounds.Contains(Point19) || Bounds.Contains(Point20)
                    || Bounds.Contains(Point21) || Bounds.Contains(Point22)
                    || Bounds.Contains(Point23) || Bounds.Contains(Point24)
                    || Bounds.Contains(Point25) || Bounds.Contains(Point26)
                    || Bounds.Contains(Point27) || Bounds.Contains(Point28)
                    || Bounds.Contains(Point29) || Bounds.Contains(Point30)
                    || Bounds.Contains(Point31) || Bounds.Contains(Point32)
                    || Bounds.Contains(Point33) || Bounds.Contains(Point34)
                    || Bounds.Contains(Point35) || Bounds.Contains(Point36)
                    || Bounds.Contains(Point37))

                {
                    // Make cells come alive with left-click, or kill them with right-click.
                    if (mouseState.LeftButton == ButtonState.Pressed)
                    {
                        IsAlive = true;
                        Game1.Paused = true;
                    }
                    else if (mouseState.RightButton == ButtonState.Pressed)
                        IsAlive = false;

                }
            }
        }

        public void CoeShip(MouseState mouseState)
        {
            if (mouseState.LeftButton == ButtonState.Pressed || mouseState.RightButton == ButtonState.Pressed)
            {
                Point Point1 = new Point(mouseState.X, mouseState.Y);
                Point Point2 = new Point(mouseState.X + 2 * Game1.CellSize, mouseState.Y - Game1.CellSize);
                Point Point3 = new Point(mouseState.X - 2 * Game1.CellSize, mouseState.Y - Game1.CellSize);
                Point Point4 = new Point(mouseState.X + 3 * Game1.CellSize, mouseState.Y - 2 * Game1.CellSize);
                Point Point5 = new Point(mouseState.X - 3 * Game1.CellSize, mouseState.Y - 2 * Game1.CellSize);
                Point Point6 = new Point(mouseState.X - 5 * Game1.CellSize, mouseState.Y - 2 * Game1.CellSize);
                Point Point7 = new Point(mouseState.X - 6 * Game1.CellSize, mouseState.Y - 2 * Game1.CellSize);
                Point Point8 = new Point(mouseState.X + 3 * Game1.CellSize, mouseState.Y - 3 * Game1.CellSize);
                Point Point9 = new Point(mouseState.X - 3 * Game1.CellSize, mouseState.Y - 3 * Game1.CellSize);
                Point Point10 = new Point(mouseState.X - 4 * Game1.CellSize, mouseState.Y - 3 * Game1.CellSize);
                Point Point11 = new Point(mouseState.X + 3 * Game1.CellSize, mouseState.Y - 4 * Game1.CellSize);
                Point Point12 = new Point(mouseState.X + 2 * Game1.CellSize, mouseState.Y - 4 * Game1.CellSize);
                Point Point13 = new Point(mouseState.X + 1 * Game1.CellSize, mouseState.Y - 4 * Game1.CellSize);
                Point Point14 = new Point(mouseState.X, mouseState.Y - 4 * Game1.CellSize);
                Point Point15 = new Point(mouseState.X - 1 * Game1.CellSize, mouseState.Y - 4 * Game1.CellSize);
                Point Point16 = new Point(mouseState.X - 2 * Game1.CellSize, mouseState.Y - 4 * Game1.CellSize);
                Point Point17 = new Point(mouseState.X, mouseState.Y + Game1.CellSize);
                Point Point18 = new Point(mouseState.X + Game1.CellSize, mouseState.Y + Game1.CellSize);
                Point Point19 = new Point(mouseState.X, mouseState.Y + 2 * Game1.CellSize);
                Point Point20 = new Point(mouseState.X + Game1.CellSize, mouseState.Y + 2 * Game1.CellSize);
                Point Point21 = new Point(mouseState.X - Game1.CellSize, mouseState.Y + 2 * Game1.CellSize);
                Point Point22 = new Point(mouseState.X + 2 * Game1.CellSize, mouseState.Y + 2 * Game1.CellSize);
                Point Point23 = new Point(mouseState.X, mouseState.Y + 3 * Game1.CellSize);
                Point Point24 = new Point(mouseState.X - Game1.CellSize, mouseState.Y + 3 * Game1.CellSize);
                Point Point25 = new Point(mouseState.X + 2 * Game1.CellSize, mouseState.Y + 3 * Game1.CellSize);
                Point Point26 = new Point(mouseState.X + 3 * Game1.CellSize, mouseState.Y + 3 * Game1.CellSize);
                Point Point27 = new Point(mouseState.X + 2 * Game1.CellSize, mouseState.Y + 4 * Game1.CellSize);
                Point Point28 = new Point(mouseState.X + Game1.CellSize, mouseState.Y + 4 * Game1.CellSize);
               
                if (Bounds.Contains(Point1) || Bounds.Contains(Point2)
                    || Bounds.Contains(Point3) || Bounds.Contains(Point4)
                    || Bounds.Contains(Point5) || Bounds.Contains(Point6)
                    || Bounds.Contains(Point7) || Bounds.Contains(Point8)
                    || Bounds.Contains(Point9) || Bounds.Contains(Point10)
                    || Bounds.Contains(Point11) || Bounds.Contains(Point12)
                    || Bounds.Contains(Point13) || Bounds.Contains(Point14)
                    || Bounds.Contains(Point15) || Bounds.Contains(Point16)
                    || Bounds.Contains(Point17) || Bounds.Contains(Point18)
                    || Bounds.Contains(Point19) || Bounds.Contains(Point20)
                    || Bounds.Contains(Point21) || Bounds.Contains(Point22)
                    || Bounds.Contains(Point23) || Bounds.Contains(Point24)
                    || Bounds.Contains(Point25) || Bounds.Contains(Point26)
                    || Bounds.Contains(Point27) || Bounds.Contains(Point28))

                {
                    // Make cells come alive with left-click, or kill them with right-click.
                    if (mouseState.LeftButton == ButtonState.Pressed)
                    {
                        IsAlive = true;
                        Game1.Paused = true;
                    }
                    else if (mouseState.RightButton == ButtonState.Pressed)
                        IsAlive = false;

                }
            }
        }

        public void Washerwoman(MouseState mouseState)
        {
            if (mouseState.LeftButton == ButtonState.Pressed || mouseState.RightButton == ButtonState.Pressed)
            {
                Point Point1 = new Point(mouseState.X, mouseState.Y);
                Point Point2 = new Point(mouseState.X - Game1.CellSize, mouseState.Y - Game1.CellSize);
                Point Point3 = new Point(mouseState.X - Game1.CellSize, mouseState.Y + Game1.CellSize);
                Point Point4 = new Point(mouseState.X - 2 * Game1.CellSize, mouseState.Y);
                Point Point5 = new Point(mouseState.X - 6 * Game1.CellSize, mouseState.Y);
                Point Point6 = new Point(mouseState.X - 7 * Game1.CellSize, mouseState.Y - Game1.CellSize);
                Point Point7 = new Point(mouseState.X - 7 * Game1.CellSize, mouseState.Y + Game1.CellSize);
                Point Point8 = new Point(mouseState.X - 8 * Game1.CellSize, mouseState.Y);
                Point Point9 = new Point(mouseState.X - 12 * Game1.CellSize, mouseState.Y);
                Point Point10 = new Point(mouseState.X - 13 * Game1.CellSize, mouseState.Y - Game1.CellSize);
                Point Point11 = new Point(mouseState.X - 13 * Game1.CellSize, mouseState.Y + Game1.CellSize);
                Point Point12 = new Point(mouseState.X - 14 * Game1.CellSize, mouseState.Y);
                Point Point13 = new Point(mouseState.X - 18 * Game1.CellSize, mouseState.Y);
                Point Point14 = new Point(mouseState.X - 19 * Game1.CellSize, mouseState.Y - Game1.CellSize);
                Point Point15 = new Point(mouseState.X - 19 * Game1.CellSize, mouseState.Y + Game1.CellSize);
                Point Point16 = new Point(mouseState.X - 20 * Game1.CellSize, mouseState.Y);
                Point Point17 = new Point(mouseState.X - 23 * Game1.CellSize, mouseState.Y);
                Point Point18 = new Point(mouseState.X - 24 * Game1.CellSize, mouseState.Y);
                Point Point19 = new Point(mouseState.X - 24 * Game1.CellSize, mouseState.Y + Game1.CellSize);
                Point Point20 = new Point(mouseState.X - 24 * Game1.CellSize, mouseState.Y - Game1.CellSize);
                Point Point21 = new Point(mouseState.X - 25 * Game1.CellSize, mouseState.Y);
                Point Point22 = new Point(mouseState.X - 25 * Game1.CellSize, mouseState.Y + Game1.CellSize);
                Point Point23 = new Point(mouseState.X - 25 * Game1.CellSize, mouseState.Y - Game1.CellSize);
                Point Point24 = new Point(mouseState.X - 25 * Game1.CellSize, mouseState.Y + 2 * Game1.CellSize);
                Point Point25 = new Point(mouseState.X - 25 * Game1.CellSize, mouseState.Y - 2 * Game1.CellSize);
                Point Point26 = new Point(mouseState.X + 4 * Game1.CellSize, mouseState.Y);
                Point Point27 = new Point(mouseState.X + 5 * Game1.CellSize, mouseState.Y - Game1.CellSize);
                Point Point28 = new Point(mouseState.X + 5 * Game1.CellSize, mouseState.Y + Game1.CellSize);
                Point Point29 = new Point(mouseState.X + 6 * Game1.CellSize, mouseState.Y);
                Point Point30 = new Point(mouseState.X + 10 * Game1.CellSize, mouseState.Y);
                Point Point31 = new Point(mouseState.X + 11 * Game1.CellSize, mouseState.Y - Game1.CellSize);
                Point Point32 = new Point(mouseState.X + 11 * Game1.CellSize, mouseState.Y + Game1.CellSize);
                Point Point33 = new Point(mouseState.X + 12 * Game1.CellSize, mouseState.Y);
                Point Point34 = new Point(mouseState.X + 16 * Game1.CellSize, mouseState.Y);
                Point Point35 = new Point(mouseState.X + 17 * Game1.CellSize, mouseState.Y - Game1.CellSize);
                Point Point36 = new Point(mouseState.X + 17 * Game1.CellSize, mouseState.Y + Game1.CellSize);
                Point Point37 = new Point(mouseState.X + 18 * Game1.CellSize, mouseState.Y);
                Point Point38 = new Point(mouseState.X + 22 * Game1.CellSize, mouseState.Y);
                Point Point39 = new Point(mouseState.X + 23 * Game1.CellSize, mouseState.Y - Game1.CellSize);
                Point Point40 = new Point(mouseState.X + 23 * Game1.CellSize, mouseState.Y + Game1.CellSize);
                Point Point41 = new Point(mouseState.X + 24 * Game1.CellSize, mouseState.Y);
                Point Point42 = new Point(mouseState.X + 28 * Game1.CellSize, mouseState.Y);
                Point Point43 = new Point(mouseState.X + 29 * Game1.CellSize, mouseState.Y - Game1.CellSize);
                Point Point44 = new Point(mouseState.X + 29 * Game1.CellSize, mouseState.Y + Game1.CellSize);
                Point Point45 = new Point(mouseState.X + 30 * Game1.CellSize, mouseState.Y);

                if (Bounds.Contains(Point1) || Bounds.Contains(Point2)
                    || Bounds.Contains(Point3) || Bounds.Contains(Point4)
                    || Bounds.Contains(Point5) || Bounds.Contains(Point6)
                    || Bounds.Contains(Point7) || Bounds.Contains(Point8)
                    || Bounds.Contains(Point9) || Bounds.Contains(Point10)
                    || Bounds.Contains(Point11) || Bounds.Contains(Point12)
                    || Bounds.Contains(Point13) || Bounds.Contains(Point14)
                    || Bounds.Contains(Point15) || Bounds.Contains(Point16)
                    || Bounds.Contains(Point17) || Bounds.Contains(Point18)
                    || Bounds.Contains(Point19) || Bounds.Contains(Point20)
                    || Bounds.Contains(Point21) || Bounds.Contains(Point22)
                    || Bounds.Contains(Point23) || Bounds.Contains(Point24)
                    || Bounds.Contains(Point25) || Bounds.Contains(Point26)
                    || Bounds.Contains(Point27) || Bounds.Contains(Point28)
                    || Bounds.Contains(Point29) || Bounds.Contains(Point30)
                    || Bounds.Contains(Point31) || Bounds.Contains(Point32)
                    || Bounds.Contains(Point33) || Bounds.Contains(Point34)
                    || Bounds.Contains(Point35) || Bounds.Contains(Point36)
                    || Bounds.Contains(Point37) || Bounds.Contains(Point38)
                    || Bounds.Contains(Point39) || Bounds.Contains(Point40)
                    || Bounds.Contains(Point41) || Bounds.Contains(Point42)
                    || Bounds.Contains(Point43) || Bounds.Contains(Point44)
                    || Bounds.Contains(Point45)
                    )

                {
                    // Make cells come alive with left-click, or kill them with right-click.
                    if (mouseState.LeftButton == ButtonState.Pressed)
                    {
                        IsAlive = true;
                        Game1.Paused = true;
                    }
                    else if (mouseState.RightButton == ButtonState.Pressed)
                        IsAlive = false;

                }
            }
        }
    }
    
}

