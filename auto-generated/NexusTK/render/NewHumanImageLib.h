// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LR
// Source by-file doc: by-file/NewHumanImageLib.md
// UID:00050M | by-type/by-struct/HumanImageRenderParams.md | Completion:94 | Confidence:95
#pragma pack(push, 1)
struct HumanImageRenderParams
{
    unsigned int m_statusKind;
    union {
        unsigned short m_appearanceId;
        unsigned short m_faceId;
        unsigned short m_shapeIndex;
    };
    union {
        unsigned char m_variantOrPalette;
        unsigned char m_hairId;
        unsigned char m_headDrawOffset;
    };
    unsigned char m_padding07;
    unsigned short m_bodyId;
    unsigned short m_weaponId;
    unsigned short m_shieldOrArrowId;
    unsigned char m_helmetId;
    unsigned char m_padding0f;
    unsigned short m_faceDecorationId;
    unsigned short m_hairDecorationId;
    unsigned short m_secondFaceDecorationId;
    unsigned short m_mantleId;
    unsigned short m_neckId;
    unsigned short m_shoesId;
    unsigned short m_coatId;
    unsigned short m_fullBodyId;
    unsigned char m_headgearMode;
    union {
        unsigned char m_gender;
        unsigned char m_direction;
    };
    union {
        unsigned char m_compositionMode;
        unsigned char m_posture;
    };
    unsigned char m_padding23;
    unsigned int m_actionState;
    union {
        unsigned char m_displayStatusByte;
        unsigned char m_defaultByte;
    };
    unsigned char m_padding29;
    unsigned short m_ridingAppearanceId;
    unsigned short m_ridingDefinitionIndex;
    unsigned short m_ridingPaletteFlags;
    short m_ridingYOffset;
    unsigned char m_faceColor;
    unsigned char m_hairColor;
    unsigned char m_skinColor;
    unsigned char m_bodyColor;
    unsigned char m_weaponColor;
    unsigned char m_shieldOrArrowColor;
    unsigned char m_helmetColor;
    unsigned char m_faceDecorationColor;
    unsigned char m_hairDecorationColor;
    unsigned char m_secondFaceDecorationColor;
    unsigned char m_mantleColor;
    unsigned char m_neckColor;
    unsigned char m_shoesColor;
    unsigned char m_invisible;
};
#pragma pack(pop)

typedef char HumanImageRenderParamsSizeMustBe64[
    (sizeof(HumanImageRenderParams) == 0x40) ? 1 : -1];

// UID:000092 | by-class/NewHumanImageLib.md | Completion:90 | Confidence:91
// UID:0001VF | by-type/by-struct/NewHumanImageLibLayout.md | Completion:92 | Confidence:93
#include "ImageFrameTable.h"
#include "Surface.h"

#pragma pack(push, 1)
struct NewHumanSequenceFrame
{
    int recordIndex;
    unsigned char flags;
    int value;
};
#pragma pack(pop)

struct NewHumanSequenceFrameTable
{
    int motionIndex;
    int frameBase;
    int frameCount;
    NewHumanSequenceFrame *frames;
};

#pragma pack(push, 1)
struct NewHumanPartFrameDescriptor
{
    int descriptorId;
    int frameBase;
    int drawIndexBase;
    int rawRecordCount;
    unsigned char primaryFrameCount;
    unsigned short *primaryFrameData;
    unsigned char secondaryFrameCount;
    unsigned short *secondaryFrameData;
    unsigned short sequenceCount;
    NewHumanSequenceFrameTable *sequenceFrames;
};
#pragma pack(pop)

struct NewHumanPartEntry
{
    int partId;
    wchar_t name[20];
    int drawIndexBase;
    int descriptorBase;
    int descriptorCount;
    int rawRecordCount;
    NewHumanPartFrameDescriptor *frameDescriptors;
    ArchiveMetadataTable *spriteArchive;
};

struct NewHumanLayerEntry
{
    int layerId;
    char name[20];
    int childCount;
    int *childIndexes;
};

#pragma pack(push, 1)
struct NewHumanMotionEntry
{
    unsigned char reservedPrefix[0x17];
    int motionId;
    char name[20];
    unsigned char reservedAfterName[2];
    unsigned char direction;
    int fallbackMotionId;
    int frameCount;
    unsigned short *frameOffsets;
    unsigned char *frameData;
};
#pragma pack(pop)

