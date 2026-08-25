// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LR
// Source by-file doc: by-file/NewHumanImageLib.md
// UID:000092 | by-class/NewHumanImageLib.md | Completion:90 | Confidence:91
#include "ImageFrameTable.h"

// UID:0001VF | by-type/by-struct/NewHumanImageLibLayout.md | Completion:92 | Confidence:93
// NewHumanImageLib layout/type facts support the class and method emitters; no standalone source body is emitted from this layout page.

// UID:0002JR | by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md | Completion:91 | Confidence:92
NewHumanImageLib::NewHumanImageLib()
    : LObject(),
      m_partEntries(),
      m_layerEntries(),
      m_motionEntries(),
      m_compositionDrawCommands(),
      m_loadedPartList(),
      m_acc2drwEntries(),
      m_hairColorEntries()
{
    g_pNewHumanImageLib = this;

    LoadMotionTable(L"Motion.tbl");

    {
        DATFile layerFile;
        unsigned char header[23];
        int layerCount = 0;

        layerFile.Open(L"Layer.tbl");
        layerFile.Read(header, sizeof(header));
        layerFile.Read(&layerCount, sizeof(layerCount));

        for (int index = 0; index < layerCount; ++index)
        {
            NewHumanLayerEntry layer = {};

            layerFile.Read(&layer.layerId, sizeof(layer.layerId));
            layerFile.Read(layer.name, sizeof(layer.name));
            layerFile.Read(&layer.childCount, sizeof(layer.childCount));

            if (layer.childCount > 0)
            {
                layer.childIndexes = new int[layer.childCount];
                layerFile.Read(layer.childIndexes,
                               sizeof(layer.childIndexes[0]) * layer.childCount);
            }

            m_layerEntries.push_back(layer);
        }

        layerFile.Close();
    }

    {
        DATFile partFile;
        unsigned char header[23];
        int partCount = 0;

        partFile.Open(L"Part.tbl");
        partFile.Read(header, sizeof(header));
        partFile.Read(&partCount, sizeof(partCount));

        for (int index = 0; index < partCount; ++index)
        {
            NewHumanPartEntry part = {};
            char partName[256];

            partFile.Read(&part.partId, sizeof(part.partId));
            partFile.Read(partName, 20);
            partFile.Read(&part.drawIndexBase, sizeof(part.drawIndexBase));
            partFile.Read(&part.descriptorBase, sizeof(part.descriptorBase));

            const int partNameLength = strlen(partName);
            MultiByteToWideChar(CP_ACP, 0, partName, partNameLength, part.name, 255);
            part.name[partNameLength] = L'\0';

            part.spriteArchive = ResolveSpritePartPath(part.name);
            m_partEntries.push_back(part);
        }

        partFile.Close();
    }

    LoadPartSpriteDescriptors();
    LoadAcc2DrwTable(L"acc2drw.tbl");

    {
        DATFile hairColorFile;
        char colorText[6];
        const int hairColorCount = m_partEntries[kNewHumanHairPartIndex].descriptorCount;

        hairColorFile.Open(L"HAIRCOL.TBL");

        for (int index = 0; index < hairColorCount; ++index)
        {
            memset(colorText, 0, sizeof(colorText));
            hairColorFile.ReadLine(colorText, sizeof(colorText));
            m_hairColorEntries.push_back(ParseUnsignedLongBase10(colorText));
        }

        hairColorFile.Close();
    }
}

// UID:00017S | by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md | Completion:90 | Confidence:91
NewHumanImageLib::~NewHumanImageLib()
{
    for (NewHumanPartEntry *part = m_partEntries.begin();
         part != m_partEntries.end();
         ++part)
    {
        ReleaseSpritePartArchive(part->spriteArchive);

        for (int descriptorIndex = 0;
             descriptorIndex < part->descriptorCount;
             ++descriptorIndex)
        {
            NewHumanPartFrameDescriptor &descriptor =
                part->frameDescriptors[descriptorIndex];

            delete [] descriptor.primaryFrameData;
            descriptor.primaryFrameData = NULL;
            descriptor.hasPrimaryFrameData = false;

            delete [] descriptor.secondaryFrameData;
            descriptor.secondaryFrameData = NULL;
            descriptor.hasSecondaryFrameData = false;

            for (int sequenceIndex = 0;
                 sequenceIndex < descriptor.sequenceCount;
                 ++sequenceIndex)
            {
                delete [] descriptor.sequenceFrames[sequenceIndex].frames;
                descriptor.sequenceFrames[sequenceIndex].frames = NULL;
                descriptor.sequenceFrames[sequenceIndex].frameCount = 0;
            }

            delete [] descriptor.sequenceFrames;
            descriptor.sequenceFrames = NULL;
            descriptor.sequenceCount = 0;
        }

        delete [] part->frameDescriptors;
        part->frameDescriptors = NULL;
        part->descriptorCount = 0;
    }

    for (NewHumanLayerEntry *layer = m_layerEntries.begin();
         layer != m_layerEntries.end();
         ++layer)
    {
        delete [] layer->childIndexes;
        layer->childIndexes = NULL;
        layer->childCount = 0;
    }

    for (NewHumanMotionEntry *motion = m_motionEntries.begin();
         motion != m_motionEntries.end();
         ++motion)
    {
        delete [] motion->frameOffsets;
        motion->frameOffsets = NULL;

        delete [] motion->frameData;
        motion->frameData = NULL;
        motion->frameCount = 0;
    }

    m_hairColorEntries.clear();
    DestroyAcc2DrwVector(&m_acc2drwEntries);
    DestroyLoadedPartListState(&m_loadedPartList);
    DestroyCompositionDrawCommands(&m_compositionDrawCommands);
    // First-draft shorthand for the lowered vector-storage cleanup at [UID:000185][0x004e5dd0-0x004e5e39.DestroyMotionVector](by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md);
    // not proof of a standalone source-authored helper body.
    DestroyMotionVector(&m_motionEntries);
    DestroyLayerVector(&m_layerEntries);
    DestroyPartVector(&m_partEntries);

    g_pNewHumanImageLib = NULL;
}

