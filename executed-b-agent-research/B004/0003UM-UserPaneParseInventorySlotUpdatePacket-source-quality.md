** TARGET-REPORT-UID:0003UM **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID0003UM UserPaneParseInventorySlotUpdatePacket Source-Quality Report

## Finalized Report / Current Recommendation

UID0003UM is now the exact source-authored `UserPane::ParseInventorySlotUpdatePacket(const unsigned char *packet)` body at `[0x005aa710,0x005aaa2c)`, with [UID:0000FQ] UserPane retained as canonical owner/emitter, [UID:0000P1] UserPane retained as the `NexusTK/ui/panels/UserPane.cpp` route, and target metadata applied at `92/94`. Destination 1 is installed byte-for-byte in the target managed block. Destination 2 is installed byte-for-byte in the shared UserPane class: it preserves B001's accepted `StartDirectionalAnimation(char direction)`, every unrelated accepted class line, and the four resolved inventory-record field names.

The exact packet contract is opcode `0x0f` dispatch payload, signed one-based slot, big-endian item id, icon style, three one-byte-length narrow strings converted to three 256-wide-character locals, quantity/count, quantity-prompt flag, current durability, protection count, and target mode. The parser consumes and converts the complete payload before checking the slot. A valid slot is `1..g_activeUserStatusPane->m_inventorySlotCount`; the selected `0x1fc`-byte record receives writes in the exact observed binary order and the function returns `false` on every path. The retained `LivingObjectPane`/spell-slot/blank-C++ statements are superseded historical provenance, not current truth.

The accepted implementation callback and all scoped validators are complete. B004 used and released short one-file leases, did not manually edit generated or manual coverage files, and performed no execute, count, probe, move, archive, or other report-lifecycle command. Report validation, execution, archive, count, and manual-coverage state remain external supervisor/validator-owned facts and are neither asserted nor directed by this artifact.

## Supporting Research

- Pre-callback assignment snapshot: `by-memory/0x005aa710-0x005aaa2c.UserPaneParseInventorySlotUpdatePacket.md`, SHA256 `C7CB808D121AB6DD45852F89B429375777E6B09A88C065ABDFF294E2754D42CB`, `6,935` bytes, `100` lines. Its then-current body and nested history were treated as hypotheses. The implemented target is now SHA256 `A330623583077DC7DA1D5714DF9E1B6ACB5B18113489CD0C9B04833CF364CE28`, `13,610` bytes, `174` lines.
- Support destinations were reread immediately before their individual edits: `by-class/UserPane.md`, `by-file/UserPane.md`, `by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md`, `by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md`, `by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md`, `by-file/LivingObjectPane.md`, and `by-memory/-ignored.md`. Verify-only globals, storage, UserStatusPane, ItemHelpPane, PacketBuffer, MemoryMan, CollectionData, clear-helper, and unrelated sibling pages were left unchanged.
- Historical generated snapshot: `auto-generated/NexusTK/ui/panels/UserPane.cpp` SHA256 `DDE87CCDC7700348665C170FF768C18909CF4636125EF77B46E3152AA3856EEA`, `64,313` bytes, `1,739` lines, header command `000000012699` at `2026-07-15 01:54:32-04:00`; its sole UID0003UM definition reproduced the pre-callback defects. B004's waited command `000000012772` completed with corrected SHA256 `6C9213AA2432BBBC54FF44936BECFA46307096E37450017638659B6E6AD41499`, `65,692` bytes, `1,776` lines, and matching header timestamp `2026-07-15T03:32:09-04:00`. A later validator-owned refresh advanced the current read-only snapshot to command `000000012773` at `2026-07-15T03:35:46-04:00`, SHA256 `5A81919A1E7AE88CB8D4ECCCCC1DF283E838BF489DC63FEEE0502E164D443222`, with the same corrected UID0003UM assertions.
- Exact old-report terms used: `UID0003UM`, `UID:0003UM`, `0x005aa710`, `0x005aaa2c`, `UserPaneParseInventorySlotUpdatePacket`, `ParseInventorySlotUpdatePacket`, `ParseSpellSlotUpdatePacket`, `UserPane`, `LivingObjectPane`, `inventory slot`, `spell slot`, `LocalInventorySlotRecord`, `GetInventorySlotAddress`, `g_activeUserStatusPane`, and `g_pCollectionData`.
- Research-time Agent-root search found the supervisor-accepted report `tools/leaser/Agents/Agent-B001/research/0003U8-UserPaneStartDirectionalAnimation-source-quality.md`, exact evidence-time SHA256 `C451005A4017837F2576424A48968610A4B0EF40A7C42D500862E5A16740AB1C`, because its complete UserPane destination includes the `ParseInventorySlotUpdatePacket` declaration. It supplied no target-specific packet or body research, but its accepted shared-class contract changes `StartDirectionalAnimation` to signed plain `char`. Destination 2 in this report is now the completed no-loss merge of that accepted B001 declaration with C3UM's four inventory-field renames; no shared-class rebase decision is deferred to callback time.
- Executed report `executed-b-agent-research/B001/00007B-LivingObjectPane-class-source-quality.md`, SHA256 `ACAB81879D78AE8ECEDFE4C7B8F65D1F71294D6F756B1F9E09CFBC9B0DD754FA`, preserved the older LivingObjectPane attribution. Current class size and receiver-offset evidence disproves that attribution for this target.
- Executed report `executed-b-agent-research/B001/0001KM-livingobject-localplayer-source-split-audit.md`, SHA256 `2D5E2E9348C546FBB26C5302EEFE49C42FBCC9F02EC313231C718889C1F8127B`, and `.../0001KM-livingobject-localplayer-source-split-retry.md`, SHA256 `015A9612DF9011F22889E88F1F5231C66C9DE9BE27B2A6D51EE39079783C8EA1`, supplied historical split/direct-delegate leads but retained the stale spell label.
- Executed report `executed-b-agent-research/B004/0003UT-LivingObjectPaneHandleUIPanelSwitchPacket-source-quality.md`, SHA256 `9B8408C79A89564F35A979A3934D2A247AD39B4B4544E7A1A1F9C6BAB7C871C8`, listed this target only as a UserPane-family sibling and does not establish its packet schema.
- Executed report `executed-b-agent-research/B010/0003UV-LivingObjectPaneRawPositionSyncPacketHelper-source-quality.md`, SHA256 `5CAC9BEF22648559D0BC99541CC74A7AF8662C0ECD2B153AE5D52672BC5A0B67`, supplied route contrast only.
- Executed report `executed-b-agent-research/B005/00037X-MapPaneInteractionMapChangeCore-source-quality.md`, SHA256 `7E6CD8D916E5E67657DBC55BDF7185DE2A1DBF3621C39636B133C91864C9E04B`, copied the then-current UserPane declaration but did not research this parser.
- Executed report `executed-b-agent-research/B001/0003U6-UserPaneProcessMovement-source-quality.md`, SHA256 `93F0BCAC417B6C72E1A368963D0104ACD85595CD5EF264B57A2B81DF8DAF9AE8`, supplied current UserPane source-route/class context only.
- Primary broad support report `executed-b-agent-research/B001/0002QY-MotionAnimationTimerTick-empty-emitter-source-quality.md`, SHA256 `08B58B97B76635467AC02E1FB182BCDF56C01FE1B7AB754941AA3233A408782A`, correctly moved the body from LivingObjectPane to UserPane and made it emitting, but its target treatment was intentionally broad and its draft text helper, unsigned slot, bound owner, field names, and write order do not survive direct instruction comparison.
- Executed target-family support opened: `executed-b-agent-research/B006/0003U9-LivingObjectPaneGetInventorySlotAddress-source-quality.md` for `0x1fc` indexing; `B006/0003PN-ItemHelpPaneOnPaintFrame-source-quality.md` for durability/protection/UI semantics; `B002/0001KN-UseInventorySlotDispatch-source-quality.md` for quantity/target-mode consumers; `B003/0004BQ-AddItemWithCountDialogConstructor-source-quality.md` and `B003/0002JO-MyItemListPaneConstructor-source-quality.md` for inventory-slot record consumers. These are revalidated leads, not substitutes for target disassembly.
- `tools/leaser/Agents/Older-Research/**` and `tools/leaser/Agents/SpecialReports/**` were searched with the exact UID, address, name, owner, inventory, spell, slot, and record terms; neither root contained a direct target report or source-contract evidence.
- The actual project archive root `source-3/project-documentation/archived/**` was searched with the same terms. It contained no Markdown reports, so it supplied no direct target evidence.

## Target

- UID: `0003UM`.
- Current path: `by-memory/0x005aa710-0x005aaa2c.UserPaneParseInventorySlotUpdatePacket.md`.
- Exact address range: `[0x005aa710,0x005aaa2c)`, length `0x31c` / `796` bytes.
- Pre-callback metadata: completion `86`, confidence `88`, canonical owner `0000FQ`, reconstructable `TRUE`, emitter `0000FQ`, blank position, `Nested:0`.
- Current implemented metadata: completion `92`, confidence `94`, with the same UID/path/range/owner/emitter/reconstructable/position/nesting.
- Current IDA name: `sub_5AA710`; recommended source name remains `UserPane::ParseInventorySlotUpdatePacket`.
- Source route: [UID:0000FQ] `UserPane` through [UID:0000P1] `NexusTK/ui/panels/UserPane.cpp`.
- Historical aliases rejected as current source: `LivingObjectPane::ParseSpellSlotUpdatePacket`, `LivingObjectPane` helper, spell-slot parser, raw helper, and blank/no-code target.

## Current Target State

The target now emits one corrected definition at `92/94`. Its installed formal uses a plain signed slot, direct one-byte length parsing, one reused 256-byte narrow staging buffer, three 256-wide locals, exact `MemoryMan::MemmoveWrapper` plus `MultiByteToWideChar` calls, `g_activeUserStatusPane + 0x284` as the bound, resolved item-meta/owner/durability/protection semantics, and the exact binary store order. The pre-callback unsigned-slot, invented-helper, CollectionData-bound, generic-field, and grouped-store draft remains relevant only as superseded history.

No split is required inside the exact target. The modeled function starts at `0x005aa710`, has size `0x31c`, and ends exactly at `0x005aaa2c`. Pure `0xcc` alignment lies immediately before and after it. The next retained body at `[0x005aaa30,0x005aaa88)` is a separate inventory-slot clear helper equivalent to dispatcher opcode `0x10`; it does not belong to UID0003UM.

## Executive Recommendation

