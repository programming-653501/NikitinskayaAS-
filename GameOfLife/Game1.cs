using System;
using System.Collections.Generic;
using System.Linq;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Audio;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.GamerServices;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Media;
namespace GameOfLife
{
    public class Game1 : Microsoft.Xna.Framework.Game
	{
        // Updates per second.
		public const int UPS = 20;
        // Framerate per second. 
        public const int FPS = 100;

        private Texture2D backgroundTexture;
        private Texture2D frameTexture,
                          howToPlayTexture,
                          aboutGameTexture;

        private enum GameState
        {
            Menu,
            InGame,
            AboutGame,
            HowToPlay
        };
        private GameState currentGameState = GameState.Menu;

        public const int CellSize = 10; 
		public const int CellsX = 120;
		public const int CellsY = 90;

		public static bool Paused = true;
        
		public static SpriteFont Font;
		public static Texture2D Pixel;
        public SpriteFont Arial;


        public static Vector2 ScreenSize;

		private Grid grid;
        private KeyboardState keyboardState, lastKeyboardState;

		private GraphicsDeviceManager graphics;
		public SpriteBatch spriteBatch;
        
        private AudioEngine audioEngine;
        private WaveBank waveBank;
        private SoundBank soundBank;
        private Cue trackCue;


        public enum ButtonStates
        {
            Hover,
            Up,
            JustRelesed,
            Down
        }
        public const int NumberOfMenuButtons = 3,
            NumberOfGameButtons = 7,

            StartButtonIndex = 0,
            AboutGameButtonIndex = 1,
            ExitButtonIndex = 2,
            BackButtonIndex = 3,
            JustPointButtonIndex = 4,
            HeavyweightSpaceshipButtonIndex = 5,
            BlinkerPufferButtonIndex = 6,
            CoeShipButtonIndex = 7,
            WasherwomanButtonIndex = 8,
            HowToPlayButtonIndex = 9;
            
        public Color BackgroundColor;
        public Color[] ButtonColor = new Color[NumberOfMenuButtons + NumberOfGameButtons];
        public Rectangle[] ButtonRectangle = new Rectangle[NumberOfMenuButtons + NumberOfGameButtons];
        public ButtonStates[] ButtonState = new ButtonStates[NumberOfMenuButtons + NumberOfGameButtons];
        public Texture2D[] ButtonTexture = new Texture2D[NumberOfMenuButtons + NumberOfGameButtons];
        public double[] ButtonTimer = new double[NumberOfMenuButtons + NumberOfGameButtons];

        public bool mousePressed, prevMousePressed = false;
        // Mouse location in window.
        public int MouseStateX, MouseStateY;
        public double FrameTime;


        public Game1()
		{
			graphics = new GraphicsDeviceManager(this);
			Content.RootDirectory = "Content";

            IsFixedTimeStep = true;
			TargetElapsedTime = TimeSpan.FromSeconds(1.0 / FPS);

			ScreenSize = new Vector2(CellsX, CellsY + CellsY / 5) * CellSize;

			IsMouseVisible = true;
            graphics.PreferredBackBufferWidth = 1920;  
            graphics.PreferredBackBufferHeight = 1080;

            //graphics.IsFullScreen = true;
        }