// UID:000417 | by-memory/0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord.md | Completion:86 | Confidence:88
void NewHumanImageLib::LoadPartFrameDrawRecord(
    int partIndex,
    unsigned short descriptorIndex,
    int motionIndex,
    int frameIndex,
    FrameDrawRecord *outRecord)
{
    NewHumanPartEntry &part = m_partEntries[partIndex];
    NewHumanPartFrameDescriptor &descriptor =
        part.frameDescriptors[descriptorIndex];
    NewHumanSequenceFrameTable &sequence =
        descriptor.sequenceFrames[motionIndex];

    if (sequence.frames == NULL)
        return;

    g_pEPFLib->LoadFrameDrawRecord(
        part.rawRecords,
        sequence.frames[frameIndex].recordIndex + descriptor.drawIndexBase,
        outRecord);
}

// UID:000419 | by-memory/0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable.md | Completion:86 | Confidence:88
void NewHumanImageLib::LoadMotionTable(const wchar_t *tableName)
{
    DATFile motionFile;
    unsigned char header[23];
    int motionCount = 0;

    motionFile.Open(tableName);
    motionFile.Read(header, sizeof(header));
    motionFile.Read(&motionCount, sizeof(motionCount));

    for (int index = 0; index < motionCount; ++index)
    {
        NewHumanMotionEntry motion = {};

        motionFile.Read(&motion.motionId, sizeof(motion.motionId));
        motionFile.Read(motion.name, sizeof(motion.name));
        motionFile.Read(&motion.direction, sizeof(motion.direction));
        motionFile.Read(&motion.fallbackMotionId,
                        sizeof(motion.fallbackMotionId));
        motionFile.Read(&motion.frameCount, sizeof(motion.frameCount));

        motion.frameOffsets = new unsigned short[motion.frameCount];
        motion.frameData = new unsigned char[motion.frameCount * 120];

        for (int frameIndex = 0;
             frameIndex < motion.frameCount;
             ++frameIndex)
        {
            motionFile.Read(&motion.frameOffsets[frameIndex],
                            sizeof(motion.frameOffsets[frameIndex]));
            motionFile.Read(&motion.frameData[frameIndex * 120], 120);
        }

        m_motionEntries.push_back(motion);
    }

    motionFile.Close();
}

// UID:00041A | by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md | Completion:86 | Confidence:87
void NewHumanImageLib::LoadLayerTable(const wchar_t *tableName)
{
    DATFile layerFile;
    unsigned char header[23];
    int layerCount = 0;

    layerFile.Open(tableName);
    layerFile.Read(header, sizeof(header));
    layerFile.Read(&layerCount, sizeof(layerCount));

    for (int index = 0; index < layerCount; ++index)
    {
        NewHumanLayerEntry layer = {};

        layerFile.Read(&layer.layerId, sizeof(layer.layerId));
        layerFile.Read(layer.name, sizeof(layer.name));
        layerFile.Read(&layer.childCount, sizeof(layer.childCount));

        if (layer.childCount > 0)
        {
            layer.childIndexes = new int[layer.childCount];

            for (int childIndex = 0;
                 childIndex < layer.childCount;
                 ++childIndex)
            {
                layerFile.Read(&layer.childIndexes[childIndex],
                               sizeof(layer.childIndexes[childIndex]));
            }
        }

        m_layerEntries.push_back(layer);
    }

    layerFile.Close();
}

// UID:00041B | by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md | Completion:87 | Confidence:90
void NewHumanImageLib::LoadPartTable(const wchar_t *tableName)
{
    DATFile partFile;
    unsigned char header[23];
    int partCount = 0;

    partFile.Open(tableName);
    partFile.Read(header, sizeof(header));
    partFile.Read(&partCount, sizeof(partCount));

    for (int index = 0; index < partCount; ++index)
    {
        NewHumanPartEntry part = {};
        char partName[256];

        partFile.Read(&part.partId, sizeof(part.partId));
        partFile.Read(partName, 20);
        partFile.Read(&part.drawIndexBase, sizeof(part.drawIndexBase));
        partFile.Read(&part.descriptorBase, sizeof(part.descriptorBase));

        const int partNameLength = strlen(partName);
        MultiByteToWideChar(CP_ACP, 0, partName, partNameLength, part.name, 255);
        part.name[partNameLength] = L'\0';

        part.spriteArchive = ResolveSpritePartPath(part.name);
        m_partEntries.push_back(part);
    }

    partFile.Close();
}

