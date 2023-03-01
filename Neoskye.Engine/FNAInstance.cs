namespace Neoskye.Engine;

internal class FNAInstance : Game {
  private GraphicsDeviceManager _graphics;
  private SpriteBatch? sb;

  public FNAInstance() : base() {
    _graphics = new(this);
  }

  protected override void Initialize() {
    sb = new(GraphicsDevice);
    base.Initialize();
  }

  protected override void LoadContent() {
    base.LoadContent();
  }

  protected override void Update(GameTime gt) {
    var kbs = Keyboard.GetState();
    if (kbs.IsKeyDown(Keys.D1)) {
      SetWindowMode(WindowMode.Windowed);
    } else if (kbs.IsKeyDown(Keys.D2)) {
      SetWindowMode(WindowMode.Fullscreen);
    } else if (kbs.IsKeyDown(Keys.D3)) {
      SetWindowMode(WindowMode.BorderlessWindowed);
    }
    base.Update(gt);
  }

  protected override void Draw(GameTime gt) {
    GraphicsDevice.Clear(Color.CornflowerBlue);
    base.Draw(gt);
  }

  internal void SetWindowMode(WindowMode winMode) {
    switch (winMode) {
      case WindowMode.Windowed:
        _graphics.IsFullScreen = false;
        Window.IsBorderlessEXT = false;
        _graphics.ApplyChanges();
        break;
      case WindowMode.Fullscreen:
        _graphics.IsFullScreen = true;
        _graphics.ApplyChanges();
        break;
      case WindowMode.BorderlessWindowed:
        _graphics.IsFullScreen = false;
        Window.IsBorderlessEXT = true;
        _graphics.ApplyChanges();
        break;
    }
  }

  internal void Resize(Vector2 size) {
    _graphics.PreferredBackBufferWidth = ((int)size.X);
    _graphics.PreferredBackBufferHeight = ((int)size.Y);
    _graphics.ApplyChanges();
  }
}