        protected override void Initialize()
		{
            base.Initialize();

			grid = new Grid(this);
            Components.Add(grid);
            grid.Enabled = false;
            grid.Visible = false;

            keyboardState = lastKeyboardState = Keyboard.GetState();
            int ButtonHeight = Window.ClientBounds.Height / 10,
                ButtonWidth = Window.ClientBounds.Width / 10;

            ButtonRectangle[StartButtonIndex] = new Rectangle(Window.ClientBounds.Width * 7 / 8 - ButtonWidth,
                                                              Window.ClientBounds.Height / 2 - 3 * ButtonHeight, 
                                                              ButtonWidth * 3 / 2, 
                                                              ButtonHeight * 3 / 2);
            ButtonRectangle[AboutGameButtonIndex] = new Rectangle(Window.ClientBounds.Width * 5 / 6 - ButtonWidth / 2,
                                                                  Window.ClientBounds.Height * 8 / 9 - ButtonHeight * 3 / 2 - 20,
                                                                  ButtonWidth,
                                                                  ButtonHeight);
            ButtonRectangle[ExitButtonIndex] = new Rectangle(Window.ClientBounds.Width * 5 / 6 - ButtonWidth / 2,
                                                             Window.ClientBounds.Height * 8 / 9 - ButtonHeight / 2,
                                                             ButtonWidth,
                                                             ButtonHeight);
            ButtonRectangle[JustPointButtonIndex] = new Rectangle(Window.ClientBounds.Width * 8 / 9 - ButtonWidth / 2,
                                                                  Window.ClientBounds.Height / 100,
                                                                  ButtonTexture[JustPointButtonIndex].Width * 4 / 5,
                                                                  ButtonTexture[JustPointButtonIndex].Height * 4 / 5);
            ButtonRectangle[HeavyweightSpaceshipButtonIndex] = new Rectangle(Window.ClientBounds.Width * 3 / 4,
                                                                             Window.ClientBounds.Height / 80,
                                                                             ButtonTexture[HeavyweightSpaceshipButtonIndex].Width * 2 / 3,
                                                                             ButtonTexture[HeavyweightSpaceshipButtonIndex].Height * 2 / 3);
            ButtonRectangle[BlinkerPufferButtonIndex] = new Rectangle(Window.ClientBounds.Width * 8 / 9 - ButtonWidth / 2,
                                                                      Window.ClientBounds.Height / 3 - ButtonHeight,
                                                                      ButtonTexture[BlinkerPufferButtonIndex].Width * 3 / 4,
                                                                      ButtonTexture[BlinkerPufferButtonIndex].Height * 3 / 4);
            ButtonRectangle[CoeShipButtonIndex] = new Rectangle(Window.ClientBounds.Width * 3 / 4 - ButtonWidth / 5,
                                                                Window.ClientBounds.Height / 3 - ButtonHeight,
                                                                ButtonTexture[CoeShipButtonIndex].Width * 2 / 3,
                                                                ButtonTexture[CoeShipButtonIndex].Height * 2 / 3);
            ButtonRectangle[WasherwomanButtonIndex] = new Rectangle(Window.ClientBounds.Width * 3 / 4 - 10,
                                                                    Window.ClientBounds.Height / 3 - ButtonHeight + ButtonTexture[CoeShipButtonIndex].Height * 4 / 5,
                                                                    ButtonTexture[WasherwomanButtonIndex].Width / 2,
                                                                    ButtonTexture[WasherwomanButtonIndex].Height / 2);
            ButtonRectangle[HowToPlayButtonIndex] = new Rectangle(Window.ClientBounds.Width * 5 / 6 + ButtonWidth / 2,
                                                                  Window.ClientBounds.Height / 6 + 4 * ButtonHeight,
                                                                  ButtonWidth,
                                                                  ButtonHeight);
            ButtonRectangle[BackButtonIndex] = new Rectangle(Window.ClientBounds.Width * 5 / 6 + ButtonWidth / 2,
                                                             Window.ClientBounds.Height / 6 + 5 * ButtonHeight,
                                                             ButtonWidth,
                                                             ButtonHeight);
            
            for (var i = 0; i < NumberOfMenuButtons + NumberOfGameButtons; i++)
            {
                ButtonState[i] = ButtonStates.Up;
                ButtonColor[i] = Color.White;
                ButtonTimer[i] = 0.0;
            }
            IsMouseVisible = true;
            BackgroundColor = Color.CornflowerBlue;
        }