// UID:00041C | by-memory/0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors.md | Completion:86 | Confidence:88
void NewHumanImageLib::LoadPartSpriteDescriptors()
{
    for (NewHumanPartEntry *part = m_partEntries.begin();
         part != m_partEntries.end();
         ++part)
    {
        DATFile descriptorFile;
        WideString descriptorName = part->name;
        unsigned char header[23];
        int descriptorCount = 0;
        int totalRawRecordCount = 0;

        descriptorName += L".DSC";

        descriptorFile.Open(descriptorName.c_str());
        descriptorFile.Read(header, sizeof(header));
        descriptorFile.Read(&descriptorCount, sizeof(descriptorCount));

        if (descriptorCount > 0)
        {
            part->frameDescriptors =
                new NewHumanPartFrameDescriptor[descriptorCount];
            part->descriptorCount = descriptorCount;

            for (int descriptorIndex = 0;
                 descriptorIndex < descriptorCount;
                 ++descriptorIndex)
            {
                NewHumanPartFrameDescriptor &descriptor =
                    part->frameDescriptors[descriptorIndex];

                descriptor = NewHumanPartFrameDescriptor();

                descriptorFile.Read(&descriptor.descriptorId,
                                    sizeof(descriptor.descriptorId));
                descriptorFile.Read(&descriptor.frameBase,
                                    sizeof(descriptor.frameBase));
                descriptorFile.Read(&descriptor.drawIndexBase,
                                    sizeof(descriptor.drawIndexBase));
                descriptorFile.Read(&descriptor.rawRecordCount,
                                    sizeof(descriptor.rawRecordCount));
                totalRawRecordCount += descriptor.rawRecordCount;

                descriptorFile.Read(&descriptor.primaryFrameCount,
                                    sizeof(descriptor.primaryFrameCount));
                if (descriptor.primaryFrameCount > 0)
                {
                    descriptor.primaryFrameData =
                        new unsigned short[descriptor.primaryFrameCount];
                    descriptorFile.Read(
                        descriptor.primaryFrameData,
                        sizeof(descriptor.primaryFrameData[0]) *
                            descriptor.primaryFrameCount);
                }

                descriptorFile.Read(&descriptor.secondaryFrameCount,
                                    sizeof(descriptor.secondaryFrameCount));
                if (descriptor.secondaryFrameCount > 0)
                {
                    descriptor.secondaryFrameData =
                        new unsigned short[descriptor.secondaryFrameCount];
                    descriptorFile.Read(
                        descriptor.secondaryFrameData,
                        sizeof(descriptor.secondaryFrameData[0]) *
                            descriptor.secondaryFrameCount);
                }

                int populatedSequenceCount = 0;
                descriptorFile.Read(&populatedSequenceCount,
                                    sizeof(populatedSequenceCount));

                int motionCount =
                    static_cast<int>(m_motionEntries.end() -
                                     m_motionEntries.begin());
                descriptor.sequenceCount = motionCount;
                descriptor.sequenceFrames =
                    new NewHumanSequenceFrameTable[motionCount];

                for (int motionIndex = 0;
                     motionIndex < motionCount;
                     ++motionIndex)
                {
                    NewHumanSequenceFrameTable &sequenceFrames =
                        descriptor.sequenceFrames[motionIndex];

                    sequenceFrames.motionIndex = -1;
                    sequenceFrames.frameBase = -1;
                    sequenceFrames.frameCount = 0;
                    sequenceFrames.frames = NULL;
                }

                for (int sequenceIndex = 0;
                     sequenceIndex < populatedSequenceCount;
                     ++sequenceIndex)
                {
                    int motionIndex = 0;
                    descriptorFile.Read(&motionIndex, sizeof(motionIndex));

                    NewHumanSequenceFrameTable &sequenceFrames =
                        descriptor.sequenceFrames[motionIndex];
                    sequenceFrames.motionIndex = motionIndex;

                    descriptorFile.Read(&sequenceFrames.frameBase,
                                        sizeof(sequenceFrames.frameBase));
                    descriptorFile.Read(&sequenceFrames.frameCount,
                                        sizeof(sequenceFrames.frameCount));

                    sequenceFrames.frames =
                        new NewHumanSequenceFrame[sequenceFrames.frameCount];

                    for (int frameIndex = 0;
                         frameIndex < sequenceFrames.frameCount;
                         ++frameIndex)
                    {
                        NewHumanSequenceFrame &frame =
                            sequenceFrames.frames[frameIndex];

                        descriptorFile.Read(&frame.recordIndex,
                                            sizeof(frame.recordIndex));
                        descriptorFile.Read(&frame.flags,
                                            sizeof(frame.flags));
                        descriptorFile.Read(&frame.value,
                                            sizeof(frame.value));
                    }
                }
            }

            part->rawRecordCount = totalRawRecordCount;
            descriptorFile.Close();
        }
    }
}

// UID:00041D | by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md | Completion:86 | Confidence:88
void NewHumanImageLib::LoadAcc2DrwTable(const wchar_t *tableName)
{
    DATFile acc2drwFile;
    char line[4096];
    const int acc2drwCount = m_partEntries[7].descriptorCount;

    acc2drwFile.Open(tableName);
    m_acc2drwEntries.clear();

    for (int index = 0; index < acc2drwCount; ++index)
    {
        if (acc2drwFile.ReadLine(line, sizeof(line)) <= 1)
        {
            DestroyDATFileMgr();
            DestroyExceptionHandler();
            MessageBoxW(0,
                        L"Error on ACC2DRW table!",
                        L"Error",
                        MB_ICONEXCLAMATION);
            __loaddll(0);
        }

        const int flags = ParseUnsignedLongBase10(line);
        Acc2DrwEntry entry = {};

        entry.enabled[0] = (flags % 1000) / 100 != 0;
        entry.enabled[1] = (flags % 100) / 10 != 0;
        entry.enabled[2] = (flags % 10) != 0;

        m_acc2drwEntries.push_back(entry);
    }

    acc2drwFile.Close();
}

