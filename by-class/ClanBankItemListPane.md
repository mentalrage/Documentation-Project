*** UID:000025 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct Rect;

struct ClanBankItemEntry
{
    unsigned char slotIndex;
    unsigned char reserved;
    unsigned short itemId;
    wchar_t displayName[256];
    unsigned int count;
    unsigned int flags;
};

class ClanBankItemListPane : public ListPane
{
public:
    explicit ClanBankItemListPane(const unsigned char *packet);
    virtual ~ClanBankItemListPane();

protected:
    virtual void DrawListEntry(int rowIndex, const ClanBankItemEntry *entry, const Rect *bounds);

private:
    void ClearSlotCache();
    void RebuildVisibleRows();
    ClanBankItemEntry m_entries[256];
    int m_visibleRowCount;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ClanBankItemListPane

## Status

- Confidence: strong for constructor/parser, draw, destructor, vtable anchors, and ClanBank ownership; medium for final entry-struct field names and exact original virtual method names.
- Likely source file: [UID:0000I9][ClanBank](by-file/ClanBank.md)
- Documented source grouping: [UID:0000I9][ClanBank](by-file/ClanBank.md), with a possible `ClanItemDialogs.cpp` companion split.
- 2026-06-15 live IDA status: current `NexusTK.exe` session reconfirms constructor/parser `sub_48B8C0` size `0x774`, row renderer `sub_48C040` size `0x211`, scalar deleting destructor `sub_48C3D0` size `0x3b`, unique signature for `0x0048b8c0-0x0048c251`, the single constructor caller from [UID:000026][ClanBankPane](by-class/ClanBankPane.md), vtable-only draw/destructor anchors, and the expected packet/text-render callee set.

## Class Purpose

`ClanBankItemListPane` parses clan bank inventory packets and renders bank item rows. It caches up to 255 slots, handles full-list, remove-slot, and update packet variants, sorts by display name for full lists, adds list entries, and draws each row with the item icon, display name, and count suffix.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ClanBankItemListPane` | `0x0048b8c0-0x0048c034` | Initializes the list pane, installs vtables, clears 255 entry slots, decodes bank packet cases `10`, `15`, and `16`, converts names to wide text, sorts full-list rows, and adds active entries. |
| `DrawListEntry` | `0x0048c040-0x0048c251` | Vtable-reached row renderer; draws selected background, item glyph, count-suffixed row text, and width-limited name. |
| destructor/thunks | `0x0048c2a7`, `0x0048c2b2`, `0x0048c3d0-0x0048c40b` | Secondary/tertiary adjustor thunks and scalar deleting destructor wrapper; the destructor calls list cleanup, optional free, and guarded delete paths. |
| `AppendEntryString` outlier | Metadata address `0x00430041`; IDA function [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md) | Generic string/vector append helper, not class-owned under current evidence. |
| excluded outlier | Metadata address `0x004c0043`; IDA containing function `0x004bee40-0x004c069d` | Excluded SIMD bit helper, not clan-bank behavior. |

## Evidence Notes

- IDA confirms the real local starts at `0x0048b8c0`, `0x0048c040`, and `0x0048c3d0`.
- 2026-05-27 boundary pass reports constructor/list parser end `0x0048c034` and `DrawListEntry` end `0x0048c251`; byte `0x0048c250` is the final immediate byte of `retn 0Ch`.
- IDA resolves `0x00430041` inside the modeled function at `0x00430040`, and current evidence points to a generic append helper rather than a clan-bank list method. The same enclosing helper also contains the false `ExchangeMoneyEditControlPane::GetClassName` start at `0x00430058`.
- IDA resolves `0x004c0043` inside `0x004bee40`, a large unrelated bit-manipulation function. Keep that out of clan migration.
- 2026-06-05 live IDA MCP `lookup_funcs` reports modeled functions at `0x0048b8c0` size `0x774`, `0x0048c040` size `0x211`, and `0x0048c3d0` size `0x3b`; the metadata outliers still resolve to containing functions at `0x00430040` and `0x004bee40`.
- `callers`/`xrefs_to` reports the constructor is called only from [UID:00010R][0x0048b1c0-0x0048b7dc.ClanBankPane](by-memory/0x0048b1c0-0x0048b7dc.ClanBankPane.md) at `0x0048b45b`; `DrawListEntry` is vtable-reached at `0x0061639c`; the destructor is reached from adjustor thunks `0x0048c2a7` and `0x0048c2b2` plus vtable data `0x0061631c`.
- Constructor decompilation installs three `ClanBankItemListPane` vtables at `0x0048b92b`, `0x0048b931`, and `0x0048b93b`, clears 255 entry records, handles packet case `10` as a full-list rebuild with bubble-sort by wide display name, case `15` as a slot clear, and case `16` as an update list, then iterates slot IDs `1..255` to add each active row and update the visible count.
- Draw decompilation uses the selected-row test, item image draw helpers, [UID:00016B][0x004ba820-0x004ba991.TextFitAndSuffixHelpers](by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md) for ellipsis fitting, and formats count suffixes as `"%s (%d)"` only when the entry count is greater than one.
- 2026-06-15 live IDA recheck:
  - `lookup_funcs` reports `sub_48B8C0` size `0x774`, `sub_48C040` size `0x211`, and `sub_48C3D0` size `0x3b`.
  - `make_signature_for_range 0x0048b8c0-0x0048c251` returns `unique:true`.
  - `xrefs_to` reports one constructor code xref at `0x0048b45b` from [UID:000026][ClanBankPane](by-class/ClanBankPane.md), draw handler vtable anchor `0x0061639c`, destructor thunk refs at `0x0048c2ad`/`0x0048c2b8`, and destructor vtable anchor `0x0061631c`.
  - `analyze_component` reports constructor parser complexity 21 with packet/string/list callees, draw complexity 4 with text fitting/GrafPort/glyph callees, and destructor complexity 2 with list cleanup/delete helpers.
- 2026-06-22 B014 destructor-band recheck corrects the scalar-deleting destructor wrapper endpoint to `0x0048c3d0-0x0048c40b`; the `0x0048c2a7`/`0x0048c2b2` thunks remain generated ABI support.

## Score Rationale

Completion is now above the low-score queue because the class page records current function sizes, unique class-range signature, constructor-only parent caller, vtable anchors, packet cases `10/15/16`, full-list sorting, row rebuild, row drawing/text fitting, destructor route, and outlier rejection. Confidence is strong for ClanBank ownership and behavior, but remains below final-source quality because the entry-record field names, local names, and exact virtual method names are still provisional.

## Cross-References

- [UID:0000I9][ClanBank](by-file/ClanBank.md)
- [UID:00010S][0x0048b8c0-0x0048c251.ClanBankItemListPane](by-memory/0x0048b8c0-0x0048c251.ClanBankItemListPane.md)
- [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md)
- [UID:00010T][0x0048c260-0x0048c63f.ClanDestructorBand](by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md)
- [UID:000026][ClanBankPane](by-class/ClanBankPane.md)
- [UID:00010R][0x0048b1c0-0x0048b7dc.ClanBankPane](by-memory/0x0048b1c0-0x0048b7dc.ClanBankPane.md)
- [UID:0002MO][0x00615fd8-0x006163dc.ClanBankVtableData](by-memory/0x00615fd8-0x006163dc.ClanBankVtableData.md)
- [UID:00016B][0x004ba820-0x004ba991.TextFitAndSuffixHelpers](by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md)

## Changes

- 2026-06-30 B009 empty-emitter implementation callback: inserted the accepted declaration-level `ClanBankItemListPane` shell, `ClanBankItemEntry` row type, `ClearSlotCache`/`RebuildVisibleRows` prototypes, and `[[CHILDREN]]`; set `EMITTER_POSITION_OPTIONAL:0` and raised score to `87/90`. The row-field names remain best-current inferred source names from parser/draw offsets and are a confidence cap, not a blocker.
- 2026-05-27: Corrected local method ends from `0x0048c033`/`0x0048c250` to exclusive ends `0x0048c034`/`0x0048c251`. Evidence: IDA MCP reports the constructor/parser at `0x0048b8c0-0x0048c034` and draw handler at `0x0048c040-0x0048c251`.
- What existed before: the page documented clan-bank inventory parsing/drawing and outlier method exclusions, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `76/80`.
- Summary and evidence: constructor/parser, draw method, destructor band, packet cases, sorting/rendering behavior, and wrong-owner outliers are documented; exact entry struct layout and final field names still need deeper work.
- 2026-06-05: Initially marked reconstructable but left `AUTOGEN_PARENT_UID` blank because the class was still `76/80`, below the 80/80 parent-attachment gate, even though [UID:0000I9][ClanBank](by-file/ClanBank.md) was the likely owner. Live IDA MCP `lookup_funcs` confirmed exact starts at `0x0048b8c0`, `0x0048c040`, `0x0048c2a7`, `0x0048c2b2`, and `0x0048c3d0`; the same check preserved the documented metadata outlier caveats for `0x00430041` and `0x004c0043`.
- 2026-06-05: Raised scores to `82/86` and attached parent [UID:0000I9][ClanBank](by-file/ClanBank.md) after live IDA MCP decompilation/caller/callee/xref review documented the constructor's slot initialization, packet cases `10/15/16`, full-list sort, row-count rebuild, vtable anchors, only constructor caller from [UID:00010R][0x0048b1c0-0x0048b7dc.ClanBankPane](by-memory/0x0048b1c0-0x0048b7dc.ClanBankPane.md), draw-handler vtable data, and destructor thunk path. Final C++ remains blank because entry field names, local names, and exact virtual names are still not final.
- 2026-06-05: Removed stale recovered-source and generated-helper wording while preserving the `82/86` score.
- 2026-06-15 A002 Goal 2 by-class refresh: raised to `86/89` after live IDA reconfirmed exact constructor/draw/destructor sizes, unique class-range signature, only constructor caller from ClanBankPane, draw/destructor vtable anchors, destructor thunk refs, packet/parser and draw callee sets, and the outlier exclusions. Owner/emitter route remains [UID:0000I9][ClanBank](by-file/ClanBank.md); final C++ remains blank pending source-quality entry fields and virtual names.
- 2026-06-22 B014 Rule 26 support sync: corrected the destructor wrapper half-open range to `0x0048c3d0-0x0048c40b`; scores and owner/emitter are unchanged.
