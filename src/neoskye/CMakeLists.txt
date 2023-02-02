set(NEOSKYE_SOURCE_DIR "src/neoskye")

set(NEOSKYE_SOURCES
    ${NEOSKYE_SOURCE_DIR}/Neoskye.cpp 
    ${NEOSKYE_SOURCE_DIR}/EngineOptions.cpp 
    ${NEOSKYE_SOURCE_DIR}/Entity.cpp 
    ${NEOSKYE_SOURCE_DIR}/View.cpp 
    ${NEOSKYE_SOURCE_DIR}/Input.cpp 
    ${NEOSKYE_SOURCE_DIR}/Controller.cpp 
    ${NEOSKYE_SOURCE_DIR}/Vector2.cpp 
    ${NEOSKYE_SOURCE_DIR}/content/ContentLoader.cpp 
    ${NEOSKYE_SOURCE_DIR}/content/TextData.cpp 
    ${NEOSKYE_SOURCE_DIR}/content/Sprite.cpp
    ${NEOSKYE_SOURCE_DIR}/graphics/SpriteBatch.cpp
    ${NEOSKYE_SOURCE_DIR}/components/rectrenderer.cpp
    ${NEOSKYE_SOURCE_DIR}/components/spriterenderer.cpp
    ${NEOSKYE_SOURCE_DIR}/components/spatial.cpp
PARENT_SCOPE)