// UID:0002V8 | by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md | Completion:91 | Confidence:92
#include "ImageLib.h"
#include "ResourceLayoutTable.h"
#include "RidingImageLib.h"

int NewHumanImageLib::CalculateCompositionBounds(
    const int *drawOrder,
    const NewHumanCompositionState &inputState,
    int sequence,
    int frame,
    RectBounds *bounds,
    RectBounds *projectedBounds,
    char direction)
{
    NewHumanCompositionState state = inputState;
    RectBounds partBounds;
    const RidingDefinition *ridingDefinition;
    int ridingYOffset;
    int normalizedSequence;
    int drawIndex;
    int tag;
    int bucket;
    int height;
    int projectedLeft;
    int projectedRight;
    float horizontalOffset;
    float verticalOffset;
    bool secondAccessoryPass;
    bool mergePart;
    int result = 0;

    ridingYOffset = 0;
    if (state.compositionMode == 3)
        ridingYOffset = state.ridingYOffset;

    if (state.baseBodyPartId == 0)
        return result;

    RectBoundsClear(bounds, 0, 0, 0, 0);

    if (state.compositionMode == 2) {
        result = RectBoundsSet(bounds, 0, 0, g_mapTilePixelHeight, g_mapTilePixelWidth);
        goto FinishBounds;
    }

    if (state.specialCompositionPartId != 0xffff) {
        ResolveCompositionPartRect(
            &m_partEntries[17],
            state.specialCompositionPartId,
            sequence,
            frame,
            ridingYOffset,
            0,
            &partBounds);
        RectBoundsUnion(bounds, &partBounds);

        if (state.compositionMode == 3) {
            ridingDefinition =
                g_pRidingImageLib->GetDefinitionOrDefault(state.ridingDefinitionIndex);
            ResourceLayoutRawRecordGetEntryRect(
                g_pRidingImageLib->ridingEpfPackage,
                ridingDefinition->baseRectIndex + 3 * sequence +
                    kNewHumanRidingFrameRectOffsets[frame] - 24,
                &partBounds);
        }

        RectBoundsUnion(bounds, &partBounds);
        result = RectBoundsOffset(bounds, g_mapTilePixelWidth / 2, g_mapTilePixelHeight / 2);
        goto FinishBounds;
    }

    if (state.compositionMode == 1) {
        int gfaceIndex = g_pEPFLib->FindResourceIndex(L"GFACE.EPF");
        if (gfaceIndex == -1)
            gfaceIndex = g_pEPFLib->LoadResourceIndex(L"GFACE.EPF");

        const ResourceLayoutNameRecord *gface =
            g_pEPFLib->GetResourceLayout(gfaceIndex);
        if (gface->entryCount != 0 && gface->entries != NULL)
            *bounds = *reinterpret_cast<const RectBounds *>(
                &gface->entries[0]);
        else
            RectBoundsSet(bounds, 0, 0, 0, 0);

        result = RectBoundsOffset(bounds, g_mapTilePixelWidth / 2, g_mapTilePixelHeight / 2);
        goto FinishBounds;
    }

    normalizedSequence = sequence;
    if (sequence >= 38 && sequence <= 50 && sequence != 47 && sequence != 49)
        normalizedSequence = direction + 55;

    secondAccessoryPass = false;
    for (drawIndex = 0; drawIndex < 30; ++drawIndex) {
        tag = drawOrder[drawIndex];
        mergePart = false;
        RectBoundsClear(&partBounds, 0, 0, 0, 0);

        switch (tag) {
        case 0x32:
            if (state.alternateBodyPartId == 0xffff)
                ResolveCompositionPartRect(
                    &m_partEntries[0], state.baseBodyPartId, normalizedSequence,
                    frame, ridingYOffset, 0, &partBounds);
            else
                ResolveCompositionPartRect(
                    &m_partEntries[1], state.alternateBodyPartId, normalizedSequence,
                    frame, ridingYOffset, 0, &partBounds);
            mergePart = true;
            break;

        case 0x33:
            state.baseBodyPartId = (unsigned short)(state.baseBodyPartId - 200);
            if (sequence >= 38 && sequence <= 54)
                ResolveCompositionPartRect(
                    &m_partEntries[3], state.baseBodyPartId, sequence,
                    frame, ridingYOffset, 0, &partBounds);
            else
                ResolveCompositionPartRect(
                    &m_partEntries[2], state.baseBodyPartId, sequence,
                    frame, ridingYOffset, 0, &partBounds);
            mergePart = true;
            break;

        case 0x34:
            if (state.acc2drwSelector != 0xffff &&
                !m_acc2drwEntries[state.acc2drwSelector].enabled[0])
                break;
            if (state.acc2drwPart0Id != 0xffff)
                ResolveCompositionPartRect(
                    &m_partEntries[4], state.acc2drwPart0Id, sequence,
                    frame, ridingYOffset, 0, &partBounds);
            mergePart = true;
            break;

        case 0x35:
            if (state.acc2drwSelector != 0xffff &&
                !m_acc2drwEntries[state.acc2drwSelector].enabled[1])
                break;
            if (state.facePartId != 0xff)
                ResolveCompositionPartRect(
                    &m_partEntries[5], state.facePartId, sequence,
                    frame, ridingYOffset, 0, &partBounds);
            mergePart = true;
            break;

        case 0x36:
            if (secondAccessoryPass) {
                if (state.acc2drwSelector != 0xffff)
                    ResolveCompositionPartRect(
                        &m_partEntries[7], state.acc2drwSelector, sequence,
                        frame, ridingYOffset, 0, &partBounds);
                mergePart = true;
            } else {
                --drawIndex;
                secondAccessoryPass = true;
                if (state.acc2drwSelector == 0xffff ||
                    m_acc2drwEntries[state.acc2drwSelector].enabled[2]) {
                    if (state.accessoryLowPartId != 0xff)
                        ResolveCompositionPartRect(
                            &m_partEntries[6], state.accessoryLowPartId, sequence,
                            frame, ridingYOffset, 0, &partBounds);
                    mergePart = true;
                }
            }
            break;

        case 0x37:
            bucket = ClassifyHumanPartFiveBucket(state.primaryEquipmentId);
            switch (bucket) {
            case 1:
                ResolveCompositionPartRect(
                    &m_partEntries[8], state.primaryEquipmentId, sequence,
                    frame, ridingYOffset, 0, &partBounds);
                break;
            case 2:
                ResolveCompositionPartRect(
                    &m_partEntries[9], state.primaryEquipmentId - 10000, sequence,
                    frame, ridingYOffset, 0, &partBounds);
                break;
            case 3:
                ResolveCompositionPartRect(
                    &m_partEntries[10], state.primaryEquipmentId - 20000, sequence,
                    frame, ridingYOffset, 0, &partBounds);
                break;
            case 4:
                ResolveCompositionPartRect(
                    &m_partEntries[11], state.primaryEquipmentId - 30000, sequence,
                    frame, ridingYOffset, 0, &partBounds);
                break;
            default:
                break;
            }
            mergePart = true;
            break;

        case 0x38:
            if (ClassifyHumanPartTwoBucket(state.secondaryEquipmentId) == 1)
                ResolveCompositionPartRect(
                    &m_partEntries[12], state.secondaryEquipmentId, sequence,
                    frame, ridingYOffset, 0, &partBounds);
            mergePart = true;
            break;

        case 0x39:
            if (state.capeOrBackPartId != 0xffff)
                ResolveCompositionPartRect(
                    &m_partEntries[14], state.capeOrBackPartId, normalizedSequence,
                    frame, ridingYOffset, 0, &partBounds);
            mergePart = true;
            break;

        case 0x3a:
            if (state.overlayPartIdA != 0xffff)
                ResolveCompositionPartRect(
                    &m_partEntries[15], state.overlayPartIdA, normalizedSequence,
                    frame, ridingYOffset, 0, &partBounds);
            mergePart = true;
            break;

        case 0x3b:
            if (state.overlayPartIdB != 0xffff)
                ResolveCompositionPartRect(
                    &m_partEntries[16], state.overlayPartIdB, normalizedSequence,
                    frame, ridingYOffset, 0, &partBounds);
            mergePart = true;
            break;

        case 0x3c: {
            ridingDefinition =
                g_pRidingImageLib->GetDefinitionOrDefault(state.ridingDefinitionIndex);
            ResourceLayoutRawRecordGetEntryRect(
                g_pRidingImageLib->ridingEpfPackage,
                ridingDefinition->baseRectIndex + 3 * sequence - 24 +
                    kNewHumanRidingFrameRectOffsets[frame],
                &partBounds);
            mergePart = true;
            break;
        }

        case 0x3e:
            if (ClassifyHumanPartTwoBucket(state.secondaryEquipmentId) == 2) {
                ResolveCompositionPartRect(
                    &m_partEntries[13], state.secondaryEquipmentId - 10000, sequence,
                    frame, ridingYOffset, 0, &partBounds);
            } else if (ClassifyHumanPartFiveBucket(state.primaryEquipmentId) == 5) {
                ResolveCompositionPartRect(
                    &m_partEntries[18],
                    (unsigned short)(state.primaryEquipmentId + 25536),
                    sequence,
                    frame,
                    ridingYOffset,
                    0,
                    &partBounds);
            }
            mergePart = true;
            break;

        case 0x3d:
        case 0x3f:
            mergePart = true;
            break;

        default:
            break;
        }

        if (mergePart)
            RectBoundsUnion(bounds, &partBounds);
    }

    result = RectBoundsOffset(bounds, g_mapTilePixelWidth / 2, g_mapTilePixelHeight / 2);

FinishBounds:
    if (projectedBounds != NULL) {
        height = bounds->bottom - bounds->top;
        horizontalOffset = g_activeMapPane->m_newHumanProjectionShear * (float)height;
        verticalOffset = (float)height / g_activeMapPane->m_newHumanProjectionDivisor;

        projectedRight = bounds->right;
        if (projectedRight <= (int)((float)projectedRight + horizontalOffset))
            projectedRight = (int)((float)bounds->right + horizontalOffset);

        projectedLeft = (int)((float)bounds->left + horizontalOffset);
        if (bounds->left <= projectedLeft)
            projectedLeft = bounds->left;

        return RectBoundsSet(
            projectedBounds,
            projectedLeft,
            (int)((float)bounds->bottom - verticalOffset - 1.0f),
            projectedRight,
            bounds->bottom);
    }

    return result;
}

