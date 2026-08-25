*** UID:00007M | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../controls/ListPane.h"

class GrafPort;
struct RectBounds;

struct MailListEntryRow {
    unsigned short mailId;
    unsigned char unread;
    unsigned char month;
    unsigned char day;
    unsigned char reserved;
    wchar_t sender[256];
    wchar_t subject[256];
};

class MailListPane : public ListPane {
public:
    MailListPane(short height, unsigned short mailListId);
    void AddOrUpdateMailEntry(unsigned char unread, unsigned short mailId,
                              const wchar_t *sender, unsigned char month,
                              unsigned char day, const wchar_t *subject);
    void RequestSelectedMailAndMarkRead();
    void SendDeleteRequestsForSelectedMail();
    void RemoveMailEntryById(unsigned short mailId);
    void RemoveSelectedMailEntries();
    void RequestInitialMailPage();
    void RequestOlderMailIfNeeded();
    int FindMailIdIndex(unsigned short mailId) const;
    unsigned short GetMailListId() const { return m_mailListId; }
    void SetPageRequestPending(bool pending) {
        m_pageRequestPending = pending ? 1 : 0;
    }
    virtual bool OnScrollChanged(int delta);
    virtual bool OnItemSelected(unsigned int index);
    virtual int RequestSelectedMail();
    virtual void DrawEntry(GrafPort &port, unsigned int index,
                           const MailListEntryRow &row,
                           const RectBounds &bounds);

private:
    unsigned short m_mailListId;
    unsigned char m_pageRequestPending;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MailListPane

## Status

- Confidence: very strong for behavior, row layout, mail-dialog placement, vtable routing, all thirteen class bodies, three file-local request bodies, and complete formal H/CPP routing. Exact historical lexical spellings remain the sub-95 cap.
- Likely source file: [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- Address range: [UID:0003PV][0x0047a8a0-0x0047b21f.MailListPaneCore](by-memory/0x0047a8a0-0x0047b21f.MailListPaneCore.md) inside [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md).
- Current recovered file: `source-3/simroot_v2/class_MailListPane.cpp`; treat generated and re-agent snippets only as lead evidence because they omit helper pockets and expose subobject/type artifacts.
- Parent routing: assigned to [UID:0000KZ][MailDialogs](by-file/MailDialogs.md). The class has a stable file owner/emitter and now emits a declaration shell with exact method bodies carried by [UID:0003PV][0x0047a8a0-0x0047b21f.MailListPaneCore](by-memory/0x0047a8a0-0x0047b21f.MailListPaneCore.md).

## Class Purpose

`MailListPane` is the list component owned by `MailListDialog`. The dialog reaches this pane through child/control id `7`, not through a proven direct `MailListPane *` member field. It stores `0x406`-byte mail list row records, draws mail id/sender/date/subject columns, tracks whether another list-page request is pending, requests older mail when scrolling or selection reaches the end, and provides local mail read/delete/remove helpers for selected rows.

## Source Layout

| Offset | Source-facing name | Type | Evidence |
| --- | --- | --- | --- |
| inherited | `ListPane` base | `ListPane` | Constructor calls the base with row size `0x406`, flags/style `0x1000`, caller-provided height, row height `14`, and final flags `0, 1, 1`. |
| `+0x14c` | `m_mailListId` | `unsigned short` | Constructor stores argument 2; page/read/delete packets serialize this value immediately after opcode/subopcode as the mailbox/list selector. Historical `m_mailType` is retained only as a superseded descriptive alias. |
| `+0x14e` | `m_pageRequestPending` | `unsigned char` / bool | Constructor clears it, `RequestOlderMailIfNeeded` sets it after queueing a page request, and scroll/selection virtuals guard lazy-load dispatch on it through the adjusted secondary view. |

The exact row declaration is emitted only in the formal H channel above. Its physical layout is `mailId +0x000`, unread byte `+0x002`, month `+0x003`, day `+0x004`, reserved byte `+0x005`, sender wide buffer `+0x006`, and subject wide buffer `+0x206`, total `0x406` bytes.

The `sender`/`subject` names are high-probability source names from packet order and draw columns. If later UI-resource evidence proves the captions were swapped, only the field names should change; the offsets, field widths, and draw positions stay proven.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `MailListPane` | `0x0047a8a0-0x0047a8f9` | Initializes the `ListPane` base with row size `0x406`, stores `m_mailListId`, installs the three compiler vtable views, and clears `m_pageRequestPending`. |
| `AddOrUpdateMailEntry` | `0x0047a900-0x0047a9de` | Builds a stack `MailListEntryRow`, copies two bounded 256-wide-character text fields, removes any existing row with the same mail id, scans current rows, rejects a duplicate found during the scan, and inserts in descending mail-id order. |
| `RequestSelectedMailAndMarkRead` | `0x0047a9e0-0x0047aa8d` | No-direct-route helper pocket. Fetches the selected row, clears its unread state, and sends opcode `0x3b` subopcode `0x03` with `m_mailListId` and `mailId`; local trailing zero is stack hygiene, not a sent protocol byte. |
| `SendDeleteRequestsForSelectedMail` | `0x0047aa90-0x0047ab66` | No-direct-route helper pocket. Iterates selected row indices and sends one opcode `0x3b` subopcode `0x05` delete packet per selected `mailId`; send length is `6`. |
| `RemoveMailEntryById` | `0x0047ab70-0x0047ab90` | No-direct-route helper pocket. Calls `FindMailIdIndex(mailId)` and removes exactly one row when found. |
| `RemoveSelectedMailEntries` | `0x0047aba0-0x0047abfa` | No-direct-route helper pocket. Removes selected rows while compensating each later index for prior removals. |
| `RequestInitialMailPage` | `0x0047ac00-0x0047ac27` | No-direct-route wrapper that calls the file-local page request helper with `m_mailListId`, top page id `0x7fff`, and the current layout offset. |
| `RequestOlderMailIfNeeded` | `0x0047ac30-0x0047ac88` | Uses the last row id minus one as the upper-bound mail id; empty lists use `0x7fff`. Sends a page request through `SendMailListPageRequest` and sets `m_pageRequestPending`. |
| `FindMailIdIndex` | `0x0047acd0-0x0047ad13` | Linear search over list rows by `mailId`, returning the row index or `-1`. B009 confirms [UID:00007J][MailDeleteReplyAlert](by-class/MailDeleteReplyAlert.md) also calls this helper on the reply-list child in the single-delete path, using `MailDialog+0x274` as the searched reply id; keep the global helper name mail-id oriented because the same body serves mail-list semantics. |
| `OnScrollChanged` | `0x0047ad80-0x0047add5` | Vtable-only secondary-view handler. Calls the base scroll handler, checks end-of-scroll state, adjusts the receiver by `-0xa0`, and triggers lazy load if no request is pending. |
| `OnItemSelected` | `0x0047ade0-0x0047ae29` | Vtable-only secondary-view handler. Calls the base selection handler, checks whether the final row is selected, adjusts the receiver by `-0xa0`, and triggers lazy load if no request is pending. |
| `RequestSelectedMail` | `0x0047ae30-0x0047ae43` | Vtable-routed selected-mail open/request helper. The old `GetSelectedMailId` name is rejected because the body performs owner/parent virtual lookups and tail-calls the [UID:00007L][MailListDialog](by-class/MailListDialog.md) request helper at `0x00479d30`. |
| `DrawEntry` | `0x0047ae50-0x0047b071` | Vtable-routed row renderer. Applies selection/unread coloring, formats `%5d` mail id and `%2d/%2d` date strings, truncates text with `...`, and draws id/sender/date/subject at x offsets `0`, `35`, `110`, and `150`. |
| `SendMailListPageRequest` | `0x0047b080-0x0047b110` | File-local `MailDialogs.cpp` helper, not class-exclusive. Builds a 7-byte opcode `0x3b` subopcode `0x02` page request from `mailType`, `upperBoundMailId`, and layout offset. |
| `SendMailReadRequest` | `0x0047b110-0x0047b19b` | Retained complete file-local read-request body with zero direct xrefs; the old child endpoint cut through its first byte. |
| `SendMailDeleteRequest` | `0x0047b1a0-0x0047b21d` | Retained complete file-local delete-request body with zero direct xrefs; included before corrected endpoint `0x0047b21f`. |

## Packet And Helper Details

- `SendMailListPageRequest` is shared by MailDialogs-family callers and remains a file-local helper in `MailDialogs.cpp` instead of a `MailListPane` member. The proven direct callsite/containing-entry pairs are `0x0047a056`<-`0x0047a020`, `0x0047ac21`<-`0x0047ac00`, `0x0047ac7a`<-`0x0047ac30`, `0x0047d812`<-`0x0047d7d0`, and `0x0047e0e1`<-`0x0047e090`. Entries `0x0047a020`, `0x0047ac00`, and `0x0047d7d0` are retained raw source-shaped bodies without current modeled function objects; entries `0x0047ac30` and `0x0047e090` are modeled functions.
- The older six-address PE/Capstone result is superseded, not a second direct-call inventory: `0x0047a50c` is an interior operand byte of the unrelated instruction headed at `0x0047a508`; `0x0047a539` is an interior byte of the unrelated instruction headed at `0x0047a538`; `0x0047ac1a` is a `push eax` setup instruction before direct call `0x0047ac21`; `0x0047ac72` is inside the `lea` instruction headed at `0x0047ac6e` before direct call `0x0047ac7a`; `0x0047c3cc` is an interior operand byte of the unrelated instruction headed at `0x0047c3c8`; and `0x0047e0f2` is an interior byte of the unrelated instruction headed at `0x0047e0ef`. None is itself a direct call to `0x0047b080` or a containing-entry identity.
- The page request packet is exactly seven bytes: `0x3b`, `0x02`, big-endian `mailType`, big-endian `upperBoundMailId`, and one signed layout-offset byte. `g_useEpfAssets == 1` uses `-20` (`0xec`); the alternate layout uses `-16` (`0xf0`).
- Selected read/open sends seven bytes: `0x3b`, `0x03`, big-endian `m_mailListId`, and big-endian selected `mailId`. The helper also clears the row's unread state.
- Selected delete sends six bytes: `0x3b`, `0x05`, big-endian `m_mailListId`, and big-endian selected `mailId`. Do not model the local zero after the payload as a protocol byte.
- The five helper pockets at `0x0047a9e0`, `0x0047aa90`, `0x0047ab70`, `0x0047aba0`, and `0x0047ac00` have no direct `call rel32` references and no dword pointer references in the local `.text` scan. They are source-shaped bodies that operate on this class's row state, so they are retained as no-direct-route helpers instead of discarded as padding or compiler residue.

## Vtable Evidence

- Constructor stores the primary, secondary, and tertiary `MailListPane` vtable views `0x006142d8`, `0x00614360`, and `0x00614390` at `0x0047a8d1`, `0x0047a8d7`, and `0x0047a8e1`.
- Dword references identify key slots: `0x00614364 -> 0x0047ad80`, `0x00614368 -> 0x0047ade0`, `0x00614354 -> 0x0047ae30`, and `0x00614358 -> 0x0047ae50`.
- The scroll and selection handlers are reached through the secondary subobject view. Source should express this as normal virtual overrides on `MailListPane`; do not expose fake `this - 0xa0` or `ownerPane_0xA0` fields.

## C++ Readiness

This is not a no-code class. The owner/emitter route is stable, the row layout and local method island are source-shaped, and [UID:0003PV][0x0047a8a0-0x0047b21f.MailListPaneCore](by-memory/0x0047a8a0-0x0047b21f.MailListPaneCore.md) carries first-draft method C++ for the exact range. The class page emits a declaration shell with `[[CHILDREN]]` so the exact memory child can carry method bodies.

Current source caveats:

- Exact source spellings for `MailListEntryRow`, `m_mailListId`, `m_pageRequestPending`, `GetItemAt`, `GetPrimarySelectedIndex`, and text-fit helpers are high-probability names, not recovered source text.
- `OnScrollChanged`, `OnItemSelected`, `RequestSelectedMail`, and `DrawEntry` are declared in formal H and implemented by the accepted [UID:0003PV][0x0047a8a0-0x0047b21f.MailListPaneCore](by-memory/0x0047a8a0-0x0047b21f.MailListPaneCore.md) formal CPP payload; current signatures preserve the observed physical behavior and project API conventions.
- Do not emit constructor vtable stores. They are compiler artifacts.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `94` | The page records the exact row layout, normalized fields, all thirteen class bodies, three file-local request bodies, sorted insertion/removal, page/read/delete packets, vtable routes, complete formal H, and child CPP route. |
| Confidence `94` | Current whole-file live-MCP/physical evidence agrees on every boundary, vtable ref, packet role, row offset, range correction, owner, and source route. Exact original lexical spellings remain inferred. |

## Cross-References

- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md)
- [UID:0003PV][0x0047a8a0-0x0047b21f.MailListPaneCore](by-memory/0x0047a8a0-0x0047b21f.MailListPaneCore.md)
- [UID:000321][MailDialogCoreVtables](by-type/by-vtable/MailDialogCoreVtables.md)
- [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md)
- [UID:00007L][MailListDialog](by-class/MailListDialog.md)
- [UID:00007K][MailDialog](by-class/MailDialog.md)

## Changes

- 2026-08-11 Agent-B002 UID0000KZ whole-file implementation callback:
  - Raised `88/88` to `94/94`, moved the complete declaration from formal CPP to formal H, left `[[CHILDREN]]` in formal CPP, and normalized the active field name to `m_mailListId`.
  - Corrected the child link/range to `0x0047a8a0-0x0047b21f`, added the two retained file-local request bodies, and preserved the old range/`m_mailType` spellings as superseded history.
  - Current live-MCP whole-file evidence supersedes the historical MCP-unavailable confidence cap while preserving its provenance.

- 2026-06-21 supervisor-worker Rule 26 incorporation of B009 `00007J-MailDeleteReplyAlert-class-source-quality.md`: no score change. Added the single-reply delete-alert cross-reference for `FindMailIdIndex` while rejecting a global rename to reply-only wording.
- 2026-06-20 supervisor-worker Rule 26 incorporation of B007 `00007L-MailListDialog-class-source-quality.md`:
  - Added the `m_mailListId` preferred packet-prose alias for the existing `m_mailType` field, recorded the MailListDialog child/control id `7` dependency, and cross-synced shared page-request helper call-site neighborhoods without changing this page's score or first-draft C++.
- 2026-06-20 supervisor Rule 26 incorporation of B002 `00007M-MailListPane-class-source-quality.md`:
  - Changed score from `85/86` to `88/88`.
  - Added declaration-level first-draft C++ with `MailListEntryRow`, `MailListPane` method declarations, fields `m_mailType` and `m_pageRequestPending`, and `[[CHILDREN]]`.
  - Replaced the stale "compact nine-function" model with nine documented functions plus five source-shaped no-direct-route helper pockets.
  - Corrected lazy paging from "current first row" to last row id minus one; empty lists use `0x7fff`.
  - Documented row layout, packet layouts, shared file-local page helper `0x0047b080`, vtable-only routes, rejected `GetSelectedMailId` name, and C++ readiness/caveats.
- 2026-06-08 A009 Batch 125:
  - Changed score from `78/82` to `85/86`.
  - Set `AUTOGEN_PARENT_UID:0000KZ` because this page and the direct [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) parent both satisfy the corrected `85/85` gate.
  - Added live IDA MCP evidence for all nine local functions/helpers, constructor/list-update callers, three vtable stores, key virtual-slot data refs, sorted row insertion, lazy-page request behavior, and row drawing.
- 2026-06-05: Marked reconstructable because live IDA MCP confirms the mail list pane constructor, scroll/selection helpers, selected-mail lookup, and row draw function are NexusTK-owned UI/mail behavior. Live IDA MCP evidence: `lookup_funcs` confirms starts at `0x0047a8a0`, `0x0047ad80`, `0x0047ade0`, `0x0047ae30`, and `0x0047ae50`; `callers` confirms the constructor is called from `0x00479273` and `0x00479815` inside `sub_479110`.
