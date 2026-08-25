// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JY
// Source by-file doc: by-file/HumanImageLib.md
// UID:00006A | by-class/HumanImageLib.md | Completion:92 | Confidence:93
class HumanImageLib : public LObject, public Singleton<HumanImageLib>
{
public:
    HumanImageLib();
    virtual ~HumanImageLib();

private:
    ProtectedArray<HeadInfo> m_headInfos;
    ProtectedArray<HeadInfo> m_specialHeadInfos;
    ProtectedArray<BodyInfo> m_bodyInfos;
    ProtectedArray<CoatInfo> m_coatInfos;
    ProtectedArray<WeaponInfo> m_swordInfos;
    ProtectedArray<WeaponInfo> m_spearInfos;
    ProtectedArray<WeaponInfo> m_bowInfos;
    ProtectedArray<WeaponInfo> m_fanInfos;
    ProtectedArray<WeaponInfo> m_shieldInfos;
    ProtectedArray<WeaponInfo> m_arrowInfos;
    ProtectedArray<FaceInfo> m_faceInfos;
    ProtectedArray<Acc1Info> m_accessory1Infos;
    ProtectedArray<HairInfo> m_hairInfos;
    ProtectedArray<Acc2Info> m_accessory2Infos;
    ProtectedArray<HelmetInfo> m_helmetInfos;
    ProtectedArray<MantleInfo> m_mantleInfos;
    ProtectedArray<NecklaceInfo> m_necklaceInfos;
    ProtectedArray<ShoeInfo> m_shoeInfos;

    int m_drawOrderCount;
    int m_extendedDrawOrderCount;
    int m_extendedDrawOrder2Count;
    unsigned int *m_drawOrderEntries;
    HumanDrawOrderEntry *m_extendedDrawOrderEntries;
    HumanDrawOrderEntry *m_extendedDrawOrder2Entries;
    unsigned short m_headFrameCount;
    unsigned short m_specialHeadFrameCount;
    unsigned short m_emotionFrameCount;
    unsigned short m_specialEmotionFrameCount;
    ImageFrameTable *m_headFrames;
    ImageFrameTable *m_specialHeadFrames;
    ImageFrameTable *m_bodyFrames;
    ImageFrameTable *m_swordFrames;
    ImageFrameTable *m_spearFrames;
    ImageFrameTable *m_bowFrames;
    ImageFrameTable *m_fanFrames;
    ImageFrameTable *m_shieldFrames;
    ImageFrameTable *m_arrowFrames;
    ImageFrameTable *m_faceFrames;
    ImageFrameTable *m_accessory1Frames;
    ImageFrameTable *m_hairFrames;
    ImageFrameTable *m_accessory2Frames;
    ImageFrameTable *m_helmetFrames;
    ImageFrameTable *m_mantleFrames;
    ImageFrameTable *m_necklaceFrames;
    ImageFrameTable *m_shoeFrames;
    ImageFrameTable *m_coatFrames;
};

extern HumanImageLib *g_pHumanImageLib;

// UID:0002TO | by-memory/0x004d2720-0x004d4aca.HumanImageLibConstructor.md | Completion:91 | Confidence:92
static void LoadHumanHeadInfoTable(ProtectedArray<HeadInfo> &rows,
                                   DATFile &file,
                                   const char *sourceName);
static void LoadHumanWeaponInfoTable(ProtectedArray<WeaponInfo> &rows,
                                     DATFile &file,
                                     const char *sourceName);

