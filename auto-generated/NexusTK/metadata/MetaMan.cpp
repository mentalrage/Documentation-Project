// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LC
// Source by-file doc: by-file/MetaMan.md
// UID:000088 | by-class/MetaMan.md | Completion:94 | Confidence:94
#include "MetaMan.h"

// UID:00023A | by-memory/0x00524590-0x005245b1.MetaManNodeDestroyHelper.md | Completion:89 | Confidence:91
// Emitted code for this range is covered by [UID:000088][MetaMan](by-class/MetaMan.md).

// UID:000089 | by-class/MetaTable.md | Completion:94 | Confidence:93
// UID:0001CB | by-memory/0x00524630-0x00525914.MetaTable.md | Completion:88 | Confidence:90
// MetaTable aggregate output is intentionally carried by exact class/helper children.
// This range contains MetaTable constructor/destructor/decode/reset methods, the
// materializer [UID:0001CC][0x00524870-0x00524c55.MetaTableMaterializeRows](by-memory/0x00524870-0x00524c55.MetaTableMaterializeRows.md), and row-tree helper island [UID:0001CD][0x00524d10-0x00525914.MetaTableRowTreeHelpers](by-memory/0x00524d10-0x00525914.MetaTableRowTreeHelpers.md). Do not emit
// one broad duplicate body from the aggregate page.
[[No Children Attached]]

// UID:0001CC | by-memory/0x00524870-0x00524c55.MetaTableMaterializeRows.md | Completion:90 | Confidence:92
void MetaTable::MaterializeRowsIfNeeded(const wchar_t *tableNameHint)
{
    SimpleUString rowKey;
    SimpleUString valueText;
    char multiByteText[0x8000];
    wchar_t wideText[0x8000];

    (void)tableNameHint;

    if (m_keyData == NULL)
        return;

    const unsigned char *payload = m_keyData;
    unsigned int byteOffset = 2;
    const unsigned int rowCount = PacketBufferReadUInt16BE(payload);

    for (unsigned int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
        const unsigned int keyByteLength = payload[byteOffset++];
        memmove(multiByteText, payload + byteOffset, keyByteLength);
        multiByteText[keyByteLength] = '\0';
        byteOffset += keyByteLength;

        unsigned int wideLength = (unsigned short)MultiByteToWideChar(
            CP_ACP,
            0,
            multiByteText,
            keyByteLength,
            wideText,
            0x8000);

        if (wideLength >= 0x8000)
            __report_rangecheckfailure();

        wideText[wideLength] = L'\0';
        rowKey.Assign(wideText);

        const unsigned int valueCount = PacketBufferReadUInt16BE(payload + byteOffset);
        byteOffset += 2;

        for (unsigned int valueIndex = 0; valueIndex < valueCount; ++valueIndex) {
            const int valueByteLength =
                static_cast<short>(PacketBufferReadUInt16BE(payload + byteOffset));
            byteOffset += 2;

            memmove(multiByteText, payload + byteOffset, valueByteLength);
            byteOffset += valueByteLength;

            if (static_cast<unsigned int>(valueByteLength) >= 0x8000)
                __report_rangecheckfailure();

            multiByteText[valueByteLength] = '\0';

            wideLength = (unsigned short)MultiByteToWideChar(
                CP_ACP,
                0,
                multiByteText,
                valueByteLength,
                wideText,
                0x8000);

            if (wideLength >= 0x8000)
                __report_rangecheckfailure();

            wideText[wideLength] = L'\0';
            valueText.Assign(wideText);

            m_rows[rowKey].push_back(valueText);
        }
    }

    free(m_keyData);
    m_keyData = NULL;
    m_keyDataSize = 0;
    m_isLoaded = true;
}

// UID:0001CD | by-memory/0x00524d10-0x00525914.MetaTableRowTreeHelpers.md | Completion:87 | Confidence:91
// MetaTableRowTreeHelpers is old MSVC map/vector support for MetaTable::m_rows.
// Source-facing output is the MetaTable declaration, MetaTableRowNode layout,
// MetaTableRowFindByKey helper, and materializer row-map use; do not hand-emit
// raw tree rebalancing, vector growth, cleanup thunk, or scalar deleting helpers here.


// UID:0001V6 | by-type/by-struct/MetaTableDecodedPayload.md | Completion:87 | Confidence:90
// MetaTableDecodedPayload is a variable-length decoded byte format parsed by
// MetaTable::MaterializeRowsIfNeeded. It is not emitted as a standalone C++
// struct: the source parser reads uint16be row/value fields, uint8 key lengths,
// and variable key/value byte spans directly from MetaTable::m_keyData.

// UID:0001V7 | by-type/by-struct/MetaTableRowNode.md | Completion:88 | Confidence:90
struct MetaTableRowNode
{
    MetaTableRowNode *left;
    MetaTableRowNode *parent;
    MetaTableRowNode *right;
    unsigned char colorOrRedBlackFlag;
    unsigned char isSentinelOrNil;
    unsigned short paddingOrFlags;
    SimpleUString key;
    SimpleUString *valuesBegin;
    SimpleUString *valuesEnd;
    SimpleUString *valuesCapacity;
};

// UID:0000Q2 | by-global/g_metaAliasTableName.md | Completion:88 | Confidence:89
SimpleUString g_metaAliasTableName;

// UID:0000RL | by-global/g_pMetaMan.md | Completion:89 | Confidence:90
MetaMan *g_pMetaMan = 0;

// UID:0001C8 | by-memory/0x005227d0-0x00524581.MetaMan.md | Completion:89 | Confidence:90
// MetaMan aggregate output is carried by the MetaMan class declaration, exact
// globals, direct lookup helpers, and future exact method children. This broad
// range mixes methods, unmodeled retained helpers, a tail thunk, scalar deleting
// destructor glue, and old MSVC map support; do not emit one duplicate aggregate body.
[[No Children Attached]]

