// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000MZ
// Source by-file doc: by-file/RankingDialog.md
// UID:0000BL | by-class/RankingCategoryRecord.md | Completion:94 | Confidence:95
#include <time.h>
#include <vector>

struct RankingUserEntry
{
    int categoryId;
    int rank;
    wchar_t name[32];
    int score;
};

class RankingCategoryRecord
{
    friend class RankingCategoryCollection;

public:
    RankingCategoryRecord()
        : m_totalRankCount(0),
          m_loadedRowsCategoryId(-1),
          m_localPlayerRank(-1),
          m_localPlayerScore(-1)
    {
    }

    short GetListIndex() const;
    int GetCategoryId() const;
    int GetStateCode() const;
    void SetListIndex(short listIndex);
    void SetCategoryId(int categoryId);
    void SetStateCode(int stateCode);
    tm GetStartTime() const;
    tm GetEndTime() const;
    const wchar_t* GetTitleText() const;
    void SetTitleText(const wchar_t *title);
    RankingUserEntry* GetUserEntryAt(int index);
    void SetStartTimeFromPackedDateTime(int packedDate, int packedTime);
    void SetEndTimeFromPackedDateTime(int packedDate, int packedTime);
    void SetTotalRankCount(int totalRankCount);
    void AppendUserEntry(const RankingUserEntry& entry);
    void ResetUserEntries();

private:
    short m_listIndex;
    int m_categoryId;
    int m_stateCode;
    tm m_startTime;
    tm m_endTime;
    wchar_t m_title[256];
    int m_totalRankCount;
    std::vector<RankingUserEntry> m_userEntries;
    int m_loadedRowsCategoryId;
    int m_localPlayerRank;
    unsigned char m_reservedLocalPlayerFooter[0x40];
    int m_localPlayerScore;
};

// UID:0000BK | by-class/RankingCategoryCollection.md | Completion:93 | Confidence:95
#include <vector>

class RankingCategoryCollection
{
public:
    RankingCategoryCollection();

    void ParseCategoryListResponse(const unsigned char *packet);
    void ParseInitialCategoryPageResponse(const unsigned char *packet);
    void ParseRankingRowsResponse(const unsigned char *packet);
    void ApplyRewardClaimStatusResponse(const unsigned char *packet);

    void SetSelectedCategoryId(int categoryId);
    int GetCount() const;
    int GetSelectedCategoryId() const;
    RankingCategoryRecord *GetSelectedRecord() const;
    RankingCategoryRecord *GetByIndex(short index) const;

private:
    std::vector<RankingCategoryRecord> m_records;
    int m_selectedCategoryId;
};