// UID:000437 | by-memory/0x004e4140-0x004e4205.NewHumanImageLibResolveCompositionPartRect.md | Completion:92 | Confidence:94
void NewHumanImageLib::ResolveCompositionPartRect(
    NewHumanPartEntry *part,
    unsigned short descriptorIndex,
    int motionIndex,
    int frameIndex,
    int yOffset,
    int xOffset,
    RectBounds *outBounds)
{
    int descriptorCount = part->descriptorCount;
    if (descriptorCount == 0)
        return;

    int selectedDescriptor = 0;
    if (descriptorCount > descriptorIndex)
        selectedDescriptor = descriptorIndex;

    NewHumanPartFrameDescriptor &descriptor =
        part->frameDescriptors[selectedDescriptor];
    NewHumanSequenceFrameTable &sequence =
        descriptor.sequenceFrames[motionIndex];

    if (sequence.frames == NULL)
        return;

    int rectIndex = sequence.frames[frameIndex].recordIndex +
        descriptor.drawIndexBase;
    if (rectIndex >= part->rawRecords->recordCount)
        outBounds->SetLTRB(0, 0, 0, 0);
    else
        *outBounds = part->rawRecords->records[rectIndex].bounds;

    outBounds->Offset(xOffset, yOffset);
}

// UID:000438 | by-memory/0x004e4210-0x004e427c.NewHumanImageLibResolveCompositionPartFrame.md | Completion:92 | Confidence:94
void NewHumanImageLib::ResolveCompositionPartFrame(
    NewHumanPartEntry *part,
    unsigned short descriptorIndex,
    int motionIndex,
    int frameIndex,
    int yOffset,
    int xOffset,
    FrameDrawRecord *outRecord)
{
    int selectedDescriptor = 0;
    if (part->descriptorCount > descriptorIndex)
        selectedDescriptor = descriptorIndex;

    NewHumanPartFrameDescriptor &descriptor =
        part->frameDescriptors[selectedDescriptor];
    NewHumanSequenceFrameTable &sequence =
        descriptor.sequenceFrames[motionIndex];

    if (sequence.frames == NULL)
        return;

    g_pEPFLib->LoadFrameDrawRecord(
        part->rawRecords,
        sequence.frames[frameIndex].recordIndex + descriptor.drawIndexBase,
        outRecord);

    outRecord->sourceRect.Offset(xOffset, yOffset);
}

