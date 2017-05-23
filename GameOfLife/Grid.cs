using System;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;


namespace GameOfLife
{
    /// <summary>
    /// This is a game component that implements IUpdateable.
    /// </summary>
    public class Grid : Microsoft.Xna.Framework.DrawableGameComponent
    {
        public Point Size { get; private set; }

        private GroupOfCells[,] _cells;
        private bool[,] _nextCellStates;

        private TimeSpan _updateTimer;
        public static bool JustPoint = true, 
                           HeavyweightSpaceship = false,
                           BlinkerPuffer = false, 
                           CoeShip = false, 
                           Washerwoman = false;

        public Grid(Game game)
            : base(game)
        {

            Size = new Point(Game1.CellsX, Game1.CellsY);

            _cells = new GroupOfCells[Size.X, Size.Y];
            _nextCellStates = new bool[Size.X, Size.Y];
            
            for (var i = 0; i < Size.X; i++)
            {
                for (var j = 0; j < Size.Y; j++)
                {
                    _cells[i, j] = new GroupOfCells(new Point(i, j));
                    _nextCellStates[i, j] = false;
                }
            }

            _updateTimer = TimeSpan.Zero;
            // TODO: Construct any child components here
        }

        /// <summary>
        /// Allows the game component to perform any initialization it needs to before starting
        /// to run.  This is where it can query for any required services and load content.
        /// </summary>

        public void Clear()
        {
            for (var i = 0; i < Size.X; i++)
                for (var j = 0; j < Size.Y; j++)
                    _nextCellStates[i, j] = false;

            SetNextState();
        }

        override public void Update(GameTime gameTime)
        {
            MouseState mouseState = Mouse.GetState();
            int mouseStateX = Mouse.GetState().X;
            int mouseStateY = Mouse.GetState().Y;
            if (JustPoint)
            {
                foreach (GroupOfCells cell in _cells)
                {
                    cell.JustPoint(mouseState);                    
                }
            }
            else if (HeavyweightSpaceship)
            {
                foreach (GroupOfCells cell in _cells)
                {
                    cell.HeavyweightSpaceship(mouseState);
                }
            }
            else if (BlinkerPuffer)
            {
                foreach (GroupOfCells cell in _cells)
                {
                    cell.BlinkerPuffer(mouseState);
                }
            }
            else if (CoeShip)
            {
                foreach (GroupOfCells cell in _cells)
                {
                    cell.CoeShip(mouseState);
                }
            }
            else if (Washerwoman)
            {
                foreach (GroupOfCells cell in _cells)
                {
                    cell.Washerwoman(mouseState);

                }
            }

            if (Game1.Paused)
                return;

            _updateTimer += gameTime.ElapsedGameTime;

            if (_updateTimer.TotalMilliseconds > 1000f / Game1.UPS)
            {                
                _updateTimer = TimeSpan.Zero;

                // Loop through every cell on the grid.
                for (var i = 0; i < Size.X; i++)
                {
                    for (var j = 0; j < Size.Y; j++)
                    {
                        // Check the cell's current state, and count its living neighbors.
                        var living = _cells[i, j].IsAlive;
                        var count = GetLivingNeighbors(i, j);
                        var result = false;

                        if (living && count < 2)
                            result = false;
                        if (living && (count == 2 || count == 3))
                            result = true;
                        if (living && count > 3)
                            result = false;
                        if (!living && count == 3)
                            result = true;

                        _nextCellStates[i, j] = result;
                    }
                }
                SetNextState();
            }
        }


        // Counts how many of the current cell's neighbors are currently alive.
        public int GetLivingNeighbors(int x, int y)
        {
            int count = 0;

            // Check cell on the right.
            if (x != Size.X - 1)
                if (_cells[x + 1, y].IsAlive)
                    count++;

            // Check cell on the bottom right.
            if (x != Size.X - 1 && y != Size.Y - 1)
                if (_cells[x + 1, y + 1].IsAlive)
                    count++;

            // Check cell on the bottom.
            if (y != Size.Y - 1)
                if (_cells[x, y + 1].IsAlive)
                    count++;

            // Check cell on the bottom left.
            if (x != 0 && y != Size.Y - 1)
                if (_cells[x - 1, y + 1].IsAlive)
                    count++;

            // Check cell on the left.
            if (x != 0)
                if (_cells[x - 1, y].IsAlive)
                    count++;

            // Check cell on the top left.
            if (x != 0 && y != 0)
                if (_cells[x - 1, y - 1].IsAlive)
                    count++;

            // Check cell on the top.
            if (y != 0)
                if (_cells[x, y - 1].IsAlive)
                    count++;

            // Check cell on the top right.
            if (x != Size.X - 1 && y != 0)
                if (_cells[x + 1, y - 1].IsAlive)
                    count++;

            return count;
        }



        public void SetNextState()
        {
            for (var i = 0; i < Size.X; i++)
                for (var j = 0; j < Size.Y; j++)
                    _cells[i, j].IsAlive = _nextCellStates[i, j];
        }

        public void Draw(SpriteBatch spriteBatch)
        {
            foreach (Cell cell in _cells)
                cell.Draw(spriteBatch);

            // Draw vertical gridlines.
            for (var i = 0; i < Size.X; i++)
                spriteBatch.Draw(Game1.Pixel, new Rectangle(i * Game1.CellSize - 1, 0, 1, Size.Y * Game1.CellSize), Color.DarkGray);

            // Draw horizontal gridlines.
            for (var j = 0; j < Size.Y; j++)
                spriteBatch.Draw(Game1.Pixel, new Rectangle(0, j * Game1.CellSize - 1, Size.X * Game1.CellSize, 1), Color.DarkGray);
        }
    }
}