		protected override void LoadContent()
		{
            backgroundTexture = Content.Load<Texture2D>(@"Images\font");
            frameTexture = Content.Load<Texture2D>(@"Images\frame");
            howToPlayTexture = Content.Load<Texture2D>(@"Images\infoHowToPlay");
            aboutGameTexture = Content.Load<Texture2D>(@"Images\infoAboutGame");

            spriteBatch = new SpriteBatch(GraphicsDevice);
            audioEngine = new AudioEngine(@"Content\Audio\GameAudio.xgs");
            waveBank = new WaveBank(audioEngine, @"Content\Audio\Wave Bank.xwb");
            soundBank = new SoundBank(audioEngine, @"Content\Audio\Sound Bank.xsb");
            Arial = Content.Load<SpriteFont>("Arial");

            Pixel = new Texture2D(spriteBatch.GraphicsDevice, 1, 1);
			Pixel.SetData(new[] { Color.White });
            trackCue = soundBank.GetCue("audioBackground");
            trackCue.Play();
            ButtonTexture[StartButtonIndex] =
                Content.Load<Texture2D>(@"images/start");
            ButtonTexture[AboutGameButtonIndex] =
                Content.Load<Texture2D>(@"images/aboutGame");
            ButtonTexture[ExitButtonIndex] =
                Content.Load<Texture2D>(@"images/exit");
            ButtonTexture[JustPointButtonIndex] =
                Content.Load<Texture2D>(@"images/justPoint");
            ButtonTexture[HeavyweightSpaceshipButtonIndex] =
                Content.Load<Texture2D>(@"images/heavyweightSpaceship");
            ButtonTexture[BlinkerPufferButtonIndex] =
                Content.Load<Texture2D>(@"images/blinkerPuffer");
            ButtonTexture[CoeShipButtonIndex] =
                Content.Load<Texture2D>(@"images/coeShip");
            ButtonTexture[WasherwomanButtonIndex] =
                Content.Load<Texture2D>(@"images/washerwoman");
            ButtonTexture[HowToPlayButtonIndex] =
                Content.Load<Texture2D>(@"images/howToPlay");
            ButtonTexture[BackButtonIndex] =
                Content.Load<Texture2D>(@"images/back");
        }

		protected override void Update(GameTime gameTime)
		{
            keyboardState = Keyboard.GetState();
            
            // Toggle pause when spacebar is pressed.
            if (keyboardState.IsKeyDown(Keys.Space) && lastKeyboardState.IsKeyUp(Keys.Space))
            {
				Paused = !Paused;
            }

			// Clear the screen if backspace is pressed.
			if (keyboardState.IsKeyDown(Keys.Back) && lastKeyboardState.IsKeyUp(Keys.Back))
            {
				grid.Clear();
            }

            if (keyboardState.IsKeyDown(Keys.Escape) && lastKeyboardState.IsKeyUp(Keys.Escape))
            {
                Exit();
            }

            grid.Update(gameTime);
            audioEngine.Update();
            base.Update(gameTime);


            // Get elapsed frame time in seconds.
            FrameTime = gameTime.ElapsedGameTime.Milliseconds / 1000.0;

            // Update mouse variables.
            MouseState mouseState = Mouse.GetState();
            MouseStateX = mouseState.X;
            MouseStateY = mouseState.Y;
            prevMousePressed = mousePressed;
            mousePressed = mouseState.LeftButton == Microsoft.Xna.Framework.Input.ButtonState.Pressed;

            UpdateButtons();
            lastKeyboardState = keyboardState;             
        }