// UID:0002VN | by-memory/0x004e6870-0x004e68a8.NewHumanImageLibScalarDeletingDestructor.md | Completion:86 | Confidence:91
// Compiler-generated scalar deleting destructor for NewHumanImageLib; source reconstruction is represented by the virtual destructor declaration and [UID:00017S][0x004e0250-0x004e05c4.NewHumanImageLibDestructor](by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md) ordinary destructor body.

// UID:0001Y9 | by-type/by-vtable/NewHumanImageLibVtable.md | Completion:86 | Confidence:90
// NewHumanImageLib vtable bytes are compiler-generated from the class declaration and virtual member definitions; no hand-authored vtable object is emitted here.

// UID:0000RT | by-global/g_pNewHumanImageLib.md | Completion:90 | Confidence:93
NewHumanImageLib *g_pNewHumanImageLib = 0;

// UID:0000PK | by-global/DestroyMotionVector.md | Completion:88 | Confidence:91
// DestroyMotionVector is a documented/search alias for exact helper [UID:000185][0x004e5dd0-0x004e5e39.DestroyMotionVector](by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md).
// Source behavior lives in [UID:00017S][0x004e0250-0x004e05c4.NewHumanImageLibDestructor](by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md) NewHumanImageLib::~NewHumanImageLib and the m_motionEntries vector member cleanup; no duplicate global helper body is emitted here.

// UID:0000TO | by-global/VectorGrowMotion.md | Completion:86 | Confidence:88
// VectorGrowMotion is documented by exact helper [UID:00017T][0x004e5240-0x004e5415.VectorGrowMotion](by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md) and emitted source behavior lives in [UID:000419][0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable](by-memory/0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable.md) NewHumanImageLib::LoadMotionTable; no duplicate global helper body is emitted here.

// UID:0000VA | by-item/ResolveSpritePartPath_004E19D0.md | Completion:87 | Confidence:91
// ResolveSpritePartPath source-body ownership belongs to exact helper [UID:0002VD][0x004e19d0-0x004e1f27.ResolveSpritePartPath](by-memory/0x004e19d0-0x004e1f27.ResolveSpritePartPath.md); this item page does not emit a duplicate helper body.