1. Destination 1 is installed exactly in UID0003UM; target evidence/summary are synchronized, metadata is `92/94`, and every other target header value is retained.
2. Destination 2 is installed exactly in `by-class/UserPane.md`; B001's `StartDirectionalAnimation(char direction)` and all unrelated class content are preserved while only the four accepted record fields changed.
3. The UserPane file, UID0001KM aggregate, UID0003VB dispatcher, UID0003U9 accessor, and LivingObjectPane file are synchronized without support-score or unrelated-formal changes.
4. Both exact pure-padding spans are documented in `by-memory/-ignored.md`; neither padding span nor the separate clear-slot body is merged into the target.
5. `g_activeUserStatusPane`, its storage page, UserStatusPane, ItemHelpPane, packet-reader, MemoryMan, CollectionData, and other consumers remain verify-only and unchanged.

## Supervisor Active Recheck

- Historical assignment-time tracker statement was rechecked against the then-current target: `86/88`, reconstructable true, owner/emitter `0000FQ`, one emitted but deficient body, and zero target-specific reports before this artifact. Current ordinary target truth is `92/94` with the corrected body.
- Agent/report collision search found no competing target owner. The supervisor-accepted B001 UID0003U8 report owns the signed `StartDirectionalAnimation(char direction)` correction on the shared class destination; this report incorporated that exact declaration into Destination 2. The callback reread was completed as a concurrent-content guard and introduced no unresolved rebase or ownership decision.
- Every ordinary destination was reread under its short B004 lease, scoped-validated, and immediately unleased; no B004 lease remains.
- Generated output was never manually edited. Authorized waited validator command `000000012772` refreshed it, and B004 inspected the result read-only.
- Manual coverage was inspected read-only. Exact supervisor-owned replacement/addition text is supplied below; no coverage file was edited.

## Inference Research Guidance Check

- Names were accepted only when binary role plus project-wide source vocabulary supported them. `ParseInventorySlotUpdatePacket`, `displayName`, `itemMetaKey`, `ownerName`, `quantityOrCount`, `quantityPromptFlag`, `currentDurability`, `protectionCount`, and `targetMode` each have direct dispatch, layout, or consumer evidence.
- `char inventorySlot` is the strongest source type because the body invokes the MSVC/Dinkumware narrow-character lowering helper, later sign-extends the value, and performs signed lower/upper checks. `unsigned char` is rejected for the slot but retained for packet bytes and one-byte fields.
- The three local wide buffers are exactly 256 elements. The one reused narrow buffer is exactly 256 bytes. The body does not prove or need a human `ReadLengthPrefixedAnsiText` abstraction; explicit repeated source is the strongest compiling shape.
- The `MultiByteToWideChar` return is narrowed to one byte before wide-NUL indexing in each sequence. The formal preserves that unusual behavior instead of normalizing to `int`.
- The field names at `+0x1f0` and `+0x1f4` are not inferred from numbers alone: ItemHelpPane constructor/paint consumers identify current durability and protection count. The text fields at `+0x0a6` and `+0x146` likewise have direct `m_itemMetaKey` and `m_ownerName` consumers.
- The global bound is not assigned a new accessor/friend abstraction. The current project source convention directly reads `g_activeUserStatusPane->m_inventorySlotCount`, and inventing a new helper would exceed evidence.
- No safety behavior was added. Missing packet-length, string-length, null-pointer, conversion-error, and global-pointer checks are binary facts and remain explicit negative evidence.

## Heuristic / Inference Reanalysis And Validation

| Question | Candidate set | Resolution | Basis |
|---|---|---|---|
| Owner | LivingObjectPane, UserPane, packet utility | UserPane | Receiver fields reach `+0x134104`; LivingObjectPane ends at `+0x20c`; dispatcher passes adjusted UserPane receiver. |
| Method name | spell parser, generic slot parser, inventory parser | `ParseInventorySlotUpdatePacket` | Opcode adjacency, exact `0x1fc` inventory records, `GetInventorySlotAddress` consumers, and dispatcher semantics. |
| Slot type | unsigned byte, signed byte, int | plain `char` | Runtime `to_char_type`, later `movsx`, signed `slot > 0`, signed upper-bound compare. |
| Text abstraction | invented helper, SimpleUString, explicit copy/convert | explicit repeated copy/convert | Three inlined copies and conversions, no helper call, one reused 256-byte narrow buffer. |
| First text | spell name, generic text, display name | `displayName` | ItemHelpPane and item dialogs consume record `+0x006` as display text. |
| Second text | secondary text, description, meta key | `itemMetaKey` | ItemHelpPane uses record `+0x0a6` as preferred metadata key and falls back to display name. |
| Third text | tertiary text, owner text, maker | `ownerName` | ItemHelpPane copies record `+0x146` to its accepted `m_ownerName`. |
| Dword `+0x1f0` | generic value, max durability, current durability | `currentDurability` | ItemHelpPane copies it to accepted `m_currentDurability`. |
| Dword `+0x1f4` | generic value, flags, protection count | `protectionCount` | Packet supplies one byte; ItemHelpPane formats positive values as `PROTECTED (%d)`. |
| Bound owner | CollectionData, UserPane local count, UserStatusPane | `g_activeUserStatusPane->m_inventorySlotCount` | Absolute load `0x0069ae0c`, pointee byte `+0x284`; global/storage/class docs agree. |
| Return | success bool, validity bool, handled bool | always `false` | Both valid and invalid flows converge on zero return. |
| Split | one function, string helper children, target plus clear helper | one exact target function | IDA function boundary is exact; no internal independent entry/xref; successor is separately bounded. |

## Evidence Standards Used

- Direct binary evidence: modeled function boundaries, exact bytes and hashes, disassembly, decompilation, CFG, direct call site, callee addresses, imports, and field offsets.
- Cross-function semantic evidence: dispatcher opcode, accessor stride, ItemHelpPane copies/formatting, item-use paths, and global storage/class layouts.
- Current documentation evidence: exact ordinary destinations and manual coverage rows, read-only and checked for stale current-facing statements.
- Historical reports: used only as leads and provenance, with stale ownership/spell/no-code conclusions explicitly superseded.
- Inference labels: lexical names and source placement are distinguished from exact machine facts; scores remain below 95 because original source spelling and exact local names are not recoverable.

## Evidence Checked

### Live MCP calls

- Fresh streamable MCP initialization returned transport session `a95ca9fe-3997-4f8b-93a7-b9c684dfcdd9`.
- At evidence collection, `idb_list` returned exactly one adopted/owned worker session: database `01f84d61`, `NexusTK.exe.i64`, worker PID `18448`, created `2026-07-15T02:19:37.226313`. This records evidence-time state and does not assert later session availability.
- `server_health(database=01f84d61)` returned `status=ok`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, and `2067` cached strings at evidence time.
- `lookup_funcs(0x005aa710)` returned `sub_5AA710`, size `0x31c`; `lookup_funcs(0x005aaa2c)` returned no function.
- `get_bytes` covered the target and all four adjacent spans listed in the range section.
- `analyze_function(0x005aa710)`, `decompile`, and bounded instruction queries returned a four-block, cyclomatic-complexity-three function with `212` instructions, first instruction `0x005aa710`, last instruction `0x005aaa29`, and stack frame `0x724`.
- `xrefs_to`, caller, and callee queries established one direct caller at `0x005a775c` inside `sub_5A76C0` and the exact helper/import set listed below.
- Bounded decompiles of `0x005a76c0`, `0x005a3870`, and ItemHelpPane constructor `0x004c82d0` were used to validate dispatcher, record indexing, and field names.

### Repository and report searches

