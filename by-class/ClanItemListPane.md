*** UID:00002G | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct Rect;

struct ClanItemListEntry
{
    unsigned char slotIndex;
    unsigned char reserved;
    unsigned short itemId;
    wchar_t displayName[256];
};

class ClanItemListPane : public ListPane
{
public:
    explicit ClanItemListPane(const unsigned char *packet);
    virtual ~ClanItemListPane();

protected:
    virtual void DrawListItem(int rowIndex, const ClanItemListEntry *entry, const Rect *bounds);

private:
    ClanItemListEntry m_entries[256];
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ClanItemListPane

## Status

- Confidence: strong for constructor, vtable, row parsing, draw, destructor evidence, and source-facing row layout; medium for final inherited ListPane API names and raw helper reachability.
- Likely source file: [UID:0000I9][ClanBank](by-file/ClanBank.md)

## Class Purpose

`ClanItemListPane` is the compact item list used by clan item deposit/withdraw dialogs. It decodes item slot records from packet data, stores active slots, adds rows for active items, and draws each row with icon-aware selection and truncated wide text.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ClanItemListPane` | `0x0048ae70-0x0048b08c` | Initializes list storage, parses packet item count/slot/item-id/name records, converts names to wide text, and adds active rows. |
| raw selected-entry helper | `0x0048b090-0x0048b09e` | Unmodeled helper-shaped island; reads the selected row state, calls the list entry accessor, and returns a byte from the selected entry. |
| `DrawListItem` | `0x0048b0a0-0x0048b1b1` | Draws selected/unselected item row, gets item glyph bounds, truncates display name, and draws wide text. |
| destructor/thunks | `0x0048c2ff`, `0x0048c30a`, `0x0048c510-0x0048c54b` | Vtable thunks and scalar deleting destructor. |
| shared text-fit helper | `0x004ba820-0x004ba8a2` | Shared GrafPort/text dependency that truncates a row label and appends an ellipsis suffix. |
| shared count-fit helper | `0x004ba8b0-0x004ba991` | Shared GrafPort/text dependency that counts visible wide characters fitting a measured width. |

## Evidence Notes

- Live IDA `py_eval` on 2026-06-04 used `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- IDA confirms modeled function ranges `0x0048ae70-0x0048b08c`, `0x0048b0a0-0x0048b1b1`, adjustor thunks `0x0048c2ff-0x0048c30a` and `0x0048c30a-0x0048c315`, scalar deleting destructor `0x0048c510-0x0048c54b`, and text helpers `0x004ba820-0x004ba8a2` / `0x004ba8b0-0x004ba991`.
- The constructor has one direct caller: `0x0048ab68` inside [UID:00002N][ClanWidItemDialog](by-class/ClanWidItemDialog.md). That caller creates the clan withdraw item list; the deposit item dialog uses [UID:00008W][MyItemListPane](by-class/MyItemListPane.md) instead.
- Constructor vtable stores are `0x0048aedb -> 0x006161bc`, `0x0048aee1 -> 0x00616244`, and `0x0048aeeb -> 0x00616274`. Primary vtable slot 32 (`0x0061623c`) points to `DrawListItem`; secondary and tertiary destructor slots point to `0x0048c2ff` and `0x0048c30a`.
- Constructor calls include list-pane initialization `0x004f3a50`, packet/string reads through `0x00516030`, `0x00575470`, `0x00575480`, `0x00516220`, `MultiByteToWideChar`, `_wcscpy_s`, and row insertion through `0x004f3c50`.
- The raw island at `0x0048b090-0x0048b09e` has no IDA function, no direct xrefs, and no loaded dword references to its start; it reads `this + 0x134`, calls `0x004f3dc0`, returns the first byte of that row payload, and is kept as non-final class evidence.
- `DrawListItem` calls row-selection and text-state helpers, the surface callback at `dword_69B3FC`, item glyph bounds at `0x004df460`, text truncation at `0x004ba820`, text cursor movement at `0x004b9600`, and wide-text drawing at `0x004bab70`; it also uses the ellipsis literal at `0x0061066c`.
- The text-fit pair remains shared support, not class-owned code. Live caller counts are 21 callers for `0x004ba820` and 4 callers for `0x004ba8b0`, and [UID:00016B][0x004ba820-0x004ba991.TextFitAndSuffixHelpers](by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md) already attaches it to GrafPort/text layout review.
- 2026-06-16 B001 source-quality recheck: source-facing row type is best modeled as `ClanItemListEntry { uint8_t slotIndex; uint8_t reservedOrPadding; uint16_t itemId; wchar_t displayName[256]; }`. The constructor's `0x204` row size, packet parse order, UTF-16 conversion, and row insertion match the draw method's item id read at row `+2`, display-name read at row `+4`, and the selected-slot helper's first-byte return.
- The selected-slot raw helper at `0x0048b090-0x0048b09e` is source-shaped and best named `ClanItemListPane::GetSelectedSlotIndexRaw` if retained, but PE VA/RVA/rel32 scans found no inbound route to the island start. [UID:00002N][ClanWidItemDialog](by-class/ClanWidItemDialog.md) is the confirmed active constructor/consumer; [UID:000029][ClanDepItemDialog](by-class/ClanDepItemDialog.md) remains related dialog-family context but uses [UID:00008W][MyItemListPane](by-class/MyItemListPane.md).
- 2026-06-15 live IDA MCP recheck on session `a003_objectlist_dispatch_20260615` confirms the modeled class anchors remain `sub_48AE70` size `0x21c`, `sub_48B0A0` size `0x111`, adjustor thunks `sub_48C2FF` / `sub_48C30A` size `0xb` each, and scalar deleting destructor `sub_48C510` size `0x3b`; `0x0048b090` still reports `Not a function`.
- The same recheck confirms `xrefs_to(0x0048ae70)` has the single constructor caller `0x0048ab68` inside `sub_48A810`, `xrefs_to(0x0048b0a0)` is the vtable data cell `0x0061623c`, and `xrefs_to(0x0048c510)` includes both tiny thunk callers plus the vtable data cell `0x006161bc`.
- `analyze_component` over `0x0048ae70`, `0x0048b0a0`, and `0x0048c510` reports stable function sizes, 9/11/3 callee counts, and no internal call-graph edge between the modeled bodies, matching the constructor/draw/destructor split. `make_signature_for_range(0x0048ae70,0x0048b1b1)` returns a unique wildcarded range signature.
- 2026-06-22 B014 destructor-band recheck keeps the existing `0x0048c510-0x0048c54b` scalar-deleting destructor endpoint and confirms `0x0048c2ff`/`0x0048c30a` as generated secondary/tertiary thunks for this class.

## Score Rationale

| Field | Value | Reason |
| --- | ---: | --- |
| Completion | 86 | Current IDA evidence now covers modeled method ranges, constructor caller, vtable data anchors, destructor thunk routing, packet row layout, raw helper byte semantics, raw helper non-function/no-route status, component shape, and a unique range signature. Remaining work is deciding whether the raw helper can be promoted into source-quality C++ and finalizing inherited ListPane API names. |
| Confidence | 89 | Confidence is strong because the live rechecks match the prior memory/file evidence, row layout, and ClanBank owner route. It remains below final-code confidence because the selected-entry raw island has no modeled function/xrefs and the shared text-fit helper names are not class-local. |

## Cross-References

- [UID:0000I9][ClanBank](by-file/ClanBank.md)
- [UID:00010Q][0x0048ae70-0x0048b1b1.ClanItemListPane](by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md)
- [UID:00010T][0x0048c260-0x0048c63f.ClanDestructorBand](by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md)
- [UID:00016B][0x004ba820-0x004ba991.TextFitAndSuffixHelpers](by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md)

## Changes

- 2026-06-30 B009 empty-emitter implementation callback: inserted the accepted declaration-level `ClanItemListPane` shell, `ClanItemListEntry` row type, and `[[CHILDREN]]`; set `EMITTER_POSITION_OPTIONAL:0` and raised score to `87/90`. The raw selected-slot helper at `0x0048b090` remains no-route/no-standalone-body and is preserved in the child method block.
- 2026-05-27: Corrected `DrawListItem` from `0x0048b0a0-0x0048b1b0` to exclusive end `0x0048b1b1`. Evidence: IDA MCP reports `sub_48B0A0` at `0x0048b0a0-0x0048b1b1`, with `retn 0Ch` occupying bytes `0x0048b1ae-0x0048b1b0`.
- Earlier baseline: the page documented item-list parsing/drawing and text-fitting helper caveats, but metadata remained unevaluated.
- Earlier scoring pass: scores were set to `72/80` because constructor/parser, draw method, destructor/thunks, and text-fitting helpers were covered; final helper ownership, entry layout, and font/global naming remained incomplete.
- 2026-06-04: Raised from `72/80` to `82/86`, marked reconstructable, and attached to [UID:0000I9][ClanBank](by-file/ClanBank.md).
  - Before: page had behavior notes but no reconstructable/parent metadata, stale recovered-file provenance, and treated the shared text-fit pair as local methods.
  - After: live IDA evidence records executable identity, exact modeled ranges, raw helper-shaped island status, constructor caller, three vtable stores, draw/destructor vtable slots, constructor parser calls, draw-time item/text helper calls, and shared text-helper caller fanout.
  - Reasoning: this is enough for reconstructable class-level documentation and parent attachment because the [UID:0000I9][ClanBank](by-file/ClanBank.md) parent is already `86/80` with a valid `NexusTK/social/` path. Completion remains below final-code range because field names, raw helper reachability, and shared text helper ownership are not final.
- 2026-06-15 A002 Goal 2 by-class refresh: raised from `82/86` to `86/89` with no owner/emitter changes. Live IDA reconfirmed modeled method sizes, one constructor caller, vtable-only draw/destructor anchors, raw helper non-function status, component summary, and unique range signature. C++ remains blank because field names, raw helper reachability, and shared text-helper source ownership are not yet source-quality.
- 2026-06-16 B001 source-quality note: validated the source-facing row type, selected-slot raw helper semantics, ClanWid/ClanDep relationship, and GrafPort-owned text-fit dependency. Class score remains `86/89`; final C++ remains blank because the raw helper has no proven inbound route and inherited ListPane API names remain inferred.
- 2026-06-22 B014 Rule 26 support sync: confirmed the destructor/thunk routing in the corrected Clan destructor band; no score or owner/emitter change.