// UID:0002VD | by-memory/0x004e19d0-0x004e1f27.ResolveSpritePartPath.md | Completion:89 | Confidence:91
ArchiveMetadataTable *ResolveSpritePartPath(const wchar_t *baseName)
{
    struct SpritePartArchiveHeader
    {
        unsigned short frameCount;
        unsigned short maxWidth;
        unsigned short maxHeight;
        unsigned short reserved;
    };

    wchar_t archiveName[20];
    swprintf(archiveName, 20, L"%s%d.EPF", baseName, 0);

    if (HasDATEntry(archiveName))
    {
        int probeIndex = 0;
        unsigned char shardCount = 0;
        do
        {
            ++probeIndex;
            ++shardCount;
            swprintf(archiveName, 20, L"%s%d.EPF", baseName, probeIndex);
        }
        while (HasDATEntry(archiveName));

        const int shardTotal = shardCount;
        SpritePartArchiveHeader *headers =
            shardTotal > 0 ? new SpritePartArchiveHeader[shardTotal] : 0;
        DATFile *archives = shardTotal > 0 ? new DATFile[shardTotal] : 0;

        ArchiveMetadataTable *table = new ArchiveMetadataTable;
        table->frameCount = 0;
        table->maxWidth = 0;
        table->maxHeight = 0;
        table->reserved = 0;
        table->records = 0;

        for (int i = 0; i < shardTotal; ++i)
        {
            swprintf(archiveName, 20, L"%s%d.EPF", baseName, i);
            archives[i].Open(archiveName);
            archives[i].Read(&headers[i], 8);

            table->frameCount =
                static_cast<unsigned short>(table->frameCount + headers[i].frameCount);
            if (table->maxWidth < headers[i].maxWidth)
            {
                table->maxWidth = headers[i].maxWidth;
            }
            if (table->maxHeight < headers[i].maxHeight)
            {
                table->maxHeight = headers[i].maxHeight;
            }
        }

        table->records = new PackedArchiveRecord[table->frameCount + 1];
        PackedArchiveRecord *outRecord = table->records;
        unsigned char *lastPayloadBase = 0;
        int lastRecordTableOffset = 0;

        for (int i = 0; i < shardTotal; ++i)
        {
            int recordTableOffset = 0;
            archives[i].Read(&recordTableOffset, sizeof(recordTableOffset));

            unsigned char *payloadBase = archives[i].GetDataPointer();
            lastPayloadBase = payloadBase;
            lastRecordTableOffset = recordTableOffset;

            archives[i].Seek(recordTableOffset, 1);

            for (int recordIndex = 0;
                 recordIndex < headers[i].frameCount;
                 ++recordIndex)
            {
                short top = 0;
                short left = 0;
                short bottom = 0;
                short right = 0;
                int payloadStartOffset = 0;
                int payloadEndOffset = 0;

                archives[i].Read(&top, sizeof(top));
                archives[i].Read(&left, sizeof(left));
                archives[i].Read(&bottom, sizeof(bottom));
                archives[i].Read(&right, sizeof(right));
                archives[i].Read(&payloadStartOffset, sizeof(payloadStartOffset));
                archives[i].Read(&payloadEndOffset, sizeof(payloadEndOffset));

                InitRectBounds(&outRecord->bounds, left, top, right, bottom);
                outRecord->payloadStart = payloadBase + payloadStartOffset;
                outRecord->payloadEnd = payloadBase + payloadEndOffset;
                ++outRecord;
            }
        }

        InitRectBounds(&outRecord->bounds, 0, 0, 0, 0);
        outRecord->payloadStart =
            lastPayloadBase != 0 ? lastPayloadBase + lastRecordTableOffset : 0;
        outRecord->payloadEnd =
            lastPayloadBase != 0 ? lastPayloadBase + lastRecordTableOffset : 0;

        for (int i = shardTotal - 1; i >= 0; --i)
        {
            archives[i].Close();
        }

        delete [] archives;
        delete [] headers;

        return table;
    }

    swprintf(archiveName, 20, L"%s.EPF", baseName);
    if (!HasDATEntry(archiveName))
    {
        return 0;
    }

    DATFile archive;
    archive.Open(archiveName);

    ArchiveMetadataTable *table = new ArchiveMetadataTable;
    archive.Read(table, 8);

    table->records = new PackedArchiveRecord[table->frameCount + 1];
    PackedArchiveRecord *outRecord = table->records;

    int recordTableOffset = 0;
    archive.Read(&recordTableOffset, sizeof(recordTableOffset));

    unsigned char *payloadBase = archive.GetDataPointer();
    archive.Seek(recordTableOffset, 1);

    for (int recordIndex = 0; recordIndex < table->frameCount; ++recordIndex)
    {
        short top = 0;
        short left = 0;
        short bottom = 0;
        short right = 0;
        int payloadStartOffset = 0;
        int payloadEndOffset = 0;

        archive.Read(&top, sizeof(top));
        archive.Read(&left, sizeof(left));
        archive.Read(&bottom, sizeof(bottom));
        archive.Read(&right, sizeof(right));
        archive.Read(&payloadStartOffset, sizeof(payloadStartOffset));
        archive.Read(&payloadEndOffset, sizeof(payloadEndOffset));

        InitRectBounds(&outRecord->bounds, left, top, right, bottom);
        outRecord->payloadStart = payloadBase + payloadStartOffset;
        outRecord->payloadEnd = payloadBase + payloadEndOffset;
        ++outRecord;
    }

    InitRectBounds(&outRecord->bounds, 0, 0, 0, 0);
    outRecord->payloadStart = payloadBase + recordTableOffset;
    outRecord->payloadEnd = payloadBase + recordTableOffset;

    archive.Close();
    return table;
}

// UID:00041E | by-memory/0x004e4f10-0x004e50a0.VectorGrowAcc2Drw.md | Completion:86 | Confidence:88
// Emitted code for this Acc2DrwEntry vector growth slow path is covered by
// [UID:00041D][0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable](by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md) NewHumanImageLib::LoadAcc2DrwTable source as
// m_acc2drwEntries.push_back(entry), or by a local NewHumanImageLib/vector
// compatibility template if recovered typed source cannot regenerate this
// out-of-line helper.
// Do not emit a standalone decompiler-shaped VectorGrowAcc2Drw body here.