HumanImageLib::HumanImageLib()
    : LObject(),
      Singleton<HumanImageLib>(),
      m_headInfos(10),
      m_specialHeadInfos(10),
      m_bodyInfos(10),
      m_coatInfos(10),
      m_swordInfos(10),
      m_spearInfos(10),
      m_bowInfos(10),
      m_fanInfos(10),
      m_shieldInfos(10),
      m_arrowInfos(10),
      m_faceInfos(10),
      m_accessory1Infos(10),
      m_hairInfos(10),
      m_accessory2Infos(10),
      m_helmetInfos(10),
      m_mantleInfos(10),
      m_necklaceInfos(10),
      m_shoeInfos(10),
      m_drawOrderCount(0),
      m_extendedDrawOrderCount(0),
      m_extendedDrawOrder2Count(0),
      m_drawOrderEntries(0),
      m_extendedDrawOrderEntries(0),
      m_extendedDrawOrder2Entries(0),
      m_headFrameCount(0),
      m_specialHeadFrameCount(0),
      m_emotionFrameCount(0),
      m_specialEmotionFrameCount(0),
      m_headFrames(0), m_specialHeadFrames(0), m_bodyFrames(0),
      m_swordFrames(0), m_spearFrames(0), m_bowFrames(0),
      m_fanFrames(0), m_shieldFrames(0), m_arrowFrames(0),
      m_faceFrames(0), m_accessory1Frames(0), m_hairFrames(0),
      m_accessory2Frames(0), m_helmetFrames(0), m_mantleFrames(0),
      m_necklaceFrames(0), m_shoeFrames(0), m_coatFrames(0)
{
    DATFile headInfoFile;
    headInfoFile.Open(kHumanHeadTableArgs);
    LoadHumanHeadInfoTable(m_headInfos, headInfoFile, "headtable.txt");

    DATFile specialHeadInfoFile;
    specialHeadInfoFile.Open(kHumanSpecialHeadTableArgs);
    LoadHumanHeadInfoTable(m_specialHeadInfos,
                           specialHeadInfoFile,
                           "headsptable.txt");
    LoadHumanInfoTable(m_bodyInfos, L"BODY.TBL");
    LoadHumanInfoTable(m_coatInfos, L"COAT.TBL");
    DATFile swordInfoFile;
    swordInfoFile.Open(kHumanSwordTableArgs);
    LoadHumanWeaponInfoTable(m_swordInfos, swordInfoFile, "swordtable.txt");

    DATFile spearInfoFile;
    spearInfoFile.Open(kHumanSpearTableArgs);
    LoadHumanWeaponInfoTable(m_spearInfos, spearInfoFile, "speartable.txt");

    DATFile bowInfoFile;
    bowInfoFile.Open(kHumanBowTableArgs);
    LoadHumanWeaponInfoTable(m_bowInfos, bowInfoFile, "bowtable.txt");

    DATFile fanInfoFile;
    fanInfoFile.Open(kHumanFanTableArgs);
    LoadHumanWeaponInfoTable(m_fanInfos, fanInfoFile, "fantable.txt");

    DATFile shieldInfoFile;
    shieldInfoFile.Open(kHumanShieldTableArgs);
    LoadHumanWeaponInfoTable(m_shieldInfos, shieldInfoFile, "shieldtable.txt");

    DATFile arrowInfoFile;
    arrowInfoFile.Open(kHumanArrowTableArgs);
    LoadHumanWeaponInfoTable(m_arrowInfos, arrowInfoFile, "arrowtable.txt");
    LoadHumanInfoTable(m_faceInfos, L"FACE.TBL");
    LoadHumanInfoTable(m_accessory1Infos, L"ACE1.TBL");
    LoadHumanInfoTable(m_hairInfos, L"HAIR.TBL");
    LoadHumanInfoTable(m_accessory2Infos, L"ACE2.TBL");
    LoadHumanInfoTable(m_helmetInfos, L"HELMET.TBL");
    LoadHumanInfoTable(m_mantleInfos, L"MANTLE.TBL");
    LoadHumanInfoTable(m_necklaceInfos, L"NECLACE.TBL");
    LoadHumanInfoTable(m_shoeInfos, L"SHOES.TBL");
    LoadHumanDrawOrderTable(L"DRWORDER.TBL", &m_drawOrderEntries, &m_drawOrderCount);
    LoadHumanDrawOrderTable(L"XDRWORD.TBL", &m_extendedDrawOrderEntries, &m_extendedDrawOrderCount);
    LoadHumanDrawOrderTable(L"XDRWORD2.TBL", &m_extendedDrawOrder2Entries, &m_extendedDrawOrder2Count);

    m_headFrames = LoadImageFrameTable(L"HEAD.EPF", 0);
    m_specialHeadFrames = LoadImageFrameTable(L"HEADSP.EPF", 0);
    m_bodyFrames = LoadImageFrameTable(L"BODY.EPF", 0);
    m_swordFrames = LoadImageFrameTable(L"SWORD.EPF", 0);
    m_spearFrames = LoadImageFrameTable(L"SPEAR.EPF", 0);
    m_bowFrames = LoadImageFrameTable(L"BOW.EPF", 0);
    m_fanFrames = LoadImageFrameTable(L"FAN.EPF", 0);
    m_shieldFrames = LoadImageFrameTable(L"SHIELD.EPF", 0);
    m_arrowFrames = LoadImageFrameTable(L"ARROW.EPF", 0);
    m_faceFrames = LoadImageFrameTable(L"FACE.EPF", 0);
    m_accessory1Frames = LoadImageFrameTable(L"ACE1.EPF", 0);
    m_hairFrames = LoadImageFrameTable(L"HAIR.EPF", 0);
    m_accessory2Frames = LoadImageFrameTable(L"ACE2.EPF", 0);
    m_helmetFrames = LoadImageFrameTable(L"HELMET.EPF", 0);
    m_mantleFrames = LoadImageFrameTable(L"MANTLE.EPF", 0);
    m_necklaceFrames = LoadImageFrameTable(L"NECLACE.EPF", 0);
    m_shoeFrames = LoadImageFrameTable(L"SHOES.EPF", 0);
    m_coatFrames = LoadImageFrameTable(L"COAT.EPF", 0);

    ResolveHumanEmotionFrameCounts(L"EMOTION.EPF", L"EMOTIOSP.EPF",
        &m_headFrameCount, &m_specialHeadFrameCount,
        &m_emotionFrameCount, &m_specialEmotionFrameCount);
    ApplyHumanAccessoryDrawTable(m_accessory2Infos, L"ACC2DRW.TBL");
    ApplyHumanHairColorTable(m_hairInfos, L"HAIRCOL.TBL");
    ValidateHumanFrameCounts();
}