		protected override void Draw(GameTime gameTime)
        {
            switch (currentGameState)
            {
                case GameState.Menu:
                    GraphicsDevice.Clear(Color.White);
                    spriteBatch.Begin();
                    spriteBatch.Draw(backgroundTexture,
                     new Rectangle(0, 0, Window.ClientBounds.Width,
                     Window.ClientBounds.Height), null,
                     Color.White, 0, Vector2.Zero,
                     SpriteEffects.None, 0);
                    spriteBatch.Draw(frameTexture,
                     new Rectangle(0, 0, Window.ClientBounds.Width,
                     Window.ClientBounds.Height), null,
                     Color.White, 0, Vector2.Zero,
                     SpriteEffects.None, 0);
                    for (var i = 0; i < NumberOfMenuButtons; i++)
                        spriteBatch.Draw(ButtonTexture[i], ButtonRectangle[i], ButtonColor[i]);
                    spriteBatch.End();                    
                    break;

                case GameState.InGame:
                    GraphicsDevice.Clear(Color.White);
                    spriteBatch.Begin();
                    spriteBatch.Draw(backgroundTexture,
                    new Rectangle(0, 0, Window.ClientBounds.Width,
                    Window.ClientBounds.Height), null,
                    Color.White, 0, Vector2.Zero,
                    SpriteEffects.None, 0);
                    grid.Draw(spriteBatch);
                    for (var i = NumberOfMenuButtons - 1; i < NumberOfGameButtons + NumberOfMenuButtons; i++)
                        spriteBatch.Draw(ButtonTexture[i], ButtonRectangle[i], ButtonColor[i]);
                    if (Paused)
                    {
                        string paused = "Paused";
                        spriteBatch.DrawString(Arial, paused, new Vector2((Window.ClientBounds.Height / (9/8))
                         - (Arial.MeasureString(paused).Y / (9/8)), (Window.ClientBounds.Width / 2)
                         - (Arial.MeasureString(paused).X / 2)), Color.DarkBlue);
                    }
                    spriteBatch.End();
                    base.Draw(gameTime);

                    break;
                case GameState.AboutGame:
                    GraphicsDevice.Clear(Color.White);
                    spriteBatch.Begin();
                    spriteBatch.Draw(backgroundTexture,
                                     new Rectangle(0, 0, Window.ClientBounds.Width,
                                     Window.ClientBounds.Height), null,
                                     Color.White, 0, Vector2.Zero,
                                     SpriteEffects.None, 0);
                    spriteBatch.Draw(aboutGameTexture,
                                     new Rectangle(0, 0, Window.ClientBounds.Width,
                                     Window.ClientBounds.Height), null,
                                     Color.White, 0, Vector2.Zero,
                                     SpriteEffects.None, 0);
                    spriteBatch.Draw(ButtonTexture[BackButtonIndex],
                                     ButtonRectangle[BackButtonIndex],
                                     ButtonColor[BackButtonIndex]);
                    spriteBatch.End();
                    break;
                case GameState.HowToPlay:
                    GraphicsDevice.Clear(Color.White);
                    spriteBatch.Begin();
                    spriteBatch.Draw(backgroundTexture,
                                     new Rectangle(0, 0, Window.ClientBounds.Width,
                                     Window.ClientBounds.Height), null,
                                     Color.White, 0, Vector2.Zero,
                                     SpriteEffects.None, 0);
                    spriteBatch.Draw(howToPlayTexture,
                                     new Rectangle(0, 0, Window.ClientBounds.Width,
                                     Window.ClientBounds.Height), null,
                                     Color.White, 0, Vector2.Zero,
                                     SpriteEffects.None, 0);
                    spriteBatch.Draw(ButtonTexture[BackButtonIndex],
                                     ButtonRectangle[BackButtonIndex],
                                     ButtonColor[BackButtonIndex]);
                    spriteBatch.End();
                    break;
            }
        }

        // Wrapper for hit_image_alpha taking Rectangle and Texture.
        public Boolean HitImageAlpha(Rectangle rectangle, Texture2D texture, int x, int y)
        {
            return HitImageAlpha(0, 0, texture, texture.Width * (x - rectangle.X) /
                rectangle.Width, texture.Height * (y - rectangle.Y) / rectangle.Height);
        }

        // Wraps hit_image then determines if hit a transparent part of image. 
        public Boolean HitImageAlpha(float textureX, float textureY, Texture2D texture, int x, int y)
        {
            if (HitImage(textureX, textureY, texture, x, y))
            {
                uint[] data = new uint[texture.Width * texture.Height];
                texture.GetData<uint>(data);
                if ((x - (int)textureX) + (y - (int)textureY) *
                    texture.Width < texture.Width * texture.Height)
                {
                    return ((data[(x - (int)textureX) + (y - (int)textureY) * texture.Width] & 0xFF000000) >> 24) > 20;
                }
            }
            return false;
        }
        