struct NewHumanCompositionDrawCommand
{
    int partId;
    FrameDrawRecord frame;
    SurfaceSpriteBlitOptions options;
    DLPalette *palette;
};

struct Acc2DrwEntry
{
    bool enabled[3];
};

typedef char NewHumanSequenceFrameSizeMustBe9[
    (sizeof(NewHumanSequenceFrame) == 0x09) ? 1 : -1];
typedef char NewHumanSequenceFrameTableSizeMustBe16[
    (sizeof(NewHumanSequenceFrameTable) == 0x10) ? 1 : -1];
typedef char NewHumanPartFrameDescriptorSizeMustBe32[
    (sizeof(NewHumanPartFrameDescriptor) == 0x20) ? 1 : -1];
typedef char NewHumanPartEntrySizeMustBe68[
    (sizeof(NewHumanPartEntry) == 0x44) ? 1 : -1];
typedef char NewHumanLayerEntrySizeMustBe32[
    (sizeof(NewHumanLayerEntry) == 0x20) ? 1 : -1];
typedef char NewHumanMotionEntrySizeMustBe66[
    (sizeof(NewHumanMotionEntry) == 0x42) ? 1 : -1];
typedef char NewHumanCompositionDrawCommandSizeMustBe80[
    (sizeof(NewHumanCompositionDrawCommand) == 0x50) ? 1 : -1];
typedef char Acc2DrwEntrySizeMustBe3[
    (sizeof(Acc2DrwEntry) == 0x03) ? 1 : -1];

#include "../util/LObject.h"
#include <deque>
#include <vector>

class GrafPort;
class Motion;
struct NewHumanCompositionState;
struct NewHumanCommandSideRecord;

class NewHumanImageLib : public LObject
{
public:
    NewHumanImageLib();
    virtual ~NewHumanImageLib();

    void CalculateBounds(const HumanImageRenderParams *appearance,
                         unsigned char direction,
                         Motion *motion,
                         int frameIndex,
                         RectBounds *imageBounds,
                         RectBounds *secondaryBounds,
                         int renderMode,
                         bool moving,
                         int rotationStep);
    void Draw(GrafPort *target,
              const RectBounds *bounds,
              const HumanImageRenderParams *appearance,
              unsigned char direction,
              Motion *motion,
              unsigned int effectState,
              int frameIndex,
              bool useMapLightOverlay,
              FrameDrawRecord *translatedClipRecord,
              float translatedClipOffset,
              int renderMode,
              bool moving,
              int rotationStep);

private:
    void LoadPartFrameDrawRecord(int partIndex,
                                 unsigned short descriptorIndex,
                                 int motionIndex,
                                 int frameIndex,
                                 FrameDrawRecord *outRecord);
    void LoadMotionTable(const wchar_t *tableName);
    void LoadLayerTable(const wchar_t *tableName);
    void LoadPartTable(const wchar_t *tableName);
    void LoadPartSpriteDescriptors();
    void LoadAcc2DrwTable(const wchar_t *tableName);
    int CalculateCompositionBounds(const int *drawOrder,
                                   const NewHumanCompositionState &state,
                                   int sequence,
                                   int frame,
                                   RectBounds *bounds,
                                   RectBounds *projectedBounds,
                                   char direction);
    void ResolveCompositionPartRect(NewHumanPartEntry *part,
                                    unsigned short descriptorIndex,
                                    int motionIndex,
                                    int frameIndex,
                                    int yOffset,
                                    int xOffset,
                                    RectBounds *outBounds);
    void ResolveCompositionPartFrame(NewHumanPartEntry *part,
                                     unsigned short descriptorIndex,
                                     int motionIndex,
                                     int frameIndex,
                                     int yOffset,
                                     int xOffset,
                                     FrameDrawRecord *outRecord);

    std::vector<NewHumanPartEntry> m_partEntries;
    std::vector<NewHumanLayerEntry> m_layerEntries;
    std::vector<NewHumanMotionEntry> m_motionEntries;
    std::vector<NewHumanCompositionDrawCommand> m_compositionDrawCommands;
    std::deque<NewHumanCommandSideRecord *> m_loadedPartList;
    std::vector<Acc2DrwEntry> m_acc2drwEntries;
    std::vector<unsigned long> m_hairColorEntries;
};

// UID:0000RT | by-global/g_pNewHumanImageLib.md | Completion:90 | Confidence:93
extern NewHumanImageLib *g_pNewHumanImageLib;