// UID:00017B | by-memory/0x004d4ad0-0x004d4f67.HumanImageLibDestructor.md | Completion:92 | Confidence:94
HumanImageLib::~HumanImageLib()
{
    ReleaseImageFrameTable(m_headFrames);
    ReleaseImageFrameTable(m_specialHeadFrames);
    ReleaseImageFrameTable(m_bodyFrames);
    ReleaseImageFrameTable(m_swordFrames);
    ReleaseImageFrameTable(m_spearFrames);
    ReleaseImageFrameTable(m_bowFrames);
    ReleaseImageFrameTable(m_fanFrames);
    ReleaseImageFrameTable(m_shieldFrames);
    ReleaseImageFrameTable(m_arrowFrames);
    ReleaseImageFrameTable(m_faceFrames);
    ReleaseImageFrameTable(m_accessory1Frames);
    ReleaseImageFrameTable(m_hairFrames);
    ReleaseImageFrameTable(m_accessory2Frames);
    ReleaseImageFrameTable(m_helmetFrames);
    ReleaseImageFrameTable(m_mantleFrames);
    ReleaseImageFrameTable(m_necklaceFrames);
    ReleaseImageFrameTable(m_shoeFrames);
    ReleaseImageFrameTable(m_coatFrames);
    delete[] m_drawOrderEntries;
    delete[] m_extendedDrawOrderEntries;
    delete[] m_extendedDrawOrder2Entries;
}

// UID:0001UR | by-type/by-struct/HumanImageLibLayout.md | Completion:92 | Confidence:93
// The complete HumanImageLib declaration is emitted once by UID00006A.

// UID:0000R5 | by-global/g_pHumanImageLib.md | Completion:92 | Confidence:94
class HumanImageLib;

HumanImageLib *g_pHumanImageLib = 0;

[[No Children Attached]]

// UID:0004DK | by-memory/0x004e6ae0-0x004e6c4c.HumanImageLibLoadTripleRecordTable.md | Completion:91 | Confidence:92
static void LoadHumanHeadInfoTable(ProtectedArray<HeadInfo> &rows,
                                   DATFile &file,
                                   const char *sourceName)
{
    (void)sourceName;
    rows.GetDefaultEntry().frameIndex = -1;
    rows.GetDefaultEntry().offsetX = -1;
    rows.GetDefaultEntry().offsetY = -255;

    int count = -1;
    if (!file.ReadEncodedTableInt(&count))
        g_imageLibraryLoadErrorFlag = true;
    if (count > 0 && rows.GetCount() != count)
        rows.Resize(count);

    for (int index = 0; index < count; ++index)
    {
        HeadInfo &row = *rows.GetAtOrDefault(index);
        if (!file.ReadEncodedTableInt(&row.frameIndex))
            g_imageLibraryLoadErrorFlag = true;
        if (!file.ReadEncodedTableInt(&row.offsetX))
            g_imageLibraryLoadErrorFlag = true;
        if (!file.ReadEncodedTableInt(&row.offsetY))
            g_imageLibraryLoadErrorFlag = true;
    }
}

// UID:0004DL | by-memory/0x004e6c50-0x004e6de4.HumanImageLibLoadRecordBlockTable.md | Completion:91 | Confidence:92
static void LoadHumanWeaponInfoTable(ProtectedArray<WeaponInfo> &rows,
                                     DATFile &file,
                                     const char *sourceName)
{
    (void)sourceName;
    rows.GetDefaultEntry().frameIndex = -1;
    rows.GetDefaultEntry().offsetX = -1;
    rows.GetDefaultEntry().offsetY = 0;

    int count = -1;
    if (!file.ReadEncodedTableInt(&count))
        g_imageLibraryLoadErrorFlag = true;
    if (count > 0 && rows.GetCount() != count)
        rows.Resize(count);

    for (int index = 0; index < count; ++index)
    {
        WeaponInfo &row = *rows.GetAtOrDefault(index);
        int packedDrawOrder = 0;
        if (!file.ReadEncodedTableInt(&row.frameIndex))
            g_imageLibraryLoadErrorFlag = true;
        if (!file.ReadEncodedTableInt(&row.offsetX))
            g_imageLibraryLoadErrorFlag = true;
        if (!file.ReadEncodedTableInt(&row.offsetY))
            g_imageLibraryLoadErrorFlag = true;
        if (!file.ReadEncodedTableInt(&packedDrawOrder))
            g_imageLibraryLoadErrorFlag = true;
        row.packedDrawOrder =
            (static_cast<unsigned int>(packedDrawOrder) << 16) |
            (static_cast<unsigned int>(packedDrawOrder) >> 16);
    }
}
