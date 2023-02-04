namespace neoskye {

namespace util {
  inline float lerp(float a, float b, float t) {
    return a + (b - a) * t; // this returns a + t percent (t = 0.f is 0% and t = 1.f is 100%) of b
  }
} // namespace neoskye::util
  
} // namespace neoskye