- Current `tools/leaser/Agents/**` search terms and outcomes are enumerated in Supporting Research. One then-active B001 report matched only the copied class declaration; no target-specific current report existed.
- Executed report paths opened and classified are enumerated individually in Supporting Research, including primary support UID0002QY and the earlier split/ownership reports.
- `tools/leaser/Agents/Older-Research/**`: no direct match.
- `tools/leaser/Agents/SpecialReports/**`: no direct match.
- `source-3/project-documentation/archived/**`: no Markdown report and no direct match.
- Manual `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, and `by-file/-coverage-report.md` rows were inspected. Target/class/file rows require the exact no-loss text below; the LivingObjectPane/global/storage/parent/accessor rows are already accurate at row granularity.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
|---|---|---|---|---|---|---|
| C3UM-001 | UID0003UM retains its UID and exact current path. | Exact | Current page carries UID0003UM at the assigned `0x005aa710-0x005aaa2c` path; no rename/split is supported. | `by-memory/0x005aa710-0x005aaa2c.UserPaneParseInventorySlotUpdatePacket.md` metadata | incorporate | applied |
| C3UM-002 | Exact function range is `[0x005aa710,0x005aaa2c)`, `0x31c`/796 bytes. | Exact | Fresh `lookup_funcs` returned start `0x005aa710`, size `0x31c`; final instruction is `0x005aaa29`, followed by alignment. | Target range/evidence | incorporate | applied |
| C3UM-003 | Exact target-byte SHA256 is `FEE5D907C63EEB2EAAF826EA113672F73D5205FF759757551F18EFC4A7C93160`. | Exact | Bounded MCP `get_bytes` over all 796 target bytes was hashed independently. | Target evidence | incorporate | applied |
| C3UM-004 | Target is one modeled function with four blocks, complexity three, and no internal split. | Very high | `analyze_function`, decompile, and bounded instruction/xref queries found one entry and no independently routed interior body. | Target summary; UID0001KM inventory | incorporate | applied |
| C3UM-005 | Stack frame is `0x724` with security-cookie epilogue and no source-level local SEH contract. | Exact | Decompile/disassembly show `ebp-724h` locals and cookie check but no local SEH registration or cleanup path. | Target ABI/compiler evidence | incorporate | applied |
| C3UM-006 | Sole direct caller is dispatcher call `0x005a775c`. | Exact | Target xrefs/caller queries returned one direct call inside `sub_5A76C0`. | Target caller section; UID0003VB; UID0001KM | incorporate | applied |
| C3UM-007 | Dispatcher opcode `0x0f` routes payload from `Event+0x0c` to this parser. | Exact | Dispatcher decompile/disassembly loads payload `Event+0x0c`, case-selects `0x0f`, adjusts the UserPane receiver, and calls at `0x005a775c`. | Target behavior; UID0003VB dispatcher | incorporate | applied |
| C3UM-008 | Opcode `0x10` is the adjacent clear-slot path, not this parser. | Very high | The immediately following dispatcher case clears inventory fields inline; separate raw body `[0x005aaa30,0x005aaa88)` is behaviorally equivalent. | Target boundary/history; UID0003VB | incorporate | applied |
| C3UM-009 | Canonical owner/emitter remains UID0000FQ UserPane and route UID0000P1 UserPane.cpp. | Very high | Receiver reaches UserPane-only `+0x134104`; dispatcher receiver adjustment and current class/file routes agree. | Target metadata; `by-class/UserPane.md`; `by-file/UserPane.md` | already-present | already-present |
| C3UM-010 | LivingObjectPane/spell-slot ownership is superseded historical evidence. | Very high | LivingObjectPane ends at `+0x20c`; target mutates the derived UserPane inventory array and no spell-record stride appears. | Target historical section; UID0001KM; `by-file/LivingObjectPane.md` | historicalize | applied |
| C3UM-011 | Source signature is `bool UserPane::ParseInventorySlotUpdatePacket(const unsigned char *packet)`. | High | Current class declaration, dispatcher payload route, always-zero result, and exact state mutation support this human member signature. | Target formal; rebased UserPane class formal | incorporate | applied |
| C3UM-012 | Parser obtains `MemoryMan *` once through `GetMemoryMan`. | Exact | Entry calls `0x00516030` once and preserves the returned owner for three `MemmoveWrapper` calls. | Target formal/evidence | incorporate | applied |
| C3UM-013 | Cursor starts at one because packet byte zero is the dispatcher opcode. | Exact | First target field is read from packet `+1`; dispatcher branches on payload byte zero. | Target formal/packet layout | incorporate | applied |
| C3UM-014 | Slot is source-level plain `char`, with signed validity semantics. | Very high | MSVC narrow-char lowering feeds a stored byte later sign-extended for `slot >= 1` and signed upper-bound comparison. | Target formal/type evidence | incorporate | applied |
| C3UM-015 | Item id is big-endian UInt16 at packet bytes two and three. | Exact | Call at `0x005aa76d` invokes accepted BE16 reader on packet `+2`. | Target formal/packet table | incorporate | applied |
| C3UM-016 | Icon style is one byte immediately after item id. | Exact | Byte at packet `+4` is retained and stored to record `+0x004`. | Target formal/packet table | incorporate | applied |
| C3UM-017 | Each of three strings uses a one-byte length, exact copy, narrow NUL, conversion, narrowed count, and wide NUL. | Exact | Three repeated disassembly sequences each perform that complete operation in the same order. | Target formal/behavior evidence | incorporate | applied |
| C3UM-018 | One reused 256-byte narrow local and three 256-wide locals match the frame. | Exact | Decompile identifies `CHAR[256]` plus three `wchar_t[256]` arrays within the exact `0x724` frame. | Target formal/ABI evidence | incorporate | applied |
| C3UM-019 | `sub_575470` is compiler/runtime narrow-char lowering, not a human packet helper. | Very high | Symbol resolves to Dinkumware `_Narrow_char_traits<char,int>::to_char_type`; broad callers and inlined source semantics reject a project helper. | Target helper evidence | reject-invalid | applied |
| C3UM-020 | `MemoryMan::MemmoveWrapper` is the exact copy route for all three text payloads. | Exact | All three sequences call `0x00516220` with the retained MemoryMan receiver, packet source, destination, and one-byte length. | Target formal/receiver evidence | incorporate | applied |
| C3UM-021 | `MultiByteToWideChar(0,0,...)` is called three times with wide capacity 256. | Exact | Import call sites pass code page zero, flags zero, current narrow length, and destination capacity `0x100`. | Target formal/conversion evidence | incorporate | applied |
| C3UM-022 | Quantity/count is cursor-read big-endian UInt32. | Exact | First `0x00575790` cursor call result is stored at record `+0x1e8`. | Target formal; UserPane record | incorporate | applied |
| C3UM-023 | Quantity-prompt flag is cursor-read UInt8 normalized to bool/byte. | Exact | First `0x00575710` cursor result is tested nonzero and stored at record `+0x1ec`. | Target formal; UserPane record | incorporate | applied |
| C3UM-024 | Current durability is cursor-read big-endian UInt32. | Very high | Second BE32 cursor result is stored at `+0x1f0`; ItemHelpPane copies that field to accepted `m_currentDurability`. | Target formal; UserPane record; UID0003PN consumer evidence | incorporate | applied |
| C3UM-025 | Protection count is cursor-read UInt8 and stored in a dword field. | Very high | Second byte-cursor result is zero-extended into `+0x1f4`; ItemHelpPane formats positive values as `PROTECTED (%d)`. | Target formal; UserPane record; UID0003PN consumer evidence | incorporate | applied |
| C3UM-026 | Target mode is the final cursor-read UInt8 normalized to bool/byte. | Very high | Final `0x00575710` result is tested nonzero, stored at `+0x1f8`, and consumed by accepted item-use routing. | Target formal; UserPane record; UID0001KN support | incorporate | applied |
| C3UM-027 | Bound is `g_activeUserStatusPane->m_inventorySlotCount`, not CollectionData. | Exact | Machine load dereferences global `0x0069ae0c` then unsigned byte `+0x284`; global/storage/class docs identify that field. | Target formal; UID0000PS/UID0001PE verify-only | incorporate | applied |
| C3UM-028 | Valid slots are signed values `1..count`; invalid slots still consume/convert all fields. | Exact | Bounds branch occurs only after all three strings and scalar fields are parsed; signed lower/upper comparisons guard stores only. | Target formal/CFG evidence | incorporate | applied |
| C3UM-029 | Record base is UserPane `+0x134104`, stride `0x1fc`, index `slot-1`. | Exact | Address expression `this + 508*slot + 0x133f08` equals `m_inventorySlots[slot-1]`; UID0003U9 independently uses the same contract. | Target formal; UserPane class; UID0003U9 | incorporate | applied |
| C3UM-030 | Record size remains exactly 508 bytes with three 80-wide-character fields. | Exact | Stride is `0x1fc`; three `_wcscpy_s` calls target offsets `+0x006/+0x0a6/+0x146` with capacity `0x50`. | Rebased UserPane class formal; UID0003U9 detail | incorporate | applied |
| C3UM-031 | First text field remains `displayName` at record `+0x006`. | Very high | ItemHelpPane and item dialogs consume `+0x006` as displayed item name. | Target formal; rebased UserPane class formal | already-present | already-present |
| C3UM-032 | Second text field is `itemMetaKey` at `+0x0a6`. | Very high | ItemHelpPane tests/copies `+0x0a6` as the preferred metadata key and falls back to display name. | Target formal; rebased UserPane class formal; UID0003U9 detail | incorporate | applied |
| C3UM-033 | Third text field is `ownerName` at `+0x146`. | Very high | ItemHelpPane copies record `+0x146` to its accepted `m_ownerName`. | Target formal; rebased UserPane class formal; UID0003U9 detail | incorporate | applied |
| C3UM-034 | Record `+0x1f0` is `currentDurability`. | Very high | ItemHelpPane constructor copies the field to its accepted current-durability member. | Target formal; rebased UserPane class formal; UID0003U9 detail | incorporate | applied |
| C3UM-035 | Record `+0x1f4` is `protectionCount`. | Very high | ItemHelpPane copies and paints the field through `PROTECTED (%d)` behavior. | Target formal; rebased UserPane class formal; UID0003U9 detail | incorporate | applied |
| C3UM-036 | Exact record write order is preserved by Destination 1. | Exact | Disassembly stores item id, quantity, prompt, durability, protection, icon, active, two strings, target mode, then owner string. | Target formal | incorporate | applied |
| C3UM-037 | Function returns false for valid and invalid slots. | Exact | Valid and invalid branches converge on zero return; no true-producing path exists. | Target formal/CFG evidence | incorporate | applied |
| C3UM-038 | No packet, pointer, length, conversion, or count safety behavior may be invented. | Exact negative | Disassembly has no such guard, clamp, null test, or conversion-error branch. | Target formal/negative evidence | reject-invalid | applied |
| C3UM-039 | Completion/confidence become `92/94`; owner/emitter/reconstructable/blank position/Nested remain unchanged. | High | Direct body, route, field, split, and formal blockers are closed; only original lexical/rebuild identity remains capped. | Target metadata | incorporate | applied |
| C3UM-040 | `[0x005aa702,0x005aa710)` is fourteen-byte `0xcc` alignment with recorded hash. | Exact | Bounded bytes are all `0xcc`; SHA256 is `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`. | `by-memory/-ignored.md` | incorporate | applied |
| C3UM-041 | `[0x005aaa2c,0x005aaa30)` is four-byte `0xcc` alignment with recorded hash. | Exact | Bounded bytes are all `0xcc`; SHA256 is `8843B54D2DF63CA265CF4A05D27DD2B29A74FB476D296DD44A0E171D74B441CA`. | `by-memory/-ignored.md` | incorporate | applied |
| C3UM-042 | `[0x005aaa30,0x005aaa88)` is a separate retained clear-slot helper and is not merged. | Very high | Four-byte alignment separates it; its signed slot validation and clear stores match opcode `0x10`, not opcode `0x0f` update parsing. | Target range/history; UID0001KM inventory | reject-invalid | applied |
| C3UM-043 | UserPane file/parent/dispatcher prose replaces stale spell/generic target statements without score inflation. | Very high | Pre-callback pages retained stale spell labels despite direct opcode/record evidence; current pages carry corrected inventory/opcode text with scores and unrelated content preserved. | `by-file/UserPane.md`; UID0001KM; UID0003VB | reject-stale | applied |
| C3UM-044 | LivingObjectPane file removes current-facing ownership/spell claims while preserving superseded history. | Very high | UserPane-only receiver offsets disprove current ownership; current tables exclude the target while the old attribution remains useful dated provenance. | `by-file/LivingObjectPane.md` current/history sections | historicalize | applied |
| C3UM-045 | Globals, UserStatusPane, ItemHelpPane, packet readers, MemoryMan, and unrelated siblings remain verify-only. | High | Their current accepted detail already supplies the exact global, field, helper, and consumer facts; no contradiction requires edits. | Verify-only support set | already-present | already-present |
| C3UM-046 | Exact manual coverage replacement/addition text below is supervisor-owned and was not applied by B004. | Exact process boundary | Current manual rows were read-only compared and exact no-loss replacement/addition text is present under the required handoff heading. | `Exact Manual Supervisor-Owned Coverage Or Tracker Text` | not-applicable | excluded-with-reason |

### Callback Claim Proof

| Claim | Destination-specific terminal proof |
|---|---|
| C3UM-001 | UID0003UM remained at its exact path and UID; scoped validator `000000012759` and final waited validator `000000012772` both returned exit `0`, `ok:1`. |
| C3UM-002 | Target page records `[0x005aa710,0x005aaa2c)` and `0x31c`/796 bytes; validators `12759`/`12772` passed. |
| C3UM-003 | Target evidence records byte SHA256 `FEE5D907...C93160`; validators `12759`/`12772` passed without range mutation. |
| C3UM-004 | Target and UID0001KM record one four-block, complexity-three function with no split; validators `12759` and `12765` passed. |
| C3UM-005 | Target ABI/compiler section records the `0x724` frame and cookie-only compiler lowering; validator `12759` passed. |
| C3UM-006 | Target, UID0003VB, and UID0001KM record sole call `0x005a775c`; validators `12759`, `12767`, and `12765` passed. |
| C3UM-007 | Target and UID0003VB record event payload `+0x0c`, opcode `0x0f`, receiver adjustment, and call `0x005a775c`; validators `12759`/`12767` passed. |
| C3UM-008 | Target, dispatcher, and parent distinguish opcode `0x10` clear behavior and retained `[0x005aaa30,0x005aaa88)` helper; validators `12759`, `12767`, `12765` passed. |
| C3UM-009 | Target metadata retained UID0000FQ owner/emitter and UserPane.cpp route; class/file validators `12761`/`12763` confirm already-present ownership. |
| C3UM-010 | Target history, UID0001KM, and LivingObjectPane file explicitly historicalize LivingObjectPane/spell ownership; validators `12759`, `12765`, `12770` passed. |
| C3UM-011 | Destination 1 and Destination 2 are byte-for-byte equal to the installed target/class managed blocks; validators `12759`/`12761` and final generation passed. |
| C3UM-012 | Installed target body obtains one `MemoryMan *` through `GetMemoryMan`; validator `12759` and generated readback confirm it. |
| C3UM-013 | Installed target body initializes `offset = 1`; validator `12759` and generated readback confirm it. |
| C3UM-014 | Installed target body declares `const char inventorySlot`; validator `12759` and generated readback count one signed declaration. |
| C3UM-015 | Installed target body reads item id through `PacketBufferReadUInt16BE`; validator `12759` passed. |
| C3UM-016 | Installed target body reads and stores one-byte `iconStyle`; validator `12759` passed. |
| C3UM-017 | Installed target body contains all three exact copy/NUL/convert/narrowed-count/wide-NUL sequences; validator `12759` and generated readback confirm them. |
| C3UM-018 | Installed target body has one `char[256]` and three `wchar_t[256]` locals; validator `12759` passed. |
| C3UM-019 | Target evidence rejects `sub_575470` as a project helper and emitted C++ contains no such helper call; validator `12759` passed. |
| C3UM-020 | All three installed sequences use the retained `MemoryMan::MemmoveWrapper`; validator `12759` and generated readback confirm them. |
| C3UM-021 | All three installed sequences call `MultiByteToWideChar(0, 0, ..., 256)`; validator `12759` and generated readback confirm them. |
| C3UM-022 | Installed target reads/stores `quantityOrCount` through BE32; validator `12759` passed. |
| C3UM-023 | Installed target reads/normalizes/stores `quantityPromptFlag`; validator `12759` passed. |
| C3UM-024 | Installed target reads/stores `currentDurability`; target/class/accessor validators `12759`, `12761`, `12769` passed. |
| C3UM-025 | Installed target reads byte protection count and stores `protectionCount`; target/class/accessor validators `12759`, `12761`, `12769` passed. |
| C3UM-026 | Installed target reads/normalizes/stores final `targetMode`; validator `12759` passed. |
| C3UM-027 | Installed target uses `g_activeUserStatusPane->m_inventorySlotCount`; generated target block has one accepted bound and zero `g_pCollectionData` bound; validator `12772` passed. |
| C3UM-028 | Installed body parses all fields before signed validity checks; target evidence preserves invalid-slot full consumption; validator `12759` passed. |
| C3UM-029 | Target/class/accessor document UserPane `+0x134104`, `0x1fc`, and `slot-1`; validators `12759`, `12761`, `12769` passed. |
| C3UM-030 | Installed class/accessor contract is exactly 52 records of `0x1fc` with three 80-wide fields; validators `12761`/`12769` passed. |
| C3UM-031 | `displayName +0x006` was already present and remains unchanged in target/class/accessor; validators `12759`, `12761`, `12769` passed. |
| C3UM-032 | `itemMetaKey +0x0a6` is installed in target/class/accessor; validators `12759`, `12761`, `12769` passed. |
| C3UM-033 | `ownerName +0x146` is installed in target/class/accessor; validators `12759`, `12761`, `12769` passed. |
| C3UM-034 | `currentDurability +0x1f0` is installed in target/class/accessor; validators `12759`, `12761`, `12769` passed. |
| C3UM-035 | `protectionCount +0x1f4` is installed in target/class/accessor; validators `12759`, `12761`, `12769` passed. |
| C3UM-036 | Installed Destination 1 preserves exact machine store order; target validator `12759` and generated readback confirm the ordered body. |
| C3UM-037 | Installed target returns false after the conditional store and has no true path; validator `12759` passed. |
| C3UM-038 | Generated target block contains zero invented text helper, CollectionData bound, stale generic fields, or added safety branches; validator `12772` passed. |
| C3UM-039 | Target is `92/94` with owner/emitter/reconstructable/blank position/`Nested:0` retained; validators `12759`/`12772` passed. |
| C3UM-040 | `by-memory/-ignored.md` records `[0x005aa702,0x005aa710)` and hash `1E875C...C44356`; validator `12771` passed. |
| C3UM-041 | `by-memory/-ignored.md` records `[0x005aaa2c,0x005aaa30)` and hash `8843B5...B441CA`; validator `12771` passed. |
| C3UM-042 | Target/parent/dispatcher preserve the separate clear helper and non-merge decision; validators `12759`, `12765`, `12767` passed. |
| C3UM-043 | UserPane file, UID0001KM, and UID0003VB now use inventory-parser/current opcode text without score/formal inflation; validators `12763`, `12765`, `12767` passed. |
| C3UM-044 | LivingObjectPane current tables exclude `0x005aa710`, while dated provenance remains; validator `12770` passed. |
| C3UM-045 | Verify-only dependencies were reread and left unchanged because no contradiction was found; no ordinary write or validator was performed on them. |
| C3UM-046 | Exact manual coverage handoff remains in this report; B004 did not edit manual coverage, so the terminal state is excluded-with-reason and supervisor-owned. |

## Positive Evidence Summary

- Exact unique modeled boundary and byte hash establish a stable source body.
- One direct dispatcher route identifies packet opcode `0x0f` and UserPane receiver adjustment.
- Every scalar parse operation is accounted for by a direct byte access or accepted packet cursor helper.
- Three repeated copy/conversion sequences account for the large frame and prove text capacities.
- Absolute global access plus accepted UserStatusPane storage/class docs prove the slot-count owner.
- Record base, stride, and accessor agree exactly on a one-based 52-entry UserPane inventory array.
- ItemHelpPane and item-use consumers resolve the four formerly generic field names.
- Both return paths converge on false, and invalid-slot behavior is fully explained.
- Padding hashes and successor-body analysis prove exact end boundary and reject an aggregate merge.

## IDA MCP Facts

### Function and control flow

- `sub_5AA710`: start `0x005aa710`, size `0x31c`, end exclusive `0x005aaa2c`.
- `212` decoded instructions, first `0x005aa710`, last `0x005aaa29`.
- Four basic blocks, cyclomatic complexity three.
- Stack frame `0x724`; security cookie setup/check is compiler support, not source exception logic.
- No function-local SEH registration or cleanup region exists.
- Return register is zeroed on the common epilogue; no path returns true.

### Callee inventory

| Address | Accepted identity | Target role |
|---|---|---|
| `0x00516030` | `GetMemoryMan` | Obtains MemoryMan once. |
| `0x00575470` | `std::_Narrow_char_traits<char,int>::to_char_type` compiler/runtime support | Lowers packet byte to source plain `char`; not emitted as a human call. |
| `0x00575480` | `PacketBufferReadUInt16BE(const unsigned char *)` | Reads item id. |
| `0x00516220` | `MemoryMan::MemmoveWrapper` | Copies each narrow text payload. |
| import `0x0060d120` | `MultiByteToWideChar` | Converts each text payload with code page/flags zero. |
| `0x00575790` | cursor `PacketBufferReadUInt32BE` | Reads quantity/count and current durability. |
| `0x00575710` | cursor `PacketBufferReadUInt8` | Reads prompt, protection count, and target mode. |
| `0x005cd657` | `_wcscpy_s` | Copies three converted wide locals into 80-wide record fields. |
| security helper | compiler cookie check | Compiler support only. |

### Exact packet and write facts

| Parse order | Value | Width/source | Destination |
|---|---|---|---|
| 1 | inventory slot | signed plain `char`, packet `+1` | selection only |
| 2 | item id | BE16, packet `+2..+3` | record `+0x002` |
| 3 | icon style | UInt8 | record `+0x004` |
| 4 | display name | UInt8 length + bytes + ACP conversion | record `+0x006`, cap 80 |
| 5 | item meta key | UInt8 length + bytes + ACP conversion | record `+0x0a6`, cap 80 |
| 6 | quantity/count | cursor BE32 | record `+0x1e8` |
| 7 | quantity prompt | cursor UInt8 != 0 | record `+0x1ec` |
| 8 | current durability | cursor BE32 | record `+0x1f0` |
| 9 | protection count | cursor UInt8, zero-extended | record `+0x1f4` |
| 10 | owner name | UInt8 length + bytes + ACP conversion | record `+0x146`, cap 80 |
| 11 | target mode | cursor UInt8 != 0 | record `+0x1f8` |

The machine store sequence is item id, quantity/count, prompt flag, current durability, protection count, icon style, active byte, display-name copy, item-meta-key copy, target-mode byte, owner-name copy. Destination 1 preserves that sequence rather than reorganizing it by structure declaration order.

## Function / Child Inventory

| Range | Kind | Disposition |
|---|---|---|
| `[0x005aa702,0x005aa710)` | 14 bytes of `0xcc` | Pure alignment; add to ignored ledger. |
| `[0x005aa710,0x005aaa2c)` | UID0003UM modeled function | One source-authored UserPane member; no child split. |
| `[0x005aaa2c,0x005aaa30)` | 4 bytes of `0xcc` | Pure alignment; add to ignored ledger. |
| `[0x005aaa30,0x005aaa88)` | 88-byte retained raw body | Separate inventory-slot clear helper, byte/source-equivalent to dispatcher opcode `0x10`; outside this assignment and not merged. |
| `[0x005aaa88,0x005aaa90)` | 8 bytes of `0xcc` | Alignment before the next parser; outside target changes. |
| `0x005aaa90...` | next raw parser | Separate successor family; outside target. |

No exact child is required for UID0003UM. The function has no interior xref, compiler jump table, embedded constant table, or independently callable helper. Splitting the repeated text sequences would invent abstractions absent from both machine routing and current source vocabulary.

## Direct Xref / Caller Inventory

| Site | Caller | Evidence and disposition |
|---|---|---|
| `0x005a775c` | `UserPane::OnServerMessage` (`sub_5A76C0`) | Sole direct call. Case opcode `0x0f` pushes payload from `Event+0x0c`, adjusts receiver with `lea ecx,[ebx-0xa0]`, calls target, and joins common epilogue. |

No vtable slot, function pointer, import/export entry, VA/RVA data pointer, or second direct call was found. This low xref count is expected for a private packet delegate and does not support no-code treatment. The immediately following opcode `0x10` case clears the same record fields inline and is independent corroboration of record semantics.

## Documentation Evidence And IDA Status

- At evidence collection and final bounded recheck, database `01f84d61` returned healthy status and real IDB-backed target lookup. This is evidence-time wording, not an assertion of indefinite worker availability.
- Target prose now presents the source-ready inventory parser as current fact and retains the former LivingObjectPane/spell/blank/unresolved material only under explicit dated superseded-history labels.
- UID0001KM and UID0003VB now use current-facing `ParseInventorySlotUpdatePacket`/inventory-slot text for opcode `0x0f`; dispatcher opcode `0x10` and the separate retained clear helper are explicitly distinguished.
- `by-file/LivingObjectPane.md` now excludes `0x005aa710` from current LivingObjectPane packet families and preserves the old attribution only as superseded provenance.
- `by-class/UserPane.md` contains B001 UID0003U8's accepted signed `StartDirectionalAnimation(char direction)` contract and C3UM's `itemMetaKey`, `ownerName`, `currentDurability`, and `protectionCount` fields. The installed managed block is byte-for-byte equal to Destination 2; size, offsets, count, declaration order, and every unrelated accepted/current class line remain valid.
- Current globals already identify `g_activeUserStatusPane` and its `+0x284` `m_inventorySlotCount`; no global/storage edit is needed.
- Manual coverage remains supervisor-owned and was not edited by B004. At callback comparison time, its inspected target row was still the pre-callback `86%` row; the exact replacement/addition text is preserved below, while any later external coverage state is not asserted here. UserPane class/file rows were `92%`/`91%`, and the LivingObjectPane/global/storage/parent/accessor rows were no-loss current facts when inspected.

## Ranked Ownership Analysis

### 1. UserPane member in UserPane.cpp - accepted

The receiver uses `m_inventorySlots` at UserPane `+0x134104`; this is far beyond the `0x20c` LivingObjectPane base. Dispatcher receiver adjustment, the complete UserPane class, sibling source order, and generated route all agree. Confidence is very strong.

### 2. LivingObjectPane member - rejected

Historical reports and nested target prose use this attribution, but it is structurally impossible for a base object to own the derived-only array. Retain as superseded provenance only.

### 3. PacketBuffer or network utility function - rejected

The body uses packet helpers but mutates UserPane state and receives `this`. Shared helpers do not determine owner.

### 4. UserStatusPane member - rejected

UserStatusPane supplies only the active slot-count bound. The mutated record array belongs to UserPane, and the dispatcher invokes the method on UserPane.

### 5. Aggregate/no-code/compiler support - rejected

The body is a unique routed handwritten parser with application semantics. Stack cookie and narrow-char helper are compiler details inside it, not a reason to suppress the source method.

## Source Placement

- Class owner: [UID:0000FQ] `UserPane`.
- File owner: [UID:0000P1] `NexusTK/ui/panels/UserPane.cpp`.
- Source order: private packet delegate after the inventory accessor/use family and within the UserPane server-message parser sequence represented by UID0001KM. Preserve current child order rather than assigning a new emitter position.
- The target remains `EMITTER_POSITION_OPTIONAL:` blank because the established UserPane child/aggregate machinery already determines stable source order.
- `PacketBuffer`, `MemoryMan`, `UserStatusPane`, and ItemHelpPane remain dependencies/consumers, not alternate source owners.

## Range / Split / Padding / Reclassification Analysis

- Target bytes `[0x005aa710,0x005aaa2c)` SHA256: `FEE5D907C63EEB2EAAF826EA113672F73D5205FF759757551F18EFC4A7C93160`.
- Predecessor padding `[0x005aa702,0x005aa710)` is fourteen `0xcc` bytes, SHA256 `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`.
- Immediate successor padding `[0x005aaa2c,0x005aaa30)` is four `0xcc` bytes, SHA256 `8843B54D2DF63CA265CF4A05D27DD2B29A74FB476D296DD44A0E171D74B441CA`.
- Retained clear-slot body `[0x005aaa30,0x005aaa88)` is 88 bytes, SHA256 `5654C2933DFDB08C26166228F7892EED01F7FA44FCBE9895D3D283A6F30EB080`.
- Next padding `[0x005aaa88,0x005aaa90)` is eight `0xcc` bytes, SHA256 `3D2F424783DF5853C8D7121B1371650C04241F318E1B0CD46BEDBC805B9164C3`.
- Predecessor UID0003UL ends at `0x005aa702`; no overlap exists.
- The clear-slot body uses signed `packet[1]`, the same `g_activeUserStatusPane + 0x284` bound, and clears active, item id, first display-name word, and target mode. It is source-equivalent to the dispatcher's opcode `0x10` inline case. That resolves its role and simultaneously proves it is not UID0003UM tail bytes.
- Reclassification is semantic only: retain the exact target page and range, replace stale spell/LivingObjectPane claims with UserPane inventory parsing, and add only the two missing pure-padding spans to the ignored ledger.

## Negative Evidence Summary

- No spell-table or spell-command-slot base/stride is accessed.
- No LivingObjectPane-only object can contain the accessed derived offset.
- No `g_pCollectionData` access exists in the target.
- No human `ReadLengthPrefixedAnsiText` call or equivalent project helper route exists.
- No `SimpleUString`, STL string, heap string, or persistent narrow-string object exists.
- No packet-size parameter or packet-length check exists.
- No text-length clamp exists; one-byte lengths are copied as supplied.
- No null check exists for packet, MemoryMan, active UserStatusPane, or selected record.
- No conversion error handling exists.
- No slot check occurs before all scalar/text parsing and conversion.
- No true return exists.
- No direct second caller, vtable route, pointer table, or export exists.
- No interior child entry or xref supports splitting the repeated text sequences.
- No source evidence supports changing UserPane/parent/file scores beyond the target-specific increase.

## IDA Rename / Type / Comment Recommendations

- Rename `sub_5AA710` to `UserPane__ParseInventorySlotUpdatePacket` in analysis only if an authorized IDA mutation phase occurs; this report does not mutate IDA.
- Type as `bool __thiscall UserPane::ParseInventorySlotUpdatePacket(const unsigned char *packet)`.
- Type packet-local slot as plain signed `char` under the target compiler's plain-char behavior.
- Type the record as `LocalInventorySlotRecord` size `0x1fc` and the UserPane array as 52 records at `+0x134104`.
- Rename record fields `secondaryText` to `itemMetaKey`, `tertiaryText` to `ownerName`, `value1f0` to `currentDurability`, and `value1f4` to `protectionCount`.
- Comment opcode `0x0f` as inventory-slot update and opcode `0x10` as inventory-slot clear.
- Comment `0x00575470` as compiler/runtime narrow-char lowering; do not promote it to a project packet helper.
- Preserve raw addresses, hashes, and historical aliases in documentation evidence, not in emitted C++ identifiers.

## First-Draft C++ Recommendation

### Destination 1 - `by-memory/0x005aa710-0x005aaa2c.UserPaneParseInventorySlotUpdatePacket.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool UserPane::ParseInventorySlotUpdatePacket(const unsigned char *packet)
{
    MemoryMan *memoryMan = GetMemoryMan();
    size_t offset = 1;
    const char inventorySlot = static_cast<char>(packet[offset++]);
    const unsigned short itemId = PacketBufferReadUInt16BE(packet + offset);
    offset += 2;
    const unsigned char iconStyle = packet[offset++];

    char narrowText[256];
    wchar_t displayName[256];
    unsigned char textLength = packet[offset++];
    memoryMan->MemmoveWrapper(narrowText, packet + offset, textLength);
    offset += textLength;
    narrowText[textLength] = '\0';
    unsigned char convertedLength = static_cast<unsigned char>(
        MultiByteToWideChar(0, 0, narrowText, textLength,
                            displayName, 256));
    displayName[convertedLength] = L'\0';

    wchar_t itemMetaKey[256];
    textLength = packet[offset++];
    memoryMan->MemmoveWrapper(narrowText, packet + offset, textLength);
    offset += textLength;
    narrowText[textLength] = '\0';
    convertedLength = static_cast<unsigned char>(
        MultiByteToWideChar(0, 0, narrowText, textLength,
                            itemMetaKey, 256));
    itemMetaKey[convertedLength] = L'\0';

    const unsigned int quantityOrCount =
        PacketBufferReadUInt32BE(packet, &offset);
    const bool quantityPromptFlag =
        PacketBufferReadUInt8(packet, &offset) != 0;
    const unsigned int currentDurability =
        PacketBufferReadUInt32BE(packet, &offset);
    const unsigned int protectionCount =
        PacketBufferReadUInt8(packet, &offset);

    wchar_t ownerName[256];
    textLength = packet[offset++];
    memoryMan->MemmoveWrapper(narrowText, packet + offset, textLength);
    offset += textLength;
    narrowText[textLength] = '\0';
    convertedLength = static_cast<unsigned char>(
        MultiByteToWideChar(0, 0, narrowText, textLength,
                            ownerName, 256));
    ownerName[convertedLength] = L'\0';

    const bool targetMode = PacketBufferReadUInt8(packet, &offset) != 0;

    if (inventorySlot > 0 &&
        inventorySlot <= g_activeUserStatusPane->m_inventorySlotCount)
    {
        LocalInventorySlotRecord &record =
            m_inventorySlots[inventorySlot - 1];
        record.itemId = itemId;
        record.quantityOrCount = quantityOrCount;
        record.quantityPromptFlag = quantityPromptFlag ? 1 : 0;
        record.currentDurability = currentDurability;
        record.protectionCount = protectionCount;
        record.iconStyle = iconStyle;
        record.active = 1;
        wcscpy_s(record.displayName, 80, displayName);
        wcscpy_s(record.itemMetaKey, 80, itemMetaKey);
        record.targetMode = targetMode ? 1 : 0;
        wcscpy_s(record.ownerName, 80, ownerName);
    }

    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 2 - `by-class/UserPane.md`

This complete block is the accepted no-loss merge, originally prepared before callback and now installed exactly: it preserves B001 UID0003U8's accepted `StartDirectionalAnimation(char direction)` declaration and all other accepted/current UserPane content, then applies only C3UM's `itemMetaKey`, `ownerName`, `currentDurability`, and `protectionCount` field-name corrections.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class MapPane;
struct MapPoint;
struct PaneKeyEvent;
struct ServerMessageEvent;

MapPoint *DirectionToTileOffset(
    MapPoint *outOffset, unsigned char direction);
void __stdcall DispatchCopiedEventPayload(
    const void *data, size_t size);

static bool __stdcall HandleUIPanelSwitchPacket(
    const unsigned char *packet);
static void SendDirectionPacket(unsigned char direction);

struct LinkedPlayerRecord
{
    unsigned int objectId;                // +0x000
    wchar_t name[128];                    // +0x004
    bool active;                          // +0x104
    unsigned char reserved105;
    unsigned short field106;
    unsigned char state108[7];
    unsigned char reserved10f;
    unsigned short field110;
    unsigned char field112;
    unsigned char reserved113;
    unsigned short field114;
    unsigned char field116;
    unsigned char reserved117;
    unsigned short field118;
    unsigned char field11a;
    unsigned char reserved11b;
    unsigned int value11c;
    unsigned int value120;
    unsigned int value124;
    unsigned int value128;
};

struct LocalInventorySlotRecord
{
    unsigned char active;                 // +0x000
    unsigned char reserved001;
    unsigned short itemId;                // +0x002
    unsigned char iconStyle;              // +0x004
    unsigned char reserved005;
    wchar_t displayName[80];              // +0x006
    wchar_t itemMetaKey[80];              // +0x0a6
    wchar_t ownerName[80];                // +0x146
    unsigned char reserved1e6[2];
    unsigned int quantityOrCount;         // +0x1e8
    unsigned char quantityPromptFlag;     // +0x1ec
    unsigned char reserved1ed[3];
    unsigned int currentDurability;       // +0x1f0
    unsigned int protectionCount;         // +0x1f4
    unsigned char targetMode;             // +0x1f8
    unsigned char reserved1f9[3];
};

struct MovementWaypointSegment
{
    int startX;
    int startY;
    int endX;
    int endY;
};

struct SpellCommandSlotRecord
{
    unsigned char active;                 // +0x000
    unsigned char reserved001[3];
    int inputKind;                        // +0x004
    unsigned char reserved008[0xa0];
    wchar_t prompt[80];                   // +0x0a8
};

struct LocalMovementHistoryRecord
{
    unsigned char active;
    unsigned char reserved01[3];
    int tileY;
    int tileX;
    unsigned char direction;
    unsigned char reserved0d[3];
};

class UserPane : public LivingObjectPane
{
public:
    enum UserTimerMessage
    {
        kUserPaneMovementStep = 20
    };

    UserPane();
    virtual ~UserPane();

    virtual void OnBoundsChanged(const RectBounds *bounds);
    virtual void OnClipBounds(RectBounds *clip, RectBounds *out);
    virtual void ShowNameLabel();
    virtual void HideNameLabel();
    virtual bool OnKeyEvent(const PaneKeyEvent *event);
    virtual bool OnServerMessage(const ServerMessageEvent *event);
    virtual bool OnAnimationStep(int message, int frameOrDirection, int aux);
    virtual MapPane *GetMapPane();

    void SendGiveItemPacket(signed char slot, bool allItems);
    void SendDropItemPacket(signed char slot, bool allItems);
    CollectionPlayerDataView &GetCollectionData();
    const CollectionPlayerDataView &GetCollectionData() const;

    MapPoint *GetViewportPosition(MapPoint *outPosition) const;
    void ProcessMovement(unsigned char direction);
    void InitializeWalkAnimation(unsigned char direction);
    void StartDirectionalAnimation(char direction);
    LocalInventorySlotRecord *GetInventorySlotAddress(char inventorySlot);
    void DispatchConfiguredShortcutHotkey(short hotkeyNumber, int unused);
    void ExecuteHotkeyAction(short hotkey);
    void UseInventorySlot(unsigned char slot);
    void UseCommandSlot(unsigned char slot);
    void TryPerformAction();
    bool WarpToPosition(int x, int y, int viewportColumn, int viewportRow);
    LocalMovementHistoryRecord *GetActiveMovementHistoryRecordByIndex(
        unsigned char recordIndex);
    void ClearAllMovementHistoryRecords();
    void ClearMovementHistoryRecordByIndex(int recordIndex);
    void UpdateScreenPosition();
    void SendMovementPacket(unsigned char direction);
    void TryDispatchFunctionKeyShortcut(
        unsigned short functionKeyOrdinal, unsigned int currentTick);
    void CopyDeferredUserListPacket(
        const unsigned char *packetData, size_t packetSize);
    bool ParsePlayerSettingsPacket(const unsigned char *packet);
    bool ParseInventorySlotUpdatePacket(const unsigned char *packet);
    bool HandleServerEntryPacket(const unsigned char *packet);
    bool HandleWarpPacket(const unsigned char *packet);
    bool HandleMovementReplyPacket(const unsigned char *packet);
    bool HandleExtendedMovementReplyPacket(const unsigned char *packet);
    bool HandleChatMessagePacket(const unsigned char *packet);
    bool HandleUserListPacket(const ServerMessageEvent *event);
    bool HandlePositionSyncPacket(const unsigned char *packet);
    bool ParseLinkedObjectsPacket(const unsigned char *packet);
    void SendMovementWaypointPacket(
        unsigned char direction, unsigned short token,
        const MovementWaypointSegment *segment);
    void SendFaceDirectionPacket(unsigned char direction);
    void SendAutoFaceDirectionPacket();
    void SendActionPacketWithAutoFace();
    void SendAttackTargetPacket(unsigned char action);

private:
    friend class MapPane;

    SpellCommandSlotRecord *GetSpellCommandSlotRecord(unsigned char slot)
    {
        return &m_spellCommandSlots[slot - 1];
    }

    void ClearMovementHistoryToken()
    {
        m_movementState[2] = 0;
        m_movementState[3] = 0;
    }

    void SetMovementReplyState()
    {
        m_movementState[1] = 1;
        m_movementState[2] = 1;
    }

    bool IsDirectionDelayActive() const
    {
        return m_movementState[4] != 0;
    }

    void SetDirectionDelayActive(bool active)
    {
        m_movementState[4] = active ? 1 : 0;
    }

    unsigned char m_userPaneBaseTail[0x0c];       // 0x20c
    LinkedPlayerRecord m_linkedPlayers[50];       // 0x218
    signed char m_linkedPlayerCount;              // 0x3cb0
    unsigned char m_preCollectionState[0x213];    // 0x3cb1
    int m_localPlayerHitRadius;                   // 0x3ec4
    CollectionPlayerDataView m_collectionData;   // 0x3ec8
    int m_screenX;                                // 0x1340cc
    int m_screenY;                                // 0x1340d0
    unsigned int m_screenState;                   // 0x1340d4
    RectBounds m_screenHitBounds;                 // 0x1340d8
    RectBounds m_screenLowerHitBounds;            // 0x1340e8
    MapPane *m_mapPane;                           // 0x1340f8
    unsigned char m_playerSettingsState[8];       // 0x1340fc
    LocalInventorySlotRecord m_inventorySlots[52];// 0x134104
    SpellCommandSlotRecord m_spellCommandSlots[52];// 0x13a834
    bool m_spellCommandSlotsReady;                // 0x13ead4
    unsigned char m_preViewportState[3];          // 0x13ead5
    int m_viewportColumn;                         // 0x13ead8
    int m_viewportRow;                            // 0x13eadc
    int m_viewportHalfColumns;                    // 0x13eae0
    int m_viewportHalfRows;                       // 0x13eae4
    int m_viewportRemainingColumns;               // 0x13eae8
    int m_viewportRemainingRows;                  // 0x13eaec
    unsigned char m_movementState[5];             // 0x13eaf0
    unsigned char m_preActionTickState[3];        // 0x13eaf5
    unsigned int m_lastActionTick;                // 0x13eaf8
    unsigned char m_preWhisperHistory[8];         // 0x13eafc
    List *m_whisperHistoryOther;                  // 0x13eb04
    List *m_outgoingWhisperRecipientHistory;      // 0x13eb08
    List *m_incomingWhisperSenderHistory;         // 0x13eb0c
    unsigned char m_whisperHistorySource;         // 0x13eb10
    unsigned char m_preMovementHistory[3];        // 0x13eb11
    LocalMovementHistoryRecord *m_movementHistoryRecords; // 0x13eb14
    int m_movementHistoryCapacity;                // 0x13eb18
    unsigned char m_movementHistoryWriteIndex;    // 0x13eb1c
    unsigned char m_movementHistoryState[3];      // 0x13eb1d
    unsigned char *m_deferredUserListPacket;      // 0x13eb20
    size_t m_deferredUserListPacketSize;          // 0x13eb24
    int m_deferredUserListCount;                  // 0x13eb28
    unsigned int m_deferredUserListDeadline;      // 0x13eb2c
    bool m_deferredUserListActive;                // 0x13eb30
    unsigned char m_preMovementTicks[3];          // 0x13eb31
    unsigned int m_lastMovementSendTick;          // 0x13eb34
    unsigned int m_lastMovementInputTick;         // 0x13eb38
    unsigned char m_actionMode;                   // 0x13eb3c
    unsigned char m_userPaneTrailingState0;       // 0x13eb3d
    bool m_includeAdjacentMovementTargets;        // 0x13eb3e
    unsigned char m_userPaneTrailingState2[0x45]; // 0x13eb3f
};

typedef char LinkedPlayerRecordSizeMustBe300[
    sizeof(LinkedPlayerRecord) == 0x12c ? 1 : -1];
typedef char LocalInventorySlotRecordSizeMustBe508[
    sizeof(LocalInventorySlotRecord) == 0x1fc ? 1 : -1];
typedef char SpellCommandSlotRecordSizeMustBe328[
    sizeof(SpellCommandSlotRecord) == 0x148 ? 1 : -1];
typedef char LocalMovementHistoryRecordSizeMustBe16[
    sizeof(LocalMovementHistoryRecord) == 0x10 ? 1 : -1];
typedef char UserPaneSizeMustBe1305476[
    sizeof(UserPane) == 0x13eb84 ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Final Recommendation

Destinations 1 and 2 are installed exactly. Destination 2 preserves both accepted changes: B001 UID0003U8's `StartDirectionalAnimation(char direction)` and C3UM's four inventory-record field names. Only the target moved to `92/94`; every support score is preserved. Bounded prose and ignored padding are synchronized. The completed callback resolves every investigable target and coordination blocker: exact range, source owner, opcode, signature, signed slot, packet shape, helper disposition, local buffer shape, record layout, field semantics, global bound, write order, return value, source route, split decision, formal C++, shared-class no-loss merge, score, stale historical contradictions, and manual coverage handoff.

The confidence cap is lexical and rebuild-equivalence related: original parameter/local spelling is unavailable, and exact compiler code generation is not promised. Those caps do not justify a blank body or defer any current target decision.

## Recommended Target Doc Changes

- Applied: UID/path/range, owner `0000FQ`, emitter `0000FQ`, `RECONSTRUCTABLE:TRUE`, blank position, and `Nested:0` are retained.
- Applied: completion/confidence changed `86/88 -> 92/94`.
- Applied: Destination 1 is exact in the managed formal block; mechanical comparison reports exact equality at 3,008 normalized characters.
- Applied Item Summary: `Source-ready UserPane opcode-0x0f inventory-slot update parser with signed one-based slot validation, exact three-string ACP conversion, 508-byte record writes, active UserStatusPane bound, durability/protection semantics, and preserved invalid-slot/always-false behavior.`
- Applied: exact bytes, range, CFG, ABI, callee, packet, record, caller, padding, negative, and historical evidence remain at report-level detail.
- Applied: old LivingObjectPane/spell/blank-C++ `Status`, `Summary`, and `Open Questions` claims are under explicit superseded-history treatment with rejection reasons.
- Applied: no current target statement calls the superseded draft binary-equivalent.

## Recommended Support Doc Changes

1. Applied to `by-class/UserPane.md`: exact Destination 2; B001 `StartDirectionalAnimation(char direction)`, the four C3UM field names, every unrelated line, class closure, size guard, child point, metadata, and `92/93` are preserved. Mechanical comparison reports exact equality at 9,646 normalized characters.
2. Applied to `by-file/UserPane.md`: retained `91/92`, added opcode-`0x0f` route and exact record/global/text behavior, and preserved unrelated source-family detail.
3. Applied to `by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md`: retained `90/92` non-emitting aggregate state, replaced stale current spell rows, added full target evidence, and preserved every sibling.
4. Applied to `by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md`: retained `87/89` and formal block, labeled case `0x0f` inventory update and case `0x10` clear inventory slot, and preserved all other opcode routing.
5. Applied to `by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md`: retained `88/91` and accessor formal, added current UserPane ownership, exact 52-by-`0x1fc` array, and all resolved record fields; dated historical aliases remain explicit.
6. Applied to `by-file/LivingObjectPane.md`: retained `90/92`, removed `0x005aa710` from current LivingObjectPane/spell families, added explicit UserPane exclusion, and preserved actual LivingObjectPane content and provenance.
7. Applied to `by-memory/-ignored.md`: exact `[0x005aa702,0x005aa710)` fourteen-CC and `[0x005aaa2c,0x005aaa30)` four-CC entries with hashes, adjacency, compiler/no-source disposition, and owner links.
8. Verified unchanged: `by-global/g_activeUserStatusPane.md`, `by-memory/0x0069ae0c-0x0069ae10.g_activeUserStatusPane.md`, UserStatusPane class/file, ItemHelpPane pages, PacketBuffer, MemoryMan, CollectionData, retained clear helper, and unrelated UserPane siblings.

## Score And Metadata Recommendation

| Destination | Current | Recommended | Rationale |
|---|---|---|---|
| UID0003UM target | `92/94` current; `86/88` pre-callback | `92/94` applied | Exact body, range, opcode, field schema, helpers, owner, route, and negatives resolved; original lexical names/rebuild identity remain capped. |
| UID0000FQ UserPane class | `92/93` | unchanged | Four field-name corrections increase specificity but do not warrant unrelated score inflation. |
| UID0000P1 UserPane file | `91/92` | unchanged | Route already accepted; bounded synchronization only. |
| UID0001KM parent | current | unchanged | Non-emitting split/index role and broad score remain valid. |
| UID0003VB dispatcher | current | unchanged | Only one opcode label/detail is corrected. |
| UID0003U9 accessor | `88/91` | unchanged | Exact accessor already source-ready; detail correction only. |
| UID0000KU LivingObjectPane file | `90/92` | unchanged | Removal of stale current-facing misattribution does not change its own source completeness. |
| UID0000VN ignored ledger | ignored | unchanged | Adds two pure-padding facts only. |

## Open Questions With Attempted Resolution

| Question | Attempts | Resolution |
|---|---|---|
| Was this a spell-slot parser? | Compared receiver base/stride, dispatcher opcode adjacency, spell record layout, inventory accessor, and consumers. | No. It is inventory-slot update parsing. |
| Is the slot unsigned? | Traced compiler helper, sign extension, and both bounds. | No. Plain signed `char` is strongest source type. |
| Did source use a text helper? | Searched helpers/reports and compared all three instruction sequences. | No current route supports one; explicit repeated code is highest probability. |
| What do the three strings mean? | Traced ItemHelpPane constructor/paint and item dialogs. | `displayName`, `itemMetaKey`, `ownerName`. |
| What are `+0x1f0/+0x1f4`? | Traced ItemHelpPane field copies and `PROTECTED (%d)` display. | `currentDurability` and `protectionCount`. |
| Which object owns slot count? | Resolved absolute global and `+0x284` against global/storage/class docs. | Active UserStatusPane, not CollectionData. |
| Should repeated string parsing be split? | Checked interior xrefs/function starts and source helper vocabulary. | No. Keep in one method. |
| Does successor belong to target? | Hashed/disassembled padding and raw clear body; compared opcode `0x10`. | No. Exact target ends at `0x005aaa2c`. |
| Is no-code justified by one caller? | Compared private dispatch delegates and unique semantic body. | No. One routed private caller is sufficient liveness. |
| Is any target blocker deferred? | Rechecked all names/types/fields/helpers/range/route/score/formal/coverage questions. | No investigable blocker remains. |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

The following text is a supervisor-owned handoff. B004 did not edit manual coverage.

### Replace the UID0003UM row in `by-memory/-coverage-report.md`

```text
        - [UID:0003UM][0x005aa710-0x005aaa2c.UserPaneParseInventorySlotUpdatePacket](by-memory/0x005aa710-0x005aaa2c.UserPaneParseInventorySlotUpdatePacket.md) 0x005aa710-0x005aaa2c | UserPane member | UserPaneParseInventorySlotUpdatePacket : reconstructable : 92% : very-strong : Source-ready opcode-0x0f inventory-slot update parser with signed one-based slot validation, exact three-string 256-byte/256-wide ACP conversion, 508-byte record indexing, display/meta/owner text, quantity/prompt/durability/protection/target fields, active UserStatusPane slot-count bound, exact write order, invalid-slot full-consumption behavior, and always-false return.
```

### Add these two UID0000VN rows adjacent to UID0003UM in `by-memory/-coverage-report.md`

```text
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005aa702-0x005aa710 | padding | UserPane inventory update parser alignment : ignored : 100% : strong : Fourteen `0xcc` bytes between UID0003UL and UID0003UM; exact SHA256 `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005aaa2c-0x005aaa30 | padding | UserPane inventory update parser to clear-slot helper alignment : ignored : 100% : strong : Four `0xcc` bytes after UID0003UM and before the separate retained opcode-0x10-equivalent clear-slot helper; exact SHA256 `8843B54D2DF63CA265CF4A05D27DD2B29A74FB476D296DD44A0E171D74B441CA`.
```

### Replace the UID0000FQ row in `by-class/-coverage-report.md`

```text
- [UID:0000FQ][UserPane](by-class/UserPane.md) : reconstructable : 92% : very-strong : Complete 0x13eb84 local-player UserPane declaration with exact movement/packet/server inventory, 52 exact 508-byte inventory records with displayName/itemMetaKey/ownerName, quantity/prompt/currentDurability/protectionCount/targetMode fields, external ProcessMovement and event helper declarations, corrected viewport and movement-history state, MapPane friendship, action/adjacent-target fields, and preserved full field/record/size-guard layout surface.
```

### Replace the UID0000P1 row in `by-file/-coverage-report.md`

```text
- [UID:0000P1][UserPane](by-file/UserPane.md) : reconstructable : 91% : very-strong : NexusTK/ui/panels/UserPane.cpp source root with complete UserPane class/method families, exact movement/server/action behavior, and source-ready opcode-0x0f ParseInventorySlotUpdatePacket using signed one-based slots, three explicit ACP text conversions, the 508-byte inventory record, active UserStatusPane slot-count bound, resolved display/meta/owner/durability/protection fields, exact write order, and preserved invalid-slot/always-false behavior.
```

### Inspected rows requiring no manual change

- UID0000KU LivingObjectPane file row already explicitly excludes UserPane-only large-offset functions.
- UID0003U9 accessor and UID0001KM parent rows remain accurate at manual-row granularity.
- UID0000PS `g_activeUserStatusPane` and UID0001PE storage rows remain accurate.
- No tracker edit text is supplied because report execution/count state is external and target source-quality changes are represented by the exact coverage rows above.

## Follow-Up Actions

- No implementation item remains. C3UM-001 through C3UM-046, Destinations 1-2, all bounded support synchronization, scoped validation, lease release, and final generated readback are complete.
- The B001 UID0003U8 shared-class merge is installed, not deferred: `StartDirectionalAnimation(char direction)` and all four C3UM field names coexist in the exact Destination 2 block.
- Manual coverage remains the sole excluded handoff because it is supervisor-owned; the exact replacement/addition text above is preserved and B004 did not apply it.
- External report validation, execution, count, path, move, archive, and manual-coverage state remain supervisor/validator-owned; this artifact neither asserts nor directs those lifecycle outcomes.
- The only residual technical uncertainty is original lexical spelling/rebuild identity, already reflected in the `92/94` cap.

## Confidence

- Range/bytes/CFG/caller/callees: `99%`.
- UserPane ownership and file route: `98%`.
- Packet field order/width and record offsets: `98%`.
- Signed slot and active UserStatusPane bound: `97%`.
- `displayName`, `itemMetaKey`, `ownerName`, `currentDurability`, `protectionCount`: `94-97%` from direct consumers.
- Exact source signature and explicit repeated conversion shape: `94%`.
- Original local variable spelling: `75%`; non-semantic and capped.
- Overall recommended documentation confidence: `94`.

## Validator Results

- All commands ran from `source-3/project-documentation` with `--apply --queue-timeout 240`; each returned exit `0`, `ok:1`. Each ordinary page was leased only for its reread/edit/validation window and immediately unleased.

| Command ID | Timestamp | Scoped destination | Result and side effects |
|---|---|---|---|
| `000000012759` | `2026-07-15T03:26:12-04:00` | UID0003UM target | exit `0`, `ok:1`; completion `92`, confidence `94`, registry/reference/projected-stat updates; generated refresh deferred. |
| `000000012761` | `2026-07-15T03:26:42-04:00` | `by-class/UserPane.md` | exit `0`, `ok:1`; reference/projected-stat updates; seven pre-existing missing-reference warnings including UID0003V8/0003VA/0003VC; generated deferred. |
| `000000012763` | `2026-07-15T03:27:17-04:00` | `by-file/UserPane.md` | exit `0`, `ok:1`; reference/projected-stat updates; 22 pre-existing missing-reference warnings, 12 suppressed; generated deferred. |
| `000000012765` | `2026-07-15T03:29:12-04:00` | UID0001KM aggregate | exit `0`, `ok:1`; reference/projected-stat updates; 11 pre-existing missing-reference warnings; generated deferred. |
| `000000012767` | `2026-07-15T03:29:45-04:00` | UID0003VB dispatcher | exit `0`, `ok:1`; reference/projected-stat updates; six pre-existing UID0003VC missing-reference warnings; generated deferred. |
| `000000012769` | `2026-07-15T03:30:25-04:00` | UID0003U9 accessor | exit `0`, `ok:1`; reference/projected-stat updates; no warning row; generated deferred. |
| `000000012770` | `2026-07-15T03:31:11-04:00` | `by-file/LivingObjectPane.md` | exit `0`, `ok:1`; reference/projected-stat updates; 19 pre-existing missing-reference warnings; generated deferred. |
| `000000012771` | `2026-07-15T03:31:52-04:00` | `by-memory/-ignored.md` | exit `0`, `ok:1`; reference/projected-stat updates; 279 pre-existing missing-reference warnings in the broad ignored ledger; generated deferred. |
| `000000012772` | `2026-07-15T03:32:09-04:00` | UID0003UM target with `--wait-generated` | exit `0`, `ok:1`; generated refresh completed with matching command/timestamp; registry rebuild, generated metadata refresh, and unrelated global autogen diagnostics were validator-owned side effects. |

- At B004 waited completion, generated `auto-generated/NexusTK/ui/panels/UserPane.cpp` was SHA256 `6C9213AA2432BBBC54FF44936BECFA46307096E37450017638659B6E6AD41499`, `65,692` bytes, `1,776` lines, with header command/timestamp `000000012772` / `2026-07-15T03:32:09-04:00`. Final read-only inspection observed the newer validator-owned header `000000012773` / `2026-07-15T03:35:46-04:00`, SHA256 `5A81919A1E7AE88CB8D4ECCCCC1DF283E838BF489DC63FEEE0502E164D443222`, same byte/line counts, and unchanged target assertions.
- Generated assertions: one UID0003UM marker, one `bool UserPane::ParseInventorySlotUpdatePacket(...)` definition, zero target Empty Emitter Markers, one `void UserPane::StartDirectionalAnimation(char direction)` definition, one UserPane class definition plus one expected forward declaration, zero UID0001KM aggregate marker/body, and no duplicate target body.
- Target-block positives: one `const char inventorySlot`, one `g_activeUserStatusPane->m_inventorySlotCount`, and the accepted `itemMetaKey`, `ownerName`, `currentDurability`, and `protectionCount` uses. Target-block negatives: zero `ReadLengthPrefixedAnsiText`, zero `g_pCollectionData`, zero `secondaryText`, zero `tertiaryText`, zero `value1f0`, and zero `value1f4`.
- Destination 1 equals the installed target managed block exactly at 3,008 normalized characters. Destination 2 equals the installed UserPane managed block exactly at 9,646 normalized characters.
- B004 ran no execute, count, probe, revalidation, move, archive, or other report-lifecycle command.

## Changed Files

- `by-memory/0x005aa710-0x005aaa2c.UserPaneParseInventorySlotUpdatePacket.md` - SHA256 `A330623583077DC7DA1D5714DF9E1B6ACB5B18113489CD0C9B04833CF364CE28`, `13,610` bytes, `174` lines; target body/metadata/evidence/history applied; validators `12759`/`12772`; lease released.
- `by-class/UserPane.md` - SHA256 `A036468084585D6FCB6689686C3086A635A789F05F8908493B2C7D081B950B6B`, `58,905` bytes, `494` lines; exact Destination 2 and four fields applied while preserving B001 signed directional declaration; validator `12761`; lease released.
- `by-file/UserPane.md` - SHA256 `B1CDF3C93302004E50FC938009FF820B5CBAF73852F5C56B9D98E408D86BD957`, `63,659` bytes, `283` lines; exact opcode/packet/record/source integration; validator `12763`; lease released.
- `by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md` - SHA256 `F866B1B8E9A4F692D1445331C10E31469E149EA1EBA1EC8329541FF22CCB0629`, `100,544` bytes, `479` lines; target row/history/evidence synchronized without sibling loss; validator `12765`; lease released.
- `by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md` - SHA256 `5D175E390A63846149FBABE50646F79C75820793B2421A53F15BA56167A7B5F0`, `28,161` bytes, `144` lines; opcodes `0x0f`/`0x10` corrected without unrelated route/formal changes; validator `12767`; lease released.
- `by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md` - SHA256 `62D59CC18D642BF77EBC4C37B5C32259811636DD93B841159DACC249B6838AA0`, `17,946` bytes, `200` lines; current UserPane 52-by-`0x1fc` layout and resolved fields added; validator `12769`; lease released.
- `by-file/LivingObjectPane.md` - SHA256 `C9E5D367088D5AA64EA7649192EBA84C72BBB963C9C8B98A09F61359567F67C6`, `117,105` bytes, `416` lines; current `0x005aa710` misattribution removed and historicalized; validator `12770`; lease released.
- `by-memory/-ignored.md` - SHA256 `65777F2601D8802263B584EF5974ADBCDFE85D3BF2AF7EBB8E4EC9A4BFD5A2DE`, `1,020,251` bytes, `5,003` lines; two exact padding entries added; validator `12771`; lease released.
- `tools/leaser/Agents/Agent-B004/research/0003UM-UserPaneParseInventorySlotUpdatePacket-source-quality.md` - this same accepted report, reconciled in place; final SHA256/metrics are recorded after the terminal scan.
- Validator command `12772` refreshed generated/validator-owned outputs. B004 did not manually edit generated, manual coverage, tracker, audit, supervisor, validator-state, lifecycle, archive, IDA, goal, or agent-note files.
- `tools/leaser/Agents/Agent-B004/current_leases.md` contains no Agent-B004 row after all releases.

## Implementation Tracking Checklist

### Report Evidence Phase

- [x] Re-read UID0003UM immediately before the authorized edit; target hash/range/metadata were compared before leasing.
- [x] Re-read every support destination under its own edit window and preserved concurrent/unrelated content.
- [x] Preserved exact `[0x005aa710,0x005aaa2c)` bytes/hash evidence; callback introduced no binary uncertainty requiring a new MCP query.
- [x] Preserved dispatcher opcode `0x0f` and sole call `0x005a775c` in target, parent, and dispatcher docs.
- [x] Preserved signed slot, active UserStatusPane bound, `0x1fc` stride, and `+0x134104` base in target/class/accessor docs.
- [x] Preserved all three explicit conversions and field-consumer-supported names in target/class/accessor docs.
- [x] Preserved both padding hashes and separate clear-helper boundaries in target/parent/dispatcher/ignored docs.
- [x] Confirmed installed Destination 2 exactly preserves B001 `StartDirectionalAnimation(char direction)` plus all four C3UM fields; normalized managed-block comparison is exact.

### Implementation Phase

- [x] Leased UID0003UM only for its reread/edit/validator window.
- [x] Applied Destination 1 exactly and set target `92/94` with all other metadata preserved.
- [x] Replaced target summary/evidence and historicalized stale LivingObjectPane/spell/blank claims.
- [x] Scoped-validated UID0003UM as command `12759` and immediately released its lease; final waited revalidation is `12772`.
- [x] Leased `by-class/UserPane.md` only for its reread/edit/validator window.
- [x] Applied Destination 2 exactly, preserving B001 `StartDirectionalAnimation(char direction)`, all four C3UM fields, and unrelated class content.
- [x] Scoped-validated `by-class/UserPane.md` as command `12761` and immediately released its lease.
- [x] Updated/scoped-validated `by-file/UserPane.md` without score inflation as command `12763`; lease released.
- [x] Updated/scoped-validated UID0001KM without sibling loss as command `12765`; lease released.
- [x] Updated/scoped-validated UID0003VB bounded opcode labels/detail as command `12767`; lease released.
- [x] Updated/scoped-validated UID0003U9 current ownership/layout detail as command `12769`; lease released.
- [x] Updated/scoped-validated `by-file/LivingObjectPane.md` current-facing stale attribution as command `12770`; lease released.
- [x] Added/scoped-validated both exact ignored spans as command `12771`; lease released.
- [x] Verified global/storage/UserStatusPane/ItemHelpPane/PacketBuffer/MemoryMan/CollectionData dependencies remain unchanged.
- [x] Ran authorized waited target generated refresh `12772` only after all ordinary edits.
- [x] Verified generated UserPane.cpp contains exactly one UID0003UM marker and definition.
- [x] Verified generated UserPane.cpp contains zero UID0003UM Empty Emitter Markers.
- [x] Verified generated UID0003UM contains signed slot, active UserStatusPane bound, explicit conversions, and all resolved record names.
- [x] Verified generated target block contains zero invented `ReadLengthPrefixedAnsiText`, zero `g_pCollectionData` bound, and zero stale generic record fields.
- [x] Verified one UserPane class definition, zero UID0001KM aggregate body/marker, one target body, and preserved signed sibling C++.
- [x] Replaced every C3UM-001..046 verification state with legal terminal truth and added destination-specific claim proof.
- [x] Recorded changed paths/hashes, lease releases, validator IDs/timestamps/exits/ok/warnings/side effects, and generated header/readback.
- [x] Confirmed zero B004 leases and no forbidden manual file edit or lifecycle command.

Checklist terminal count: `31/31` checked, `0` unchecked. Ledger terminal count: `42` applied, `3` already-present, `1` excluded-with-reason, `0` proposed, `0` blocked.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000012787","destination_path":"executed-b-agent-research/B004/0003UM-UserPaneParseInventorySlotUpdatePacket-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0003UM-UserPaneParseInventorySlotUpdatePacket-source-quality.md","timestamp":"2026-07-15T03:51:26-04:00","uid":"0003UM"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
