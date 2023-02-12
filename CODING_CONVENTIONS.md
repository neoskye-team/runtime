# Neoskye coding conventions

## Naming

Classes: PascalCase  
Local variables: camelCase  
Class fields (public): camelCase  
Class fields (private/protected): \_camelCase  
Template names: PascalCase with T prefix (e.g. `template<typename TKey, typename TValue>`)
Interfaces (i.e. classes with only virtual functions): PascalCase with I prefix (`IWindow`)

## Braces

Always

```cpp
somedecl {

}
```

## Number types

Always use number types from `<cstdint>`, except in `int main()`.


Example

```cpp
uint32_t loadSprite(const std::string& path);
```

`[u]intptr_t` is either 32 or 64 bits long, depending on the target architecture.
