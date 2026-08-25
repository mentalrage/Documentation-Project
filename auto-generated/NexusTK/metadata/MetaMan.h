// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LC
// Source by-file doc: by-file/MetaMan.md
// UID:000088 | by-class/MetaMan.md | Completion:94 | Confidence:94
#ifndef NEXUSTK_METADATA_METAMAN_H
#define NEXUSTK_METADATA_METAMAN_H

#include "../util/Singleton.h"
#include "../util/StringUtil.h"

#include <map>

class MetaTable;

class MetaMan : public Singleton<MetaMan>
{
public:
    MetaMan();
    virtual ~MetaMan();

    int LoadMetaDatAndRequestSync();
    bool HandleMetaPacket(const unsigned char *packet);

    unsigned int GetValueCount(const SimpleUString *tableName,
                               const SimpleUString *rowKey);
    const SimpleUString *FindEntry(const SimpleUString *tableName,
                                   const SimpleUString *rowKey,
                                   unsigned int valueIndex);
    bool LoadStatValues(const SimpleUString *tableName,
                        const SimpleUString *rowKey,
                        wchar_t ***outValues,
                        int valueCount);
    MetaTable *FindTableByName(const SimpleUString *tableName);

private:
    typedef std::map<SimpleUString, MetaTable *> TableMap;

    void ClearTables();
    void LoadMetaDat();
    void SaveMetaDatIfDirty();

    TableMap m_tables;
    unsigned int m_pendingTableRequests;
    bool m_synchronized;
    bool m_dirty;
};

extern MetaMan *g_pMetaMan;

typedef char MetaManSizeMustBe0x14[
    sizeof(MetaMan) == 0x14 ? 1 : -1];

#endif

// UID:000089 | by-class/MetaTable.md | Completion:94 | Confidence:93
#ifndef NEXUSTK_METADATA_METATABLE_H
#define NEXUSTK_METADATA_METATABLE_H

#include <map>
#include <vector>
#include "../util/StringUtil.h"

class MetaTable
{
public:
    typedef std::map<SimpleUString,
                     std::vector<SimpleUString> > RowMap;

    MetaTable();
    virtual ~MetaTable();

    bool DecompressAndValidateData(unsigned int expectedChecksum);
    void MaterializeRowsIfNeeded(const wchar_t *tableNameHint);
    void ResetData();

    const RowMap &Rows() const { return m_rows; }
    bool IsMaterialized() const { return m_isLoaded; }

private:
    unsigned int m_checksum;
    unsigned char *m_keyData;
    unsigned int m_keyDataSize;
    unsigned char *m_valueData;
    unsigned int m_valueDataSize;
    bool m_isLoaded;
    RowMap m_rows;
};

typedef char MetaTableSizeMustBe0x24[
    sizeof(MetaTable) == 0x24 ? 1 : -1];

#endif