        // Determine if x,y is within rectangle formed by texture located at tx,ty.
        public Boolean HitImage(float textureX, float textureY, Texture2D tex, int x, int y)
        {
            return (x >= textureX &&
                x <= textureX + tex.Width &&
                y >= textureY &&
                y <= textureY + tex.Height);
        }

        // Determine state and color of button.
        public void UpdateButtons()
        {
            for (var i = 0; i < NumberOfMenuButtons + NumberOfGameButtons; i++)
            {

                if (HitImageAlpha(ButtonRectangle[i], ButtonTexture[i], MouseStateX, MouseStateY))
                {
                    ButtonTimer[i] = 0.0;
                    if (mousePressed)
                    {
                        // Mouse is currently down.
                        ButtonState[i] = ButtonStates.Down;
                        ButtonColor[i] = Color.Blue;
                    }
                    else if (!mousePressed && prevMousePressed)
                    {
                        // Mouse was just released.
                        if (ButtonState[i] == ButtonStates.Down)
                        {
                            ButtonState[i] = ButtonStates.JustRelesed;
                        }
                    }
                    else
                    {
                        ButtonState[i] = ButtonStates.Hover;
                        ButtonColor[i] = Color.LightBlue;
                    }
                }
                else
                {
                    ButtonState[i] = ButtonStates.Up;
                    if (ButtonTimer[i] > 0)
                    {
                        ButtonTimer[i] = ButtonTimer[i] - FrameTime;
                    }
                    else
                    {
                        ButtonColor[i] = Color.White;
                    }
                }

                if (ButtonState[i] == ButtonStates.JustRelesed)
                {
                    TakeActionOnButton(i);
                }
            }
        }


        // Logic for each button click goes here.
        public void TakeActionOnButton(int i)
        {
            // Take action corresponding to which button was clicked.
            switch (i)
            {
                case StartButtonIndex:
                    currentGameState = GameState.InGame;
                    break;
                case AboutGameButtonIndex:
                    currentGameState = GameState.AboutGame;
                    break;
                case BackButtonIndex:
                    if(currentGameState == GameState.AboutGame
                        || currentGameState == GameState.InGame)
                        currentGameState = GameState.Menu;
                    else if (currentGameState == GameState.HowToPlay)
                        currentGameState = GameState.InGame;
                    Paused = true;
                    break;
                case ExitButtonIndex:
                    Exit();
                    break;
                case JustPointButtonIndex:
                    Grid.JustPoint = true;
                    Grid.BlinkerPuffer = false;
                    Grid.CoeShip = false;
                    Grid.Washerwoman = false;
                    Grid.HeavyweightSpaceship = false;
                    break;
                case BlinkerPufferButtonIndex:
                    Grid.JustPoint = false;
                    Grid.BlinkerPuffer = true;
                    Grid.CoeShip = false;
                    Grid.Washerwoman = false;
                    Grid.HeavyweightSpaceship = false;
                    break;
                case CoeShipButtonIndex:
                    Grid.JustPoint = false;
                    Grid.BlinkerPuffer = false;
                    Grid.CoeShip = true;
                    Grid.Washerwoman = false;
                    Grid.HeavyweightSpaceship = false;
                    break;
                case WasherwomanButtonIndex:
                    Grid.JustPoint = false;
                    Grid.BlinkerPuffer = false;
                    Grid.CoeShip = false;
                    Grid.Washerwoman = true;
                    Grid.HeavyweightSpaceship = false;
                    break;
                case HeavyweightSpaceshipButtonIndex:
                    Grid.JustPoint = false;
                    Grid.BlinkerPuffer = false;
                    Grid.CoeShip = false;
                    Grid.Washerwoman = false;
                    Grid.HeavyweightSpaceship = true;
                    break;
                case HowToPlayButtonIndex:
                    Paused = true;
                    currentGameState = GameState.HowToPlay;
                    break;
            }
        }
    }
}