// UID:00041F | by-memory/0x004e50a0-0x004e523e.VectorGrowLayer.md | Completion:86 | Confidence:88
// Emitted code for this NewHumanLayerEntry vector-growth slow path is covered by [UID:0002JR][0x004dfd10-0x004e024a.NewHumanImageLibConstructor](by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md)
// and [UID:00041A][0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable](by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md) m_layerEntries.push_back(layer) source, or by a
// [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md) VectorHelpers compatibility template if the recovered typed
// source cannot regenerate this out-of-line helper.
// Do not emit a standalone decompiler-shaped VectorGrowLayer helper body here.

// UID:00017T | by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md | Completion:87 | Confidence:90
// Emitted code for this NewHumanMotionEntry vector-growth slow path is covered by
// [UID:000419][0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable](by-memory/0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable.md) NewHumanImageLib::LoadMotionTable source as
// m_motionEntries.push_back(motion), or by a local NewHumanImageLib/vector
// compatibility template if recovered typed source cannot regenerate this
// out-of-line helper.
// Do not emit a standalone decompiler-shaped VectorGrowMotion helper body here.

// UID:00041G | by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md | Completion:86 | Confidence:88
// Emitted code for this NewHumanPartEntry vector-growth slow path is covered by [UID:0002JR][0x004dfd10-0x004e024a.NewHumanImageLibConstructor](by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md)
// and [UID:00041B][0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable](by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md) m_partEntries.push_back(part) source, or by a
// [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md) VectorHelpers compatibility template if the recovered typed
// source cannot regenerate this out-of-line helper.
// Do not emit a standalone decompiler-shaped VectorGrowPart helper body here.

// UID:0004PA | by-memory/0x004e5600-0x004e57bb.NewHumanCompositionDrawCommandVectorGrowInsertCompilerSupport.md | Completion:92 | Confidence:93
// Compiler-generated full-capacity grow/insert support for the
// std::vector<NewHumanCompositionDrawCommand> member used by
// NewHumanImageLib::BuildCompositionDrawCommands.
// Regenerated by the human source operation:
//     m_compositionDrawCommands.push_back(drawCommand);
// Do not emit an independent source function for [0x004e5600,0x004e57bb).

// UID:00017U | by-memory/0x004e57c0-0x004e5989.RecordVectorInsert.md | Completion:92 | Confidence:94
// Compiler-generated grow/insert support for the local
// std::vector<FrameDrawRecord> in NewHumanImageLib::RenderComposition.
// Regenerated by the human source operation:
//     frameDrawRecords.push_back(frameDrawRecord);
// The compiler emits the full-capacity path and its private range-copy support;
// do not emit an independent RecordVector class method.

// UID:000182 | by-memory/0x004e5be0-0x004e5beb.NewHumanImageLibSingletonClearHelper.md | Completion:86 | Confidence:93
// Static cleanup glue clears g_pNewHumanImageLib through the cleanup table; source-level singleton state is emitted by [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md) and lifecycle code, so this helper is not hand-authored separately.

// UID:000185 | by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md | Completion:88 | Confidence:91
// Compiler-lowered vector cleanup for NewHumanImageLib::m_motionEntries.
// Source behavior is represented by [UID:00017S][0x004e0250-0x004e05c4.NewHumanImageLibDestructor](by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md) NewHumanImageLib::~NewHumanImageLib:
// it releases each NewHumanMotionEntry payload, then destroys the vector storage.
// Do not emit a standalone DestroyMotionVector helper body for this vector cleanup thunk.

// UID:0004DN | by-memory/0x004e6e50-0x004e6fe2.NewHumanImageLibGrowCommandSideVector.md | Completion:88 | Confidence:91
// NewHumanImageLibGrowCommandSideVector is compiler-lowered command-side
// pointer-ring/vector growth support for NewHumanImageLib::BuildPartDrawCommand.
// Source behavior should live in typed BuildPartDrawCommand command-append
// logic, or in a local vector compatibility template if needed.
// Do not emit a standalone allocator/memmove/memset helper body here.

// UID:0004DO | by-memory/0x004e6ff0-0x004e7026.FrameDrawRecordUninitializedCopyCompilerSupport.md | Completion:92 | Confidence:94
// Compiler-generated uninitialized range-copy support for the local
// std::vector<FrameDrawRecord> in NewHumanImageLib::RenderComposition.
// Regenerated by the human source operation:
//     frameDrawRecords.push_back(frameDrawRecord);
// Do not emit an independent source function for [0x004e6ff0,0x004e7026).

// UID:0004DQ | by-memory/0x004e70a0-0x004e70e9.NewHumanCompositionDrawCommandPushBackCompilerSupport.md | Completion:92 | Confidence:93
// Compiler-generated std::vector<NewHumanCompositionDrawCommand>::push_back
// support for NewHumanImageLib::BuildCompositionDrawCommands.
// Regenerated by the human source operation:
//     m_compositionDrawCommands.push_back(drawCommand);
// Do not emit an independent source function for [0x004e70a0,0x004e70e9).

// UID:00050M | by-type\by-struct\HumanImageRenderParams.md | Completion:94 | Confidence:95 | Empty Emitter Marker
