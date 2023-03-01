namespace Neoskye.Engine;

public enum WindowMode {
  Windowed,
  Fullscreen,
  BorderlessWindowed,
}

public struct Configuration {
  public Vector2 size;
  public WindowMode winMode;
}

public class Engine {
  private FNAInstance _backend;
  private static Engine? _inst;
  private Configuration _cfg;
  public Configuration Config {
    get => _cfg;
    set { _cfg = value; UpdateConfig(); }
  }

  private void UpdateConfig() {
    _inst?._backend.Resize(_cfg.size);
  }

  public static Engine Instance {
    get {
      if (_inst is not null)
        return _inst;
      throw new ArgumentNullException();
    }
  }

  public Engine(Action<Engine> setup) {
    _backend = new();
    _inst = this;
    setup(this);
    _backend.Run();
  }
}