// UID:0001C9 | by-memory/0x00523a00-0x00523c99.MetaManLookupHelpers.md | Completion:90 | Confidence:91
static unsigned int MetaMan_GetDirectRowValueCount(MetaMan *metaMan,
                                                   const SimpleUString *tableName,
                                                   const SimpleUString *rowKey)
{
    MetaTable *table = metaMan->FindTableByName(tableName);
    if (table == NULL)
        return 0;

    if (!table->m_isLoaded)
        table->MaterializeRowsIfNeeded(tableName->c_str());

    MetaTableRowNode *row = NULL;
    MetaTableRowFindByKey(&row, table->m_rowTreeHeader, rowKey);
    if (row == table->m_rowTreeHeader)
        return 0;

    return static_cast<unsigned int>(row->valuesEnd - row->valuesBegin);
}

static const SimpleUString *MetaMan_FindDirectRowValue(MetaMan *metaMan,
                                                       const SimpleUString *tableName,
                                                       const SimpleUString *rowKey,
                                                       unsigned int valueIndex)
{
    MetaTable *table = metaMan->FindTableByName(tableName);
    if (table == NULL)
        return &g_emptySimpleUString;

    if (!table->m_isLoaded)
        table->MaterializeRowsIfNeeded(tableName->c_str());

    MetaTableRowNode *row = NULL;
    MetaTableRowFindByKey(&row, table->m_rowTreeHeader, rowKey);
    if (row == table->m_rowTreeHeader)
        return &g_emptySimpleUString;

    const unsigned int valueCount =
        static_cast<unsigned int>(row->valuesEnd - row->valuesBegin);
    if (valueIndex >= valueCount)
        return &g_emptySimpleUString;

    return row->valuesBegin + valueIndex;
}

static const SimpleUString *MetaMan_CopyDirectRowValues(MetaMan *metaMan,
                                                        const SimpleUString *tableName,
                                                        const SimpleUString *rowKey,
                                                        wchar_t ***outValues,
                                                        int requestedCount)
{
    wchar_t **values = static_cast<wchar_t **>(operator new(sizeof(wchar_t *) * requestedCount));
    for (int i = 0; i < requestedCount; ++i)
    {
        values[i] = static_cast<wchar_t *>(operator new(0x50));
        values[i][0] = L'\0';
    }
    *outValues = values;

    MetaTable *table = metaMan->FindTableByName(tableName);
    if (table == NULL)
        return &g_emptySimpleUString;

    if (!table->m_isLoaded)
        table->MaterializeRowsIfNeeded(tableName->c_str());

    MetaTableRowNode *row = NULL;
    MetaTableRowFindByKey(&row, table->m_rowTreeHeader, rowKey);
    if (row == table->m_rowTreeHeader)
        return &g_emptySimpleUString;

    const unsigned int availableCount =
        static_cast<unsigned int>(row->valuesEnd - row->valuesBegin);
    const unsigned int copyCount =
        availableCount < static_cast<unsigned int>(requestedCount)
            ? availableCount
            : static_cast<unsigned int>(requestedCount);

    for (unsigned int i = 0; i < copyCount; ++i)
        wcscpy_s(values[i], 0x28, row->valuesBegin[i].c_str());

    return row->valuesBegin;
}

// UID:0001CA | by-memory/0x005245c0-0x0052462a.MetaTableRowFindByKey.md | Completion:88 | Confidence:90
static MetaTableRowNode **MetaTableRowFindByKey(MetaTableRowNode **result,
                                                MetaTableRowNode *rowTreeHeader,
                                                const SimpleUString *key)
{
    MetaTableRowNode *candidate = rowTreeHeader;
    MetaTableRowNode *node = rowTreeHeader->parent;

    while (!node->isSentinelOrNil) {
        if (SimpleUStringLessThan(&node->key, key)) {
            node = node->right;
        } else {
            candidate = node;
            node = node->left;
        }
    }

    if (candidate == rowTreeHeader || SimpleUStringLessThan(key, &candidate->key)) {
        *result = rowTreeHeader;
    } else {
        *result = candidate;
    }

    return result;
}

// UID:0003PD | by-memory/0x0061fadc-0x0061faf0.MetaDatFilenameString.md | Completion:91 | Confidence:94
// Emitted source for L"Meta.dat" is covered by MetaMan::LoadMetaDat and
// MetaMan::SaveMetaDatIfDirty. The trailing empty-wide literal is covered by
// MetaTable::MaterializeRowsIfNeeded's m_rows[rowKey] insertion lowering.
// Do not emit a standalone string array or raw bytes for this pooled range.

// UID:0001OL | by-memory/0x0066de18-0x0066de30.g_metaAliasTableName.md | Completion:87 | Confidence:90
// Exact storage evidence for g_metaAliasTableName is emitted by [UID:0000Q2][g_metaAliasTableName](by-global/g_metaAliasTableName.md).
// Keep this by-memory page as the 24-byte SimpleUString layout/lifetime/xref
// proof; do not duplicate the source declaration here.

// UID:0001PJ | by-memory/0x0069b410-0x0069b414.g_pMetaMan.md | Completion:89 | Confidence:92
// Exact storage evidence for g_pMetaMan is emitted by [UID:0000RL][g_pMetaMan](by-global/g_pMetaMan.md).
// Keep this by-memory page as the four-byte singleton slot/lifecycle/xref proof;
// do not duplicate the source declaration here.

// UID:0003PE | by-memory\0x0061faf0-0x0061faf8.MetaTableVtableData.md | Completion:86 | Confidence:90 | Empty Emitter Marker
