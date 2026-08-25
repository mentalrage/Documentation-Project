** TARGET-REPORT-UID:0001KI **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001KI UserListDialogPane And UserListPane Source-Quality Research


Report path: `tools/leaser/Agents/Agent-B002/research/0001KI-UserListDialogPaneAndUserListPane-source-quality.md`

Target path: `by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md`

Assignment id: `B002-report-0001KI-user-list-dialog-pane-and-user-list-pane-source-quality-20260626`

Mode: report-only research originally; accepted implementation callback executed on 2026-06-26 after supervisor approval. During implementation I edited target/support `by-*` docs under leases, created exact child `by-memory` pages, ran scoped validators, and updated this checklist. I did not manually edit generated/project-level files, manual coverage reports, validator/tool state, IDA DB files, or any `-coverage-report.md` file.

## Finalized Report / Current Recommendation

Current recommendation: [UID:0001KI] is not one source function and should not be the permanent C++ emitter. It should become a reviewed non-emitting split/index page after exact child pages are created for the real source bodies and support artifacts. The current exact child coverage only covers the reusable `CheckBoxTextControlPane` overlap and read-only/vtable/resource data; it does not cover the main `UserListDialogPane`, `PartySearchEditPane`, `UserListPane`, comparator, source-message, and local helper bodies.

Preferred final parent metadata after the accepted split callback creates and validates replacement child pages:

```md
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep the parent formal `RECONSTRUCTION_CPP CODE` block blank. Parent-level C++ would be fake because the range contains several source methods/classes, reusable checkbox child coverage, switch tables, padding, retained no-route helper code, compiler cleanup/destructor/adjustor artifacts, and local wrappers. Exact C++ belongs on exact source-body children; this revised report supplies formal insertion blocks for code-emitting children and target-specific no-code proofs for non-emitting/artifact children.

Guard condition: do not apply the `RECONSTRUCTABLE:FALSE`/blank-emitter parent metadata until replacement source-body child pages have been created and validated. If the supervisor accepts only a text/support update and explicitly excludes split creation, keep the parent as a temporary reconstructable coverage-preserving aggregate with `CANONICAL_OWNER:0000OZ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OZ`, blank formal C++, and no score above `90/91`.

Required action after supervisor acceptance: perform the split first, using validator-assigned UIDs and temporary TMP references as required by `by-structure.md`; update the parent and support docs at report-level detail; run scoped validators for every changed/new `by-*` file. Do not edit generated reports, project-level generated files, manual coverage reports, tool state, or IDA DB files.

Confidence: high for boundaries, mixed-owner/container disposition, source-file route, global names, packet/update semantics, comparator record fields, and no-code parent proof. Confidence stays below final-audit level because original source names for several methods/fields are inferred from behavior rather than symbols, and the proposed new child pages still need validator UID registration.

## Target

- Target UID: [UID:0001KI].
- Target path: `by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md`.
- Queue source: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`.
- Generated queue state is stale: the tracker still lists [UID:0001KI] as `82/82`, while the live target page is already `87/88`.
- Current supervisor classification: report-only source-quality pass; IDA MCP mandatory; no by-* edits until callback.
- Current live metadata:
  - `COMPLETION:87`
  - `CONFIDENCE:88`
  - `CANONICAL_OWNER:0000OZ`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:0000OZ`
  - formal `RECONSTRUCTION_CPP CODE` block blank
  - current item summary: social user-list aggregate with dialog/list panes, party-search subdialog, source-message helper, comparators, destructor families, checkbox overlap, raw sizes, refs, non-padding chunks, and read-only caveats documented.

## Current Target State

The target page is stronger than the stale generated tracker. It already records a detailed covered-range table for:

- `UserListDialogPane::UserListDialogPane` at `0x0059bc90-0x0059d198`.
- Constructor cleanup/tail bytes at `0x0059d198-0x0059d1e0`.
- `nullsub_61`, sort helpers, refresh, packet handler, key/control handlers, switch-table bytes, local send helper, and `AddUserListSourceMessage`.
- Reusable `CheckBoxTextControlPane` exact children in the middle of the aggregate.
- `PartySearchEditPane` constructor/action/no-op/cleanup helpers.
- `UserListPane` constructor/destructor/draw/selection/direct-message/double-click helpers.
- Comparator helpers and no-route sort wrappers.
- Singleton clear helper, adjustor thunks, scalar deleting destructors, and final padding before [UID:0001KK].

The current defect is metadata/source-shape, not a missing headline behavior summary. The target still acts as the emitter for a broad mixed range, while its own text correctly says exact method bodies should live on precise method/range children. Those children do not yet exist for the source bodies, so the parent is carrying coverage that it should not carry permanently.

Related target/support docs checked:

- [UID:0000FN] `by-class/UserListDialogPane.md`
- [UID:0000FO] `by-class/UserListPane.md`
- [UID:0000A7] `by-class/PartySearchEditPane.md`
- [UID:0000OZ] `by-file/UserListDialogPane.md`
- [UID:00007U] `by-class/CheckBoxTextControlPane.md`
- [UID:0000L7] `by-file/SpecializedButtonPanes.md`
- [UID:0002ZX] `by-global/g_bShowHuntersListOnly.md`
- [UID:0003EI] `by-global/g_pUserListDialogPane.md`
- [UID:0001BD] `by-memory/0x0062e8fc-0x0062eccc.UserListReadOnlyData.md`
- [UID:0001BE] `by-memory/0x0062e8fc-0x0062e998.UserListDialogPaneVtableData.md`
- [UID:0001BG] `by-memory/0x0062eadc-0x0062eb9c.UserListPaneVtableData.md`
- [UID:0001BH] `by-memory/0x0062eb9c-0x0062eccc.UserListResourceStrings.md`
- [UID:0001KJ] `by-memory/0x0059ded0-0x0059f0a5.CheckBoxTextControlPaneExecutableMap.md`
- [UID:0003FH] `by-memory/0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw.md`
- `by-type/by-enum/MapServerPacketOpcode.md`
- Read-only generated context: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/-ag-memory-coverage.md`, and `auto-generated/NexusTK/social/UserListDialogPane.cpp`.
- Read-only project-level alias context: `project-level/-resolved.md` and `project-level/-unresolved.md`.
- Executed/active report leads for prior user-list and checkbox work, including B001 user-list source-quality work and B009 checkbox setter work, rechecked against current docs/MCP before use.

## Supervisor Active Recheck

The assignment explicitly required a full source-quality pass on the broad social user-list aggregate, including a fresh decision on exact child coverage, new split needs, aggregate emitter status, and target-specific no-code proof. It also required live IDA MCP evidence and prohibited fallback-only reporting.

Result:

- MCP was available and responsive.
- Exact child pages already cover reusable checkbox subranges and read-only/vtable/resource data, but not the main source bodies.
- New child pages are required before the parent can be honestly reclassified as a non-emitting index.
- The parent should remain formal-C++ blank under an explicit no-code proof.
- The parent should not remain the permanent emitter after the split is performed.

## Inference Research Guidance Check

I treated current docs, generated C++, and old B-agent reports as leads, not proof. The stale generated tracker and generated C++ header were not treated as authoritative because the live target page is already stronger and the generated output still carries old metadata. I ignored stale Wave2/Wave3 assumptions except as possible leads; no Wave2/Wave3-only claim is used as proof in this report.

IDA facts used directly: function starts/sizes, non-function starts, bytes, decompilation, disassembly, xrefs, callees, globals, vtable refs, and string/data refs.

Documentation evidence used directly: current by-* target/support pages, accepted checkbox/user-list support docs, current generated rows only as stale-state indicators, and by-structure UID/split workflow rules.

Inference used: source-facing names such as `HandleUserListPacket`, `RefreshCategoryView`, `AddUserListSourceMessage`, `SyncUserListSourceTextIntoBucket`, `g_bShowHuntersListOnly`, and `UserListRecord` field names. These are behavior-backed names, not original symbol proof.

## Evidence Checked

### Live IDA MCP

MCP session was active and healthy:

- Active session/database: `80de0a67`.
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Backend: worker.
- PID/worker PID: `26892`.
- `server_health(database='80de0a67')`: `status=ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready=true`, `hexrays_ready=true`, `strings_cache_ready=true`, strings cache size `2067`.
- Initial no-database calls returned a schema/argument error because the current MCP session requires `database`. Retried calls with `database='80de0a67'` succeeded; this was not MCP unavailability.
- Revision health recheck on 2026-06-26: lightweight JSON-RPC `tools/list` against `http://127.0.0.1:13337/mcp` returned HTTP 200 and exposed `server_health` and `idb_list`; MCP was available during the revision pass.

Function-boundary MCP checks:

- `lookup_funcs` reported `sub_59BC90` size `0x1508` at `0x0059bc90`.
- `0x0059d1a0`, `0x0059dc20`, `0x0059ded0`, `0x0059e0b0`, `0x0059e9b0`, and `0x0059e9d0` are not IDA function starts.
- Exact modeled starts inside the aggregate include `0x0059d1e0` `nullsub_61`, `0x0059d1f0`, `0x0059d250`, `0x0059d2b0`, `0x0059d620`, `0x0059d900`, `0x0059da90`, `0x0059de60`, `0x0059df30`, `0x0059df50`, `0x0059e0c0`, `0x0059e0d0`, `0x0059e3a0`, `0x0059e3c0` `nullsub_62`, `0x0059e3d0`, `0x0059e710`, `0x0059e8a0`, `0x0059e950`, `0x0059e990`, `0x0059e9f0`, `0x0059ea90`, `0x0059ed20`, `0x0059ed60`, `0x0059ee10`, `0x0059efe0`, the eight `0xb` adjustor thunks from `0x0059efeb` through `0x0059f038`, and scalar deleting destructor starts at `0x0059f050`, `0x0059f0b0`, `0x0059f110`, and `0x0059f190`.
- The next modeled function after the aggregate is `sub_59F260` at `0x0059f260`, so `0x0059f25b-0x0059f260` is final padding before [UID:0001KK].

Raw byte/boundary MCP checks:

- `get_bytes(0x0059bc8b)` showed five `0xcc` bytes before `55 8b ec`, confirming the constructor start.
- `get_bytes(0x0059d198, 72)` showed eight leading `0xcc` bytes followed by real cleanup code that stores vtables `0x0062e900`, `0x0062e960`, `0x0062e990`, conditionally deletes `this+0x288`, calls base cleanup, clears `0x0069b4e0`, and returns.
- `get_bytes(0x0059d5f8, 48)` showed refresh tail `c2 04 00`, a switch-table dword block, then `0xcc` padding before `0x0059d620`.
- `get_bytes(0x0059dbe0, 128)` showed `OnControlCommand` tail, switch-table dwords, selector bytes, padding, then executable no-route local helper code beginning at `0x0059dc20`.
- `get_bytes(0x0059e9a0, 88)` showed comparator tail, padding, exact no-route sort wrappers at `0x0059e9b0` and `0x0059e9d0`, then padding before `0x0059e9f0`.
- `get_bytes(0x0059f25b)` showed five `0xcc` bytes before `0x0059f260`.

Xref MCP checks:

- `xrefs_to(0x0059bc90)` returned four code xrefs at `0x5087f4`, `0x513c6c`, `0x5a7ccb`, and `0x5abc54`; these are user-list packet/menu dispatch consumers.
- `xrefs_to(0x0059d1a0)` and `xrefs_to(0x0059dc20)` returned no xrefs.
- `xrefs_to(0x0059de60)` returned code xrefs from `0x0059d7c2` and `0x0059eeb0`.
- `xrefs_to(0x0059e0d0)` returned a code xref from `0x0059db82`.
- `xrefs_to(0x0059e950)` returned five data refs from sort setup/wrapper sites, including the no-route status wrapper at `0x0059e9b6`.
- `xrefs_to(0x0059e990)` returned five data refs from sort setup/wrapper sites, including the no-route name wrapper at `0x0059e9d6`.
- `xrefs_to(0x0059e9b0)` and `xrefs_to(0x0059e9d0)` returned no xrefs.
- `xrefs_to(0x0059e9f0)` returned a code xref from `0x0059d7b0`.
- `xrefs_to(0x0069b4e0)` returned twelve refs across constructor publish/fallback, user-list/menu consumers, cleanup/destructor paths, and retained raw code.
- `xrefs_to(0x0069bed0)` returned six refs from constructor/filter/refresh/control-toggle paths.
- Vtable refs confirmed stores/uses around `0x0062e900`, `0x0062e99c`, `0x0062ea40`, and `0x0062eadc`.

Callee/decompilation/disassembly MCP checks:

- `callees(0x0059bc90)` confirmed constructor dependencies including repeated `0x0059e710` list-pane construction, `MultiByteToWideChar`, `_wcscpy_s`, `0x4949e0` checkbox/control construction, sort/list helpers, and UI resources.
- `callees(0x0059d620)` confirmed packet-handler calls to `0x0059e9f0`, `0x0059de60`, `0x0059d2b0`, `MultiByteToWideChar`, `_wcscpy_s`, and related list/UI helpers.
- `callees(0x0059da90)` confirmed control-command calls to `0x0059d1f0`, `0x0059d250`, `0x0059d2b0`, `0x0059e0d0`, and `0x4f4aa0`.
- `callees(0x0059e3d0)` confirmed party-search send path dependencies including `0x574bb0`, `WideCharToMultiByte`, `_wcscpy_s`, and UI helpers.
- `callees(0x0059ee10)` confirmed double-click dependencies including `0x0059de60`, `0x574bb0`, and `WideCharToMultiByte`.
- Decompilation of `0x0059e950` confirmed status comparator semantics: compare low nibble at record `+0x00c`, and if equal use dword at `+0x008` as the tie-breaker.
- Decompilation of `0x0059e990` confirmed name comparator semantics: `_wcsicmp(a1 + 7, a2 + 7)`, which is byte offset `+0x00e`.
- Decompilation of `0x0059de60` confirmed `AddUserListSourceMessage` formats `"%s > %s"` from record name at `+0x00e` and source text at `+0x210` and emits with color/style constants.
- Decompilation of `0x0059e9f0` confirmed source-text synchronization: scan by UTF-16 name at `+0x00e`, set source-present byte at `+0x20f`, and copy 256 UTF-16 characters to `+0x210`.
- Decompilation of `0x0059efe0` confirmed the singleton clear helper writes `0` to `0x0069b4e0`.
- Disassembly of `0x0059d1a0` confirmed real cleanup code even though IDA does not model a function start.
- Disassembly of `0x0059dc20` confirmed executable no-route local send helper code after `OnControlCommand` switch support.
- Disassembly of `0x0059e9b0` and `0x0059e9d0` confirmed no-route sort wrappers that call the shared sort helper with `CompareUserListRecordsByStatus` and `CompareUserListRecordsByName`.
- Decompilation of `0x0059d620` confirmed opcode/update handling for `0x83`/decimal `131` and `0x84`/decimal `132` (Verified with `int_convert.py`).
- Decompilation of `0x0059da90` confirmed close, sort change, category navigation, `PartySearchEditPane` open, and `g_bShowHuntersListOnly` toggle behavior.
- Decompilation of `0x0059e3d0` confirmed `PartySearchEditPane::OnAction` sends opcode `0x84`/decimal `132` (Verified with `int_convert.py`) and toggles the child checkbox on the secondary action.
- Decompilation of `0x0059ee10` confirmed `UserListPane::OnDoubleClick` either emits cached source text through `AddUserListSourceMessage` or sends opcode `0x85`/decimal `133` (Verified with `int_convert.py`).

String/data MCP checks:

- `get_string(0x0062eb9c)` returned `Users Dialog Pane`.
- `get_string(0x0062ec30)` returned `%s > %s`.
- `get_string(0x0062ec40)` returned `Put me on the hunters list`.
- `get_string(0x0062ec78)` returned `STAR.EPF`.
- `get_string(0x0062eca0)` returned `STAR.EPD`.
- IDA string typing was weak for several string-table entries such as `USERLIST.*`, `ICON.*`, and `kServerUserList`; current docs/raw string evidence remain better for those labels.

Numeric conversions used:

- `0x414` = decimal `1044` (Verified with `int_convert.py`).
- `0x28c` = decimal `652` (Verified with `int_convert.py`).
- `0x49c` = decimal `1180` (Verified with `int_convert.py`).
- `0x64` = decimal `100` (Verified with `int_convert.py`).
- `0x100` = decimal `256` (Verified with `int_convert.py`).
- `0x83` = decimal `131` (Verified with `int_convert.py`).
- `0x84` = decimal `132` (Verified with `int_convert.py`).
- `0x85` = decimal `133` (Verified with `int_convert.py`).
- `0x36` = decimal `54` (Verified with `int_convert.py`).
- `0x1508` = decimal `5384` (Verified with `int_convert.py`).
- `0x1f7` = decimal `503` (Verified with `int_convert.py`).

### Documentation And Generated Evidence

Generated state is stale/read-only:

- `auto-generated/-ag-research-tracker.md` still lists [UID:0001KI] as `82/82`.
- `auto-generated/-ag-coverage-report-by-memory.md` still lists [UID:0001KI] as `82%` with old summary text.
- `auto-generated/-ag-memory-coverage.md` reports [UID:0001KI] emitting through [UID:0000OZ] into `auto-generated/NexusTK/social/UserListDialogPane.cpp`.
- `auto-generated/NexusTK/social/UserListDialogPane.cpp` has `validator-command-id: 000000003210` and `validator-refreshed-at: 2026-06-26T19:38:14-04:00`, but still carries stale metadata for [UID:0000FN], [UID:0000A7], [UID:0000FO], and [UID:0001KI]. It contains class declaration material and empty emitter markers, not final method-body C++.
- `project-level/-resolved.md` still contains a stale `byte_69BED0 -> g_bShowHiddenUsers` alias line. Current by-global documentation and MCP support `g_bShowHuntersListOnly`; project-level generated/support files remain outside this B report's write scope.
- `project-level/-unresolved.md` still lists expected unresolved references including `dword_69B4E0` and offsets in [UID:0001KI]. This is read-only context, not a manual edit target.

Support doc state:

- `by-type/by-enum/MapServerPacketOpcode.md` already has the server-side `0x36` user-list dialog packet row. The outgoing `0x84` and `0x85` client messages belong in user-list/party-search docs unless a separate client-opcode enum exists.
- `g_bShowHuntersListOnly.md` is the correct current global name. The older `g_bShowHiddenUsers` alias is stale.
- `g_pUserListDialogPane.md` already documents singleton pointer xrefs and should be preserved.
- Existing checkbox exact child pages and the checkbox executable map already own the reusable checkbox control overlap.

## Heuristic / Inference Reanalysis And Validation

### Aggregate Emitter Reanalysis

Confirmed fact: [UID:0001KI] is a broad executable island, not one method or one source declaration. It spans multiple classes and several artifact categories:

- `UserListDialogPane` constructor, event handlers, sort/refresh/packet methods, and cleanup/destructor wrappers.
- `PartySearchEditPane` constructor, action handler, no-op override, cleanup, and destructor wrapper.
- `UserListPane` constructor, destructor, draw/selection/direct-message/double-click methods, and destructor wrapper.
- File-local/static comparator and source-message helpers.
- Reusable `CheckBoxTextControlPane` bodies that are already exact child pages and belong to [UID:00007U]/[UID:0000L7], not to the user-list source file as unique implementations.
- Switch-table bytes, alignment padding, and compiler-generated adjustor/deleting destructor artifacts.
- No-route local helper and wrappers that are real code but have no current caller/source route and should not be exposed as public source APIs.

Decision: the parent aggregate's permanent emitted C++ must remain blank, and after child creation the parent should be `RECONSTRUCTABLE:FALSE` with blank emitters. It should be a split/index/audit page owned by [UID:0000OZ] as the source-file grouping page.

Rejected alternative: keep [UID:0001KI] as the long-term [UID:0000OZ] emitter with blank C++. This preserves current generated coverage but leaves empty source output for a range that contains many source-authored methods. It is acceptable only as a temporary state until the split exists.

Rejected alternative: put a monolithic formal C++ block on [UID:0001KI]. That would either duplicate exact child bodies or invent a wrapper-like source function the original developers did not have.

### Exact Child Coverage Reanalysis

Existing exact child coverage inside/around the parent:

- `CheckBoxTextControlPane` constructor/teardown/paint/set/get/scalar deleting destructor exact children cover `0x0059ded0-0x0059e0c7` and `0x0059f050-0x0059f0a5`.
- `UserListReadOnlyData`, vtable, and resource-string children cover read-only/static evidence, not executable source bodies.

Missing source-body child coverage:

- No exact by-memory pages cover the `UserListDialogPane` source methods at `0x0059bc90-0x0059de60`.
- No exact by-memory pages cover the `PartySearchEditPane` source methods at `0x0059e0d0-0x0059e707`.
- No exact by-memory pages cover the `UserListPane` source methods at `0x0059e710-0x0059f25b`, except the reusable checkbox overlap.
- Comparator helpers, `AddUserListSourceMessage`, `SyncUserListSourceTextIntoBucket`, no-route wrappers, and singleton clear helper lack exact source-body pages.

Decision: new split child pages are required. UIDs are not available during report-only work; per `by-structure.md`, create the new pages first and run the validator so it assigns real UIDs, then replace TMP references in parent/support docs.

### Packet, Field, And Helper Names

Best source-facing names and field roles:

- Server packet `0x36`/decimal `54` (Verified with `int_convert.py`): `kServerUserList` / user-list dialog packet, already present in `MapServerPacketOpcode.md`.
- Dialog/packet submessage `0x83`/decimal `131` (Verified with `int_convert.py`): selected/local hunters-list flag update.
- Client/source-message update `0x84`/decimal `132` (Verified with `int_convert.py`): party-search/hunters-list source-text update, sent from `PartySearchEditPane::OnAction` and the retained local helper.
- Client source request `0x85`/decimal `133` (Verified with `int_convert.py`): `UserListPane::OnDoubleClick` source-text request for the selected user.
- `g_bShowHuntersListOnly`: correct name for byte at `0x0069bed0`; constructor/refresh/control-toggle paths prove it filters rows whose `UserListRecord::huntersListFlag` is zero.
- `g_pUserListDialogPane`: correct name for singleton pointer at `0x0069b4e0`; constructor publishes and destructor/clear paths reset it.
- `UserListRecord`: packed `0x414`/decimal `1044` row (Verified with `int_convert.py`); name at `+0x00e`, source text at `+0x210`, source-present at `+0x20f`, hunters-list flag at `+0x20e`, status/rank at `+0x00c`, arrival sort key at `+0x008`.
- `CompareUserListRecordsByStatus`: comparator at `0x0059e950`.
- `CompareUserListRecordsByName`: comparator at `0x0059e990`.
- `AddUserListSourceMessage`: helper at `0x0059de60`, formats `"%s > %s"`.
- `SyncUserListSourceTextIntoBucket`: helper at `0x0059e9f0`.

Rejected names:

- `g_bShowHiddenUsers`: stale/contradicted by current behavior and by-global docs.
- IDA labels such as `dword_69B4E0`, `byte_69BED0`, and `sub_59DE60` for source-facing docs; keep only as raw evidence aliases when needed.
- Treating `0x84` and `0x85` as server-side `MapServerPacketOpcode` rows in the existing enum file; the evidence here is for outgoing client messages.

### Raw / No-Route Code

`0x0059d1a0-0x0059d1e0`: real constructor cleanup/destructor-like code after eight `0xcc` bytes. It rewrites vtables, deletes master-list state, calls base cleanup, and clears the singleton. It should become an exact child or remain documented inside the parent as compiler cleanup/unwind-tail evidence, but it should not be emitted as a standalone public method.

`0x0059dc20-0x0059de4a`: executable local send helper after `OnControlCommand` switch support. It has no direct xrefs in current IDA and no code/data/immediate/pointer route found by the current pass. It builds/sends the same outbound `0x84` update shape, but the final disposition for this report is a no-owner, non-emitting raw helper child with blank formal C++ and a documented no-improvement proof; do not route it to [UID:0000OZ] or a class as source output.

`0x0059e9b0-0x0059e9cf` and `0x0059e9d0-0x0059e9ef`: executable no-route sort wrappers. They use `this+0x130` and call the shared sort helper with status/name comparators. Final disposition for this report is no-owner, non-emitting raw wrapper children with blank formal C++ and documented no-improvement proof; do not expose them as public APIs or class methods.

Adjustor thunks and scalar deleting destructor wrappers should not become source-authored method bodies. They are compiler-generated outputs caused by class declarations/destructors and should remain blank-C++ children or ignored/false artifacts as appropriate.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| [UID:0001KI] is mixed/overbroad and not a single source function. | Confirmed | MCP function map, byte ranges, support docs, checkbox overlap, vtable/destructor/adjustor artifacts. | Checked exact child pages and generated output; no monolithic source body found. | None for parent no-code disposition. |
| Existing exact children do not cover the main user-list source bodies. | Confirmed | `rg`/doc review found only checkbox exact children and read-only/vtable/resource children for this island. | Target's own range map and generated C++ checked; no exact method pages for main bodies. | UIDs for new children are unavailable until validator registration. |
| Parent should become non-emitting after replacement children exist. | Strong | By-structure split rules; parent spans several classes, helpers, tables, padding, and compiler artifacts. | Keeping parent as permanent emitter would preserve coverage but empty output; monolithic C++ rejected. | Reclassification is coupled to child creation. |
| [UID:0000OZ] remains the source-file route/grouping owner. | Strong | Dispatch callers, source-tree grouping, support docs, generated route, class family cohesion. | Class-only ownership rejected because parent spans multiple classes and file-local/static helpers. | Exact original file basename not symbol-proven, but current by-file route is best. |
| `g_bShowHuntersListOnly` is the correct global name for `0x0069bed0`. | Strong | Constructor/refresh/control-toggle xrefs and by-global doc; behavior filters hunters-list rows. | Stale `g_bShowHiddenUsers` alias rejected. | Original spelling not symbol-proven. |
| `UserListRecord` field offsets are stable enough for source docs. | Strong | Constructor, comparators, draw, source-message, sync, and packet handlers agree on offsets. | Decompiler local names ignored; offsets cross-checked with behavior. | Exact original struct/field spellings inferred. |
| The no-route helper/wrappers are real code but should not emit public source APIs. | Strong | Raw bytes/disassembly show executable code; xrefs to starts absent; code/data/immediate/pointer-byte route checks were negative for `0x0059dc20`, `0x0059e9b0`, and `0x0059e9d0`; broad operand scan timed out once and MCP health recovered. | Checked xrefs, code refs, data refs, immediate target searches, pointer-byte searches, surrounding switch/padding bytes, and MCP health after the heavy timeout. | Closed for this report: no-owner/non-emitting raw child pages, blank formal C++, no public method/helper route. |

## Ranked Ownership Analysis

### 1. [UID:0000OZ] UserListDialogPane source file

Evidence for:

- The aggregate is a cohesive social user-list source-file island: dialog, list pane, party-search subdialog, comparators, local helpers, globals, strings, and vtables all serve the same feature.
- Generated output currently routes [UID:0001KI] through [UID:0000OZ].
- Class support docs for [UID:0000FN], [UID:0000FO], and [UID:0000A7] are all part of the same source family.
- The parent index needs one owner for the split page; file-level [UID:0000OZ] is narrower than a generic social subsystem and broader than any one class.

Evidence against:

- [UID:0001KI] spans multiple classes and generic checkbox overlap; [UID:0000OZ] should not emit one monolithic body.

Decision: keep [UID:0000OZ] as the parent split/index owner/source route. After split creation, blank [UID:0001KI]'s emitters and assign exact child emitters to [UID:0000OZ] only where their own metadata clears the gate.

### 2. Class owners [UID:0000FN], [UID:0000FO], [UID:0000A7]

Evidence for:

- Individual methods clearly belong to `UserListDialogPane`, `UserListPane`, and `PartySearchEditPane`.
- Vtable refs and constructor/destructor patterns identify the class boundaries.

Evidence against:

- No single class owns the whole [UID:0001KI] range.
- File-local/static helpers and compiler artifacts do not belong as public class methods.

Decision: use class UIDs as canonical owners for exact method child pages, not for the parent aggregate.

### 3. [UID:00007U] / [UID:0000L7] CheckBoxTextControlPane / SpecializedButtonPanes

Evidence for:

- Existing exact child pages cover `CheckBoxTextControlPane` constructor/paint/set/get/destructor subranges inside the aggregate.
- Support docs already own reusable checkbox control behavior.

Evidence against:

- Checkbox code is only an overlap inside [UID:0001KI]; it does not own the user-list feature.

Decision: leave checkbox exact children/support docs unchanged unless implementation finds a direct contradiction. Parent should keep links/caveats only.

### 4. Dispatch consumers such as MapPane/UserPane/LivingObjectPane

Evidence for:

- User-list constructor has callers from map/user/menu dispatch paths.

Evidence against:

- Those callers allocate or dispatch to the user-list UI; they do not own the UI source bodies.

Decision: consumers only. Do not move ownership.

### 5. No owner / raw-only parent

Evidence for:

- Some subranges are no-route raw helpers, wrappers, switch tables, padding, or compiler artifacts.

Evidence against:

- The parent as a source-file index has a clear feature route through [UID:0000OZ].

Decision: do not set parent `CANONICAL_OWNER:NONE`; set parent `RECONSTRUCTABLE:FALSE` after split and leave emitters blank.

## Source Placement

Recommended placement:

- Parent/index: [UID:0000OZ] `by-file/UserListDialogPane.md`.
- `UserListDialogPane` methods: owner [UID:0000FN], emitter [UID:0000OZ].
- `PartySearchEditPane` methods: owner [UID:0000A7], emitter [UID:0000OZ].
- `UserListPane` methods: owner [UID:0000FO], emitter [UID:0000OZ].
- Static/file-local helper/comparator children: owner [UID:0000OZ], emitter [UID:0000OZ] when route/score permits; no-route raw wrappers remain blank-emitter until resolved.
- Reusable checkbox children: keep [UID:00007U]/[UID:0000L7] ownership/emission already established.

Rejected placements:

- `SpecializedButtonPanes.cpp` for user-list code: only the reusable checkbox overlap belongs there.
- `MapPane`/`UserPane`: consumers only.
- A new one-off raw source file for [UID:0001KI]: the feature already has the [UID:0000OZ] file route.
- Parent-level monolithic emitted C++ in [UID:0000OZ]: rejected as non-source-shaped.

## Range / Split / Padding / Reclassification Analysis

The implementation callback should create exact child pages first, validate them so the validator assigns real UIDs, then update [UID:0001KI] to use real UID links and become the non-emitting parent/index. Report-only planning allowed temporary child-path references before the child UIDs existed; the implementation callback replaced live parent/support references with real UIDs.

Recommended parent after split:

- [UID:0001KI] `by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md`
- `COMPLETION:90`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:0000OZ`
- `RECONSTRUCTABLE:FALSE`
- `EMITTER_UIDS:` blank
- formal C++ blank
- `Item Summary`: `MCP-reviewed social user-list split index over dialog/list/party-search method bodies, checkbox-control overlap, comparator/source-message helpers, switch tables, padding, no-route wrappers, globals, and compiler destructor/adjustor artifacts; exact child ranges and aggregate no-code proof documented.`

Recommended child/split table, revised for implementation acceptance:

UIDs are validator-assigned during implementation. Before assignment, parent/support references must use temporary child-path references; after this callback, live parent/support references use real UIDs. Each row below gives the exact metadata values and `Item Summary` disposition to create. Code-emitting rows use [UID:0000OZ] as the emitter and have exact formal C++ blocks in the next section. Non-emitting rows intentionally have blank `EMITTER_UIDS` and a child-specific no-code proof; they are not blank placeholder pages.

| Range | Proposed child file | Exact metadata to create | Exact `Item Summary` / C++ disposition |
| --- | --- | --- | --- |
| `0x0059bc90-0x0059d198` | `by-memory/0x0059bc90-0x0059d198.UserListDialogPaneConstructor.md` | `COMPLETION:86`; `CONFIDENCE:90`; `CANONICAL_OWNER:0000FN`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:` blank | `UserListDialogPane constructor body: constructs dialog/user-list controls, initializes category/filter state, builds five UserListPane buckets, converts initial user names into UserListRecord rows, publishes g_pUserListDialogPane, and sorts/refreshes the user-list UI.` Formal C++ blank. No-code proof: exact body emission would require declaring the constructor's full UI member layout and child-control construction API that are outside this child page; a partial constructor would invent declarations not yet present in support docs. |
| `0x0059d198-0x0059d1e0` | `by-memory/0x0059d198-0x0059d1e0.UserListDialogPaneConstructorCleanupTail.md` | `COMPLETION:86`; `CONFIDENCE:90`; `CANONICAL_OWNER:0000FN`; `RECONSTRUCTABLE:FALSE`; `EMITTER_UIDS:` blank | `Compiler cleanup/destructor-tail bytes after UserListDialogPane constructor failure path: restores vtables, deletes master-list state, calls base cleanup, clears g_pUserListDialogPane, and returns through generated unwind code.` Formal C++ blank; compiler cleanup artifact, not a standalone source API. |
| `0x0059d1e0-0x0059d1e3` | `by-memory/0x0059d1e0-0x0059d1e3.UserListDialogPaneNullsub61.md` | `COMPLETION:88`; `CONFIDENCE:91`; `CANONICAL_OWNER:0000FN`; `RECONSTRUCTABLE:FALSE`; `EMITTER_UIDS:` blank | `No-op function/nullsub in the UserListDialogPane executable island.` Formal C++ blank; no source behavior beyond the compiler/source placeholder no-op. |
| `0x0059d1f0-0x0059d24f` | `by-memory/0x0059d1f0-0x0059d24f.UserListDialogPaneSortListsByStatus.md` | `COMPLETION:88`; `CONFIDENCE:90`; `CANONICAL_OWNER:0000FN`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:0000OZ` | `UserListDialogPane::SortListsByStatus loops over five bucket panes, sorts each by CompareUserListRecordsByStatus, and invalidates the refreshed pane bounds.` Formal C++ block required from this report. |
| `0x0059d250-0x0059d2af` | `by-memory/0x0059d250-0x0059d2af.UserListDialogPaneSortListsByName.md` | `COMPLETION:88`; `CONFIDENCE:90`; `CANONICAL_OWNER:0000FN`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:0000OZ` | `UserListDialogPane::SortListsByName loops over five bucket panes, sorts each by CompareUserListRecordsByName, and invalidates the refreshed pane bounds.` Formal C++ block required from this report. |
| `0x0059d2b0-0x0059d5fe` | `by-memory/0x0059d2b0-0x0059d5fe.UserListDialogPaneRefreshCategoryView.md` | `COMPLETION:86`; `CONFIDENCE:90`; `CANONICAL_OWNER:0000FN`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:` blank | `UserListDialogPane::RefreshCategoryView clamps category-page navigation, derives selected category/career state, clears five bucket panes, filters hunters-list rows through g_bShowHuntersListOnly and UserListRecord::huntersListFlag, redistributes rows, sorts buckets, and updates category/count labels.` Formal C++ blank. No-code proof: MCP confirms behavior, but exact method emission would require the page to define category tables, label/control fields, and list-row insertion helpers not yet declared at support level; a compact source body would omit material binary behavior. |
| `0x0059d5fe-0x0059d620` | `by-memory/0x0059d5fe-0x0059d620.UserListDialogPaneRefreshCategorySwitchTable.md` | `COMPLETION:87`; `CONFIDENCE:91`; `CANONICAL_OWNER:0000FN`; `RECONSTRUCTABLE:FALSE`; `EMITTER_UIDS:` blank | `Switch-table/tail data and alignment following UserListDialogPane::RefreshCategoryView.` Formal C++ blank; compiler-generated jump-table/padding bytes. |
| `0x0059d620-0x0059d8f5` | `by-memory/0x0059d620-0x0059d8f5.UserListDialogPaneHandleUserListPacket.md` | `COMPLETION:86`; `CONFIDENCE:90`; `CANONICAL_OWNER:0000FN`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:` blank | `UserListDialogPane::HandleUserListPacket handles user-list submessages 0x83 and 0x84: updates the local hunters-list flag and checkbox state, invalidates controls, mirrors the local UserListRecord flag/source text, synchronizes bucket source text, adds source messages, and refreshes categories.` Formal C++ blank. No-code proof: packet parsing, string conversion, row lookup, and helper calls are documented, but exact formal code would require packet-buffer helper declarations and local row iteration APIs outside the current child/support declarations. |
| `0x0059d900-0x0059da82` | `by-memory/0x0059d900-0x0059da82.UserListDialogPaneOnKeyEvent.md` | `COMPLETION:86`; `CONFIDENCE:90`; `CANONICAL_OWNER:0000FN`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:` blank | `UserListDialogPane::OnKeyEvent handles PageUp/PageDown category navigation and Ctrl+C selected-name copy across the five user-list panes, otherwise forwarding to the base key handler.` Formal C++ blank. No-code proof: behavior is known, but exact source insertion depends on the clipboard/copy helper class and key-event layout not declared on the current support pages. |
| `0x0059da90-0x0059dbe3` | `by-memory/0x0059da90-0x0059dbe3.UserListDialogPaneOnControlCommand.md` | `COMPLETION:87`; `CONFIDENCE:90`; `CANONICAL_OWNER:0000FN`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:0000OZ` | `UserListDialogPane::OnControlCommand handles close, sort mode, category navigation, PartySearchEditPane open, and hunters-list filter toggle controls.` Formal C++ block required from this report. |
| `0x0059dbe3-0x0059dc20` | `by-memory/0x0059dbe3-0x0059dc20.UserListDialogPaneOnControlCommandSwitchTable.md` | `COMPLETION:87`; `CONFIDENCE:91`; `CANONICAL_OWNER:0000FN`; `RECONSTRUCTABLE:FALSE`; `EMITTER_UIDS:` blank | `Switch-table selector bytes and alignment after UserListDialogPane::OnControlCommand.` Formal C++ blank; compiler-generated table/padding bytes. |
| `0x0059dc20-0x0059de4a` | `by-memory/0x0059dc20-0x0059de4a.UserListDialogPaneLocalSourceUpdateSendHelperRaw.md` | `COMPLETION:84`; `CONFIDENCE:90`; `CANONICAL_OWNER:NONE`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:` blank | `No-route local source-update send helper: reads g_pUserListDialogPane-local state, finds the local UserListRecord, mirrors hunters/source-text fields, builds outbound 0x84 update payload, and sends it through the client packet sender.` Formal C++ blank. No-improvement proof: `xrefs_to`, code-ref, data-ref, immediate, and pointer-byte searches for `0x0059dc20` were negative; broad operand scan timed out once and MCP health recovered; no current caller/source route is safe, so no owner/emitter assignment is made. |
| `0x0059de60-0x0059decf` | `by-memory/0x0059de60-0x0059decf.AddUserListSourceMessage.md` | `COMPLETION:88`; `CONFIDENCE:91`; `CANONICAL_OWNER:0000OZ`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:0000OZ` | `File-local AddUserListSourceMessage helper formats "name > sourceText" from UserListRecord and writes it to the chatting display pane using the observed color/style constants.` Formal C++ block required from this report. |
| `0x0059e0d0-0x0059e393` | `by-memory/0x0059e0d0-0x0059e393.PartySearchEditPaneConstructor.md` | `COMPLETION:86`; `CONFIDENCE:90`; `CANONICAL_OWNER:0000A7`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:` blank | `PartySearchEditPane constructor builds the hunters-list/search dialog, text control, checkbox text control, labels/buttons, and initial state from g_pUserListDialogPane.` Formal C++ blank. No-code proof: exact emission depends on child-control construction APIs and member layout not currently declared for [UID:0000A7]. |
| `0x0059e3a0-0x0059e3bf` | `by-memory/0x0059e3a0-0x0059e3bf.PartySearchEditPaneCleanupHelper.md` | `COMPLETION:86`; `CONFIDENCE:90`; `CANONICAL_OWNER:0000A7`; `RECONSTRUCTABLE:FALSE`; `EMITTER_UIDS:` blank | `PartySearchEditPane cleanup/reset helper generated around child-control teardown.` Formal C++ blank; not a standalone source-authored method body. |
| `0x0059e3c0-0x0059e3c1` | `by-memory/0x0059e3c0-0x0059e3c1.PartySearchEditPaneOnDestroyChildControlsNoop.md` | `COMPLETION:88`; `CONFIDENCE:91`; `CANONICAL_OWNER:0000A7`; `RECONSTRUCTABLE:FALSE`; `EMITTER_UIDS:` blank | `PartySearchEditPane no-op destroy-child-controls override/nullsub.` Formal C++ blank; no behavior to emit. |
| `0x0059e3d0-0x0059e707` | `by-memory/0x0059e3d0-0x0059e707.PartySearchEditPaneOnAction.md` | `COMPLETION:86`; `CONFIDENCE:90`; `CANONICAL_OWNER:0000A7`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:` blank | `PartySearchEditPane::OnAction closes on action 1, reads checkbox/text controls, writes g_pUserListDialogPane local source state, mirrors the local UserListRecord, builds outbound 0x84 packet, and toggles the checkbox on action 2.` Formal C++ blank. No-code proof: exact packet-builder/text-control source needs support declarations not present on the class page; behavior is documented without emitting incomplete code. |
| `0x0059e710-0x0059e899` | `by-memory/0x0059e710-0x0059e899.UserListPaneConstructor.md` | `COMPLETION:86`; `CONFIDENCE:90`; `CANONICAL_OWNER:0000FO`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:` blank | `UserListPane constructor initializes the base list pane, vtables, star/status/badge frame arrays, STAR/ICON resources selected by the high-resolution flag, and sibling-pane routing fields.` Formal C++ blank. No-code proof: exact emission requires frame-array member declarations and resource wrapper types not present in [UID:0000FO]. |
| `0x0059e8a0-0x0059e943` | `by-memory/0x0059e8a0-0x0059e943.UserListPaneDestructor.md` | `COMPLETION:86`; `CONFIDENCE:90`; `CANONICAL_OWNER:0000FO`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:` blank | `UserListPane destructor restores vtables, tears down star/status/badge frame arrays, destroys the final frame, and calls the base list-pane destructor.` Formal C++ blank. No-code proof: exact destructor code depends on the same undeclared frame-array member layout as the constructor. |
| `0x0059e950-0x0059e983` | `by-memory/0x0059e950-0x0059e983.CompareUserListRecordsByStatus.md` | `COMPLETION:90`; `CONFIDENCE:92`; `CANONICAL_OWNER:0000OZ`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:0000OZ` | `File-local status comparator: compares UserListRecord::statusIconId low nibble and uses arrivalSortKey as the tie-breaker.` Formal C++ block required from this report. |
| `0x0059e990-0x0059e9a6` | `by-memory/0x0059e990-0x0059e9a6.CompareUserListRecordsByName.md` | `COMPLETION:90`; `CONFIDENCE:92`; `CANONICAL_OWNER:0000OZ`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:0000OZ` | `File-local name comparator: case-insensitive compare of UserListRecord::name at byte offset +0x00e.` Formal C++ block required from this report. |
| `0x0059e9b0-0x0059e9cf` | `by-memory/0x0059e9b0-0x0059e9cf.UserListPaneSortByStatusNoRouteWrapper.md` | `COMPLETION:84`; `CONFIDENCE:90`; `CANONICAL_OWNER:NONE`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:` blank | `No-route wrapper that loads the list storage at this+0x130 and invokes the shared sort helper with CompareUserListRecordsByStatus.` Formal C++ blank. No-improvement proof: `xrefs_to`, code-ref, data-ref, immediate, and pointer-byte searches for `0x0059e9b0` were negative; no current route supports class/file ownership or emission. |
| `0x0059e9d0-0x0059e9ef` | `by-memory/0x0059e9d0-0x0059e9ef.UserListPaneSortByNameNoRouteWrapper.md` | `COMPLETION:84`; `CONFIDENCE:90`; `CANONICAL_OWNER:NONE`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:` blank | `No-route wrapper that loads the list storage at this+0x130 and invokes the shared sort helper with CompareUserListRecordsByName.` Formal C++ blank. No-improvement proof: `xrefs_to`, code-ref, data-ref, immediate, and pointer-byte searches for `0x0059e9d0` were negative; no current route supports class/file ownership or emission. |
| `0x0059e9f0-0x0059ea8f` | `by-memory/0x0059e9f0-0x0059ea8f.SyncUserListSourceTextIntoBucket.md` | `COMPLETION:88`; `CONFIDENCE:91`; `CANONICAL_OWNER:0000OZ`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:0000OZ` | `File-local SyncUserListSourceTextIntoBucket scans a UserListPane by name, marks source text present, and copies 256 UTF-16 source characters from the source UserListRecord.` Formal C++ block required from this report. |
| `0x0059ea90-0x0059ed18` | `by-memory/0x0059ea90-0x0059ed18.UserListPaneDrawUserEntry.md` | `COMPLETION:86`; `CONFIDENCE:90`; `CANONICAL_OWNER:0000FO`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:` blank | `UserListPane::DrawUserEntry renders one user row, including selected/source state, hunters-list flag, status/star icon selection, badge icons, text color, and row decorations.` Formal C++ blank. No-code proof: drawing coordinates, image-frame APIs, color constants, and base list drawing contracts are not fully declared in support docs, so emitted code would be incomplete. |
| `0x0059ed20-0x0059ed5e` | `by-memory/0x0059ed20-0x0059ed5e.UserListPaneOnItemSelected.md` | `COMPLETION:87`; `CONFIDENCE:90`; `CANONICAL_OWNER:0000FO`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:0000OZ` | `UserListPane::OnItemSelected clears selection on sibling panes and selects the current row.` Formal C++ block required from this report. |
| `0x0059ed60-0x0059ee0c` | `by-memory/0x0059ed60-0x0059ee0c.UserListPaneOpenSayToUserMessageInputPane.md` | `COMPLETION:87`; `CONFIDENCE:90`; `CANONICAL_OWNER:0000FO`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:0000OZ` | `UserListPane::OpenSayToUserMessageInputPane opens the direct-message input pane for the selected user after closing the user-list dialog, choosing the high/low resource constructor path from the display-resource flag.` Formal C++ block required from this report. |
| `0x0059ee10-0x0059efd0` | `by-memory/0x0059ee10-0x0059efd0.UserListPaneOnDoubleClick.md` | `COMPLETION:87`; `CONFIDENCE:90`; `CANONICAL_OWNER:0000FO`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:0000OZ` | `UserListPane::OnDoubleClick handles left double-click selection: cached source text is sent to chat, otherwise it builds outbound 0x85 source-request packet for hunters-list rows.` Formal C++ block required from this report. |
| `0x0059efe0-0x0059efeb` | `by-memory/0x0059efe0-0x0059efeb.ClearUserListDialogPaneSingleton.md` | `COMPLETION:90`; `CONFIDENCE:92`; `CANONICAL_OWNER:0000OZ`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:0000OZ` | `File-local ClearUserListDialogPaneSingleton helper clears g_pUserListDialogPane.` Formal C++ block required from this report. |
| `0x0059efeb-0x0059f043` | `by-memory/0x0059efeb-0x0059f043.UserListFeatureAdjustorThunks.md` | `COMPLETION:87`; `CONFIDENCE:91`; `CANONICAL_OWNER:0000OZ`; `RECONSTRUCTABLE:FALSE`; `EMITTER_UIDS:` blank | `Compiler-generated adjustor thunk block for PartySearchEditPane, UserListDialogPane, and UserListPane virtual dispatch cleanup paths.` Formal C++ blank; generated by class declarations/vtables, not handwritten source. |
| `0x0059f0b0-0x0059f105` | `by-memory/0x0059f0b0-0x0059f105.PartySearchEditPaneScalarDeletingDestructor.md` | `COMPLETION:87`; `CONFIDENCE:91`; `CANONICAL_OWNER:0000A7`; `RECONSTRUCTABLE:FALSE`; `EMITTER_UIDS:` blank | `Compiler-generated PartySearchEditPane scalar deleting destructor wrapper around the real destructor/base cleanup and optional delete.` Formal C++ blank; wrapper is compiler output. |
| `0x0059f110-0x0059f181` | `by-memory/0x0059f110-0x0059f181.UserListDialogPaneScalarDeletingDestructor.md` | `COMPLETION:87`; `CONFIDENCE:91`; `CANONICAL_OWNER:0000FN`; `RECONSTRUCTABLE:FALSE`; `EMITTER_UIDS:` blank | `Compiler-generated UserListDialogPane scalar deleting destructor wrapper that includes object cleanup, singleton clear, base cleanup, and optional delete.` Formal C++ blank; source destructor semantics are documented on class/method support, not emitted as this wrapper. |
| `0x0059f190-0x0059f25b` | `by-memory/0x0059f190-0x0059f25b.UserListPaneScalarDeletingDestructor.md` | `COMPLETION:87`; `CONFIDENCE:91`; `CANONICAL_OWNER:0000FO`; `RECONSTRUCTABLE:FALSE`; `EMITTER_UIDS:` blank | `Compiler-generated UserListPane scalar deleting destructor wrapper around UserListPane destruction and optional delete.` Formal C++ blank; wrapper is compiler output. |

Existing checkbox exact children remain unchanged:

- [UID:0003FE] `0x0059ded0-0x0059df27.CheckBoxTextControlPaneConstructorRaw`
- [UID:0003FF] `0x0059df30-0x0059df4f.CheckBoxTextControlPaneTeardownHelper`
- [UID:0003FG] `0x0059df50-0x0059e0ac.CheckBoxTextControlPaneOnPaint`
- [UID:0003FH] `0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw`
- [UID:0003FI] `0x0059e0c0-0x0059e0c7.CheckBoxTextControlPaneGetChecked`
- [UID:0003FJ] `0x0059f050-0x0059f0a5.CheckBoxTextControlPaneScalarDeletingDestructor`

Padding/alignment rows already documented by [UID:0001KI] do not need standalone child pages unless the validator/supervisor requires every parent subrange to be file-backed. Keep them in the parent range table.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits are requested or allowed for this report.

Source-facing names to preserve in docs:

- `g_bShowHuntersListOnly` for `0x0069bed0`.
- `g_pUserListDialogPane` for `0x0069b4e0`.
- `g_useEpfAssets` for `0x0066da97`, used here as the EPF/EPD resource-mode branch for `UserListPane` resources and direct-message pane selection.
- `UserListRecord` as the packed `0x414` row type.
- `CompareUserListRecordsByStatus`.
- `CompareUserListRecordsByName`.
- `AddUserListSourceMessage`.
- `SyncUserListSourceTextIntoBucket`.
- `PartySearchEditPane::OnAction`.
- `UserListPane::OpenSayToUserMessageInputPane`.

Names intentionally left descriptive/inferred:

- `RefreshCategoryView`, `HandleUserListPacket`, `OnControlCommand`, and `OnKeyEvent` are behavior-backed but not symbol-proven.
- `UserListDialogPaneLocalSourceUpdateSendHelperRaw` is a conservative raw-helper page name because no direct route to `0x0059dc20` was found.
- No-route sort wrapper names should keep `NoRouteWrapper` because this pass found no caller route.

## First-Draft C++ Recommendation

Eligible for draft C++ on [UID:0001KI]: no.

Reason target formal C++ must remain blank:

1. The target is not one original source function, class declaration, or standalone helper.
2. It crosses `UserListDialogPane`, `PartySearchEditPane`, `UserListPane`, file-local/static helpers, reusable checkbox-control child pages, switch-table bytes, padding, no-route wrappers, scalar deleting destructors, and adjustor thunks.
3. Existing exact child pages already own the checkbox overlap; parent C++ would duplicate or obscure that ownership.
4. New exact method children are required for the source-authored bodies. Parent C++ would either duplicate exact child bodies or invent a decompiler-shaped aggregate wrapper.
5. Compiler-generated deleting destructors, adjustor thunks, switch tables, and padding are not handwritten C++ bodies.
6. No-route helper/wrapper code should not be exposed as public source APIs without a route/source-role proof.

Exact parent no-code proof to incorporate into [UID:0001KI]:

`No formal C++ is emitted from this parent because this range is a mixed social user-list split index, not one source function. It contains UserListDialogPane, PartySearchEditPane, UserListPane, file-local helpers, reusable CheckBoxTextControlPane child coverage, switch-table bytes, padding, no-route wrappers, singleton cleanup, scalar deleting destructors, and adjustor thunks. Exact method/helper C++ belongs on precise child pages. This parent remains a documentation/index container after those children exist and validate.`

Formal child C++ disposition:

- Code-emitting children in the revised split table must receive the exact formal `RECONSTRUCTION_CPP CODE` insertion content below. These are not illustrative snippets.
- Non-emitting source-authored children must keep formal C++ blank and use the no-code proofs in the revised split table.
- Compiler-generated cleanup/switch/padding/adjustor/scalar-deleting rows must keep formal C++ blank and `RECONSTRUCTABLE:FALSE`.
- No-route raw helper/wrapper children must keep `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, blank formal C++, and the no-improvement proof in the revised split table.

### Formal C++ Blocks For Code-Emitting Children

#### `by-memory/0x0059d1f0-0x0059d24f.UserListDialogPaneSortListsByStatus.md`

Use this exact formal `RECONSTRUCTION_CPP CODE` block:

```cpp
void UserListDialogPane::SortListsByStatus()
{
    for (int index = 0; index < 5; ++index)
    {
        UserListPane *pane = m_bucketPanes[index];
        pane->SortRecords(CompareUserListRecordsByStatus);
        pane->Invalidate();
    }
}
```

#### `by-memory/0x0059d250-0x0059d2af.UserListDialogPaneSortListsByName.md`

Use this exact formal `RECONSTRUCTION_CPP CODE` block:

```cpp
void UserListDialogPane::SortListsByName()
{
    for (int index = 0; index < 5; ++index)
    {
        UserListPane *pane = m_bucketPanes[index];
        pane->SortRecords(CompareUserListRecordsByName);
        pane->Invalidate();
    }
}
```

#### `by-memory/0x0059da90-0x0059dbe3.UserListDialogPaneOnControlCommand.md`

Use this exact formal `RECONSTRUCTION_CPP CODE` block:

```cpp
void UserListDialogPane::OnControlCommand(unsigned int controlId)
{
    switch (controlId)
    {
    case 1:
        Close();
        RemoveFromPaneManager();
        break;

    case 3:
        if (m_sortControl->GetSelection() == 0)
        {
            SortListsByStatus();
        }
        else if (m_sortControl->GetSelection() == 1)
        {
            SortListsByName();
        }
        Invalidate();
        break;

    case 0x10:
        RefreshCategoryView(1);
        break;

    case 0x13:
        RefreshCategoryView(-1);
        break;

    case 0x14:
        new PartySearchEditPane(this);
        break;

    case 0x15:
        g_bShowHuntersListOnly = !g_bShowHuntersListOnly;
        m_huntersListOnlyCheckBox->SetChecked(g_bShowHuntersListOnly);
        m_huntersListOnlyCheckBox->Invalidate();
        RefreshCategoryView(0);
        break;
    }
}
```

#### `by-memory/0x0059de60-0x0059decf.AddUserListSourceMessage.md`

Use this exact formal `RECONSTRUCTION_CPP CODE` block:

```cpp
void AddUserListSourceMessage(const UserListRecord *record)
{
    if (g_pChattingDisplayPane == 0)
        return;

    wchar_t message[520];
    wsprintfW(message, L"%s > %s", record->name, record->sourceText);
    g_pChattingDisplayPane->AddChattingMessage(message, 143, 128, 0, 0, 0);
}
```

#### `by-memory/0x0059e950-0x0059e983.CompareUserListRecordsByStatus.md`

Use this exact formal `RECONSTRUCTION_CPP CODE` block:

```cpp
int __cdecl CompareUserListRecordsByStatus(const UserListRecord *left, const UserListRecord *right)
{
    const int rightStatus = right->statusIconId & 0x0f;
    const int leftStatus = left->statusIconId & 0x0f;

    if (rightStatus == leftStatus)
        return right->arrivalSortKey - left->arrivalSortKey;

    return rightStatus - leftStatus;
}
```

#### `by-memory/0x0059e990-0x0059e9a6.CompareUserListRecordsByName.md`

Use this exact formal `RECONSTRUCTION_CPP CODE` block:

```cpp
int __cdecl CompareUserListRecordsByName(const UserListRecord *left, const UserListRecord *right)
{
    return _wcsicmp(left->name, right->name);
}
```

#### `by-memory/0x0059e9f0-0x0059ea8f.SyncUserListSourceTextIntoBucket.md`

Use this exact formal `RECONSTRUCTION_CPP CODE` block:

```cpp
void SyncUserListSourceTextIntoBucket(UserListPane *pane, const UserListRecord *sourceRecord)
{
    const int count = pane->GetRecordCount();

    for (int index = 0; index < count; ++index)
    {
        UserListRecord *record = pane->GetRecordAt(index);

        if (_wcsicmp(record->name, sourceRecord->name) != 0)
            continue;

        record->hasSourceText = 1;
        wcscpy_s(record->sourceText, 256, sourceRecord->sourceText);
    }
}
```

#### `by-memory/0x0059ed20-0x0059ed5e.UserListPaneOnItemSelected.md`

Use this exact formal `RECONSTRUCTION_CPP CODE` block:

```cpp
void UserListPane::OnItemSelected(int itemIndex)
{
    for (int index = 0; index < m_siblingPaneCount; ++index)
        m_siblingPanes[index]->SetSelection(-1, false);

    SetSelection(itemIndex, false);
}
```

#### `by-memory/0x0059ed60-0x0059ee0c.UserListPaneOpenSayToUserMessageInputPane.md`

Use this exact formal `RECONSTRUCTION_CPP CODE` block:

```cpp
void UserListPane::OpenSayToUserMessageInputPane()
{
    UserListRecord *record = GetSelectedRecord();
    if (record == 0)
        return;

    ClosePane(g_pUserListDialogPane);

    if (g_useEpfAssets)
        new NewSayToUserMessageInputPane(record->name);
    else
        new SayToUserMessageInputPane(record->name);
}
```

#### `by-memory/0x0059ee10-0x0059efd0.UserListPaneOnDoubleClick.md`

Use this exact formal `RECONSTRUCTION_CPP CODE` block:

```cpp
bool UserListPane::OnDoubleClick(const MouseEvent &event)
{
    if (!event.IsLeftDoubleClick() || !ContainsPoint(event.x, event.y))
        return ListPane::OnMouseEvent(event);

    const int itemIndex = HitTestItem(event.x, event.y);
    if (itemIndex < 0)
        return false;

    UserListRecord *record = GetRecordAt(itemIndex);
    if (record == 0 || record->huntersListFlag == 0)
        return false;

    if (record->hasSourceText && g_pUserListDialogPane != 0)
    {
        AddUserListSourceMessage(record);
        return true;
    }

    char name[256];
    const int nameLength = WideCharToMultiByte(CP_ACP, 0, record->name, -1, name, sizeof(name), 0, 0);
    if (nameLength <= 0)
        return true;

    unsigned char packet[258];
    packet[0] = 0x85;
    packet[1] = static_cast<unsigned char>(nameLength - 1);
    memcpy(&packet[2], name, nameLength - 1);
    SendMapPacket(packet, nameLength + 1);
    return true;
}
```

#### `by-memory/0x0059efe0-0x0059efeb.ClearUserListDialogPaneSingleton.md`

Use this exact formal `RECONSTRUCTION_CPP CODE` block:

```cpp
void ClearUserListDialogPaneSingleton()
{
    g_pUserListDialogPane = 0;
}
```

## Final Recommendation

1. Create exact child pages for the ranges listed in the split table, using validator-assigned UIDs. Use TMP references until UIDs exist.
2. Convert [UID:0001KI] to a non-emitting split/index parent only after replacement child pages validate.
3. Preserve [UID:0000OZ] as the parent source-file grouping owner and as the emitter route for eligible exact method/helper children.
4. Keep parent formal C++ blank with the exact no-code proof above.
5. Preserve existing checkbox exact children and support docs unless a direct contradiction appears during implementation.
6. Update support docs only where they are weaker than the report: class method inventories, source-file grouping, global naming notes, child split links, and stale alias cleanup inside editable by-* docs.
7. Do not edit generated/project-level/manual coverage/tool-state/IDA DB files.

## Recommended Target Doc Changes

Target path: `by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md`

Apply after child creation:

- Metadata:
  - `COMPLETION:90`
  - `CONFIDENCE:91`
  - `CANONICAL_OWNER:0000OZ`
  - `RECONSTRUCTABLE:FALSE`
  - `EMITTER_UIDS:` blank
- Keep formal `RECONSTRUCTION_CPP CODE` blank.
- Replace/update item summary with:
  - `MCP-reviewed social user-list split index over dialog/list/party-search method bodies, checkbox-control overlap, comparator/source-message helpers, switch tables, padding, no-route wrappers, globals, and compiler destructor/adjustor artifacts; exact child ranges and aggregate no-code proof documented.`
- Add a status/rebuild note that [UID:0001KI] is a non-emitting split/index parent after child pages exist.
- Preserve current behavior evidence, but replace old wording about missing precise method/range children with real child links after validator UIDs are assigned.
- Add explicit child/split table facts, parent no-code proof, current MCP session facts, and generated-state staleness note.
- Preserve negative evidence for no-route `0x0059dc20`, `0x0059e9b0`, and `0x0059e9d0`.
- Preserve `g_bShowHuntersListOnly`, `g_pUserListDialogPane`, `UserListRecord`, `CompareUserListRecordsByStatus`, `CompareUserListRecordsByName`, `AddUserListSourceMessage`, and `SyncUserListSourceTextIntoBucket` names.

If split creation is explicitly excluded by supervisor callback:

- Do not apply `RECONSTRUCTABLE:FALSE` or blank emitters.
- Keep current parent owner/emitter/reconstructable as a temporary coverage-preserving state.
- Add the no-code proof and split-required section, with score no higher than `90/91`.

## Recommended Support Doc Changes

All support edits are callback-safe: edit only if the current file is weaker than this report, inspect/leave unchanged if already same-or-greater detail, and leave untouched if unrelated. Do not edit project-level/generated/manual coverage files.

- `by-file/UserListDialogPane.md` [UID:0000OZ]: edit after child UIDs exist. Add/refresh the method/helper inventory for all child pages, document that [UID:0001KI] is a non-emitting split parent, preserve [UID:0000OZ] as source-file route, and record current MCP evidence for `g_bShowHuntersListOnly`, `g_pUserListDialogPane`, `UserListRecord`, `0x84`, and `0x85`.
- `by-class/UserListDialogPane.md` [UID:0000FN]: edit after child UIDs exist if weaker. Add/refresh links for constructor, sort, refresh, packet, key/control, cleanup/tail, switch-table, scalar deleting destructor, and adjustor artifacts. Keep source method bodies on exact children.
- `by-class/UserListPane.md` [UID:0000FO]: edit after child UIDs exist if weaker. Add/refresh links for constructor/destructor, draw, selection, direct-message opener, double-click source request, no-route sort wrappers, scalar deleting destructor, and adjustor artifacts.
- `by-class/PartySearchEditPane.md` [UID:0000A7]: edit after child UIDs exist if weaker. Add/refresh links for constructor, action handler, cleanup/no-op override, scalar deleting destructor, and adjustor artifacts. Preserve outbound `0x84` behavior.
- `by-global/g_bShowHuntersListOnly.md` [UID:0002ZX]: inspect; edit only if it lacks the current MCP evidence that `0x0069bed0` is toggled by control id `0x15` and filters rows whose `UserListRecord+0x20e` flag is zero. Do not reintroduce `g_bShowHiddenUsers`.
- `by-global/g_pUserListDialogPane.md` [UID:0003EI]: inspect; edit only if it lacks the constructor publish/destructor or clear-helper evidence from `0x0059efe0` and related xrefs.
- `by-global/g_useEpfAssets.md` [UID:0000SW]: inspect; edit only if it lacks the user-list evidence that `byte_66DA97` selects `STAR.EPF`/`ICON.EPF` versus `STAR.EPD`/`ICON.EPD` and the new versus legacy direct-message input pane constructor.
- `by-type/by-enum/MapServerPacketOpcode.md`: inspect only. It already has the server `0x36` user-list row; leave unchanged unless it is weaker or contradicts the current report. Do not add outgoing `0x84`/`0x85` as server opcodes unless a separate enum structure supports that.
- `by-class/CheckBoxTextControlPane.md` [UID:00007U], `by-file/SpecializedButtonPanes.md` [UID:0000L7], and existing checkbox exact child pages: inspect/leave unchanged unless a direct contradiction is found. Current evidence supports keeping checkbox ownership out of [UID:0001KI].
- `by-memory/0x0062e8fc-0x0062eccc.UserListReadOnlyData.md`, `by-memory/0x0062e8fc-0x0062e998.UserListDialogPaneVtableData.md`, `by-memory/0x0062eadc-0x0062eb9c.UserListPaneVtableData.md`, and `by-memory/0x0062eb9c-0x0062eccc.UserListResourceStrings.md`: inspect/leave unchanged unless weaker; they are data support docs, not executable child homes.

## Score And Metadata Recommendation

Current target score/metadata:

- `COMPLETION:87`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:0000OZ`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000OZ`
- C++ blank

Preferred parent score/metadata after split:

- `COMPLETION:90`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:0000OZ`
- `RECONSTRUCTABLE:FALSE`
- `EMITTER_UIDS:` blank
- C++ blank

Score rationale:

- Completion rises because current MCP confirms boundaries, function/non-function starts, raw helper status, comparator semantics, packet/opcode behavior, globals, strings, and exact split child ranges.
- Confidence rises because current MCP corroborates the target's B001-derived map and resolves stale generated/global naming contradictions.
- Completion/confidence do not go higher because the child pages are not yet created/validated and UIDs are unavailable during report-only work. Code-emitting children now have exact formal C++ insertion blocks; non-emitting source/artifact/no-route children have explicit no-code proofs.
- Parent reclassification is evidence-backed but must be sequenced after child creation to avoid dropping source-body coverage.

Score-limiting blockers researched:

- Exact child coverage gap: resolved with a complete split table and child metadata/disposition plan.
- Aggregate C++ risk: resolved with target-specific no-code proof.
- No-route helper/wrapper liveness: researched through bytes, disassembly, xrefs, code/data/immediate/pointer route checks, and MCP health after a broad-scan timeout; resolved as no-owner/non-emitting raw children with blank formal C++ and no public source route.
- Stale global alias: resolved in favor of `g_bShowHuntersListOnly`.
- Generated tracker/C++ staleness: identified as validator-owned generated state; not edited manually.
- Opcode/record-field names: researched through decompilation, xrefs, and int conversion; source-facing names recommended.

## Open Questions With Attempted Resolution

- Original exact method names: not symbol-proven. Current behavior-backed names are strong enough for docs and child filenames, but confidence remains below final-audit. This does not block parent split/no-code disposition.
- Exact formal C++ for method/helper children: resolved. Code-emitting children have exact formal insertion blocks in this report. Complex source-authored children that are not safe to emit in this callback have child-specific no-code proofs and blank `EMITTER_UIDS`; they are not below-gate owner/emitter placeholders.
- `0x0059dc20`, `0x0059e9b0`, and `0x0059e9d0` route: resolved for this report as no-owner/non-emitting raw children. Current `xrefs_to`, code-ref, data-ref, immediate, and pointer-byte searches are absent/negative; the broad operand scan timeout is documented with MCP health recovery. No public method/helper emission is recommended.
- Project-level stale aliases: identified but excluded by assignment. Editable by-* docs should use `g_bShowHuntersListOnly`; project-level/generated cleanup is supervisor/validator-owned.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

None. Do not edit `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, project-level generated reports, `by-memory/-coverage-report.md`, or any other `-coverage-report.md` file. The generated tracker/coverage rows should refresh through normal validator execution/report lifecycle after source by-* metadata changes.

## Validator Commands For Accepted Implementation

Run each command from `E:\NTK\GhidraBridge\source-3\project-documentation`.

For every new/changed `by-memory` child file, run:

> Executable block R001 was removed from this report and preserved verbatim in [0001KI-UserListDialogPaneAndUserListPane-source-quality-removed.md](0001KI-UserListDialogPaneAndUserListPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

At minimum, after accepted split implementation, validate:

> Executable block R002 was removed from this report and preserved verbatim in [0001KI-UserListDialogPaneAndUserListPane-source-quality-removed.md](0001KI-UserListDialogPaneAndUserListPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Also validate each support doc that is edited, for example:

> Executable block R003 was removed from this report and preserved verbatim in [0001KI-UserListDialogPaneAndUserListPane-source-quality-removed.md](0001KI-UserListDialogPaneAndUserListPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Follow-Up Actions

Supervisor actions:

- Validate whether this report's split-first recommendation is accepted.
- If accepted, issue an implementation callback that explicitly permits child-page creation/split execution and repeats the no-generated/no-project-level/no-manual-coverage/no-tool-state constraints.
- After B002 implementation and verification, execute the report with the validator lifecycle command.

B002 implementation actions after callback:

- Lease only the parent/support files being edited immediately.
- Create/validate child pages first so UIDs exist.
- Replace TMP references in parent/support docs with real UID links.
- Apply parent reclassification only after children validate.
- Update the report checklist with proof and scoped validator command results.

Child C++ / no-code disposition:

- Apply exact formal C++ blocks from this report to the code-emitting child pages.
- Keep formal C++ blank on non-emitting complex source children, artifact children, and no-route raw wrappers, preserving the child-specific no-code/no-improvement proofs.

## Confidence

Recommendation confidence: high.

Score confidence: high for `90/91` parent after split; medium-high if supervisor excludes split creation and leaves parent as a temporary emitter.

Remaining uncertainty:

- Validator-assigned child UIDs are not known during report-only work.
- Exact original method/field spellings are inferred.
- New child UIDs are unavailable until validator registration during implementation.
- Complex source-authored child pages with blank formal C++ have explicit no-code proofs and blank emitters; they are not intended as code-emitting pages in this callback.

## Validator Results

Commands run: implementation callback validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` with `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240`.

Results:

- All 33 new child pages validated with exit `0`, `ok:1`, generated refresh deferred; initial child command IDs ran from `000000003346` through `000000003421`.
- Ten child pages with reference-link cleanup were revalidated with exit `0`, `ok:1`, generated refresh deferred; command IDs `000000003439`, `000000003440`, `000000003441`, `000000003442`, `000000003443`, `000000003445`, `000000003447`, `000000003449`, `000000003451`, and `000000003453`.
- Parent/support validators were rerun after support registry refresh and all exited `0`, `ok:1`, generated refresh deferred: [UID:0001KI] command `000000003521`; [UID:0000OZ] command `000000003522`; [UID:0000FN] command `000000003523`; [UID:0000FO] command `000000003524`; [UID:0000A7] command `000000003525`; [UID:0002ZX] command `000000003526`; [UID:0003EI] command `000000003527`; [UID:0000SW] command `000000003528`.

Unresolved validator warnings/errors: no validator command failed. Residual missing-ref warnings are stale registry/generated coverage mappings and unchanged pre-existing support UID mappings, including old checkbox/read-only/global aliases; they are not missing accepted B002 child pages or skipped implementation details.

## Changed Files

Created:

- `by-memory/0x0059bc90-0x0059d198.UserListDialogPaneConstructor.md`
- `by-memory/0x0059d198-0x0059d1e0.UserListDialogPaneConstructorCleanupTail.md`
- `by-memory/0x0059d1e0-0x0059d1e3.UserListDialogPaneNullsub61.md`
- `by-memory/0x0059d1f0-0x0059d24f.UserListDialogPaneSortListsByStatus.md`
- `by-memory/0x0059d250-0x0059d2af.UserListDialogPaneSortListsByName.md`
- `by-memory/0x0059d2b0-0x0059d5fe.UserListDialogPaneRefreshCategoryView.md`
- `by-memory/0x0059d5fe-0x0059d620.UserListDialogPaneRefreshCategorySwitchTable.md`
- `by-memory/0x0059d620-0x0059d8f5.UserListDialogPaneHandleUserListPacket.md`
- `by-memory/0x0059d900-0x0059da82.UserListDialogPaneOnKeyEvent.md`
- `by-memory/0x0059da90-0x0059dbe3.UserListDialogPaneOnControlCommand.md`
- `by-memory/0x0059dbe3-0x0059dc20.UserListDialogPaneOnControlCommandSwitchTable.md`
- `by-memory/0x0059dc20-0x0059de4a.UserListDialogPaneLocalSourceUpdateSendHelperRaw.md`
- `by-memory/0x0059de60-0x0059decf.AddUserListSourceMessage.md`
- `by-memory/0x0059e0d0-0x0059e393.PartySearchEditPaneConstructor.md`
- `by-memory/0x0059e3a0-0x0059e3bf.PartySearchEditPaneCleanupHelper.md`
- `by-memory/0x0059e3c0-0x0059e3c1.PartySearchEditPaneOnDestroyChildControlsNoop.md`
- `by-memory/0x0059e3d0-0x0059e707.PartySearchEditPaneOnAction.md`
- `by-memory/0x0059e710-0x0059e899.UserListPaneConstructor.md`
- `by-memory/0x0059e8a0-0x0059e943.UserListPaneDestructor.md`
- `by-memory/0x0059e950-0x0059e983.CompareUserListRecordsByStatus.md`
- `by-memory/0x0059e990-0x0059e9a6.CompareUserListRecordsByName.md`
- `by-memory/0x0059e9b0-0x0059e9cf.UserListPaneSortByStatusNoRouteWrapper.md`
- `by-memory/0x0059e9d0-0x0059e9ef.UserListPaneSortByNameNoRouteWrapper.md`
- `by-memory/0x0059e9f0-0x0059ea8f.SyncUserListSourceTextIntoBucket.md`
- `by-memory/0x0059ea90-0x0059ed18.UserListPaneDrawUserEntry.md`
- `by-memory/0x0059ed20-0x0059ed5e.UserListPaneOnItemSelected.md`
- `by-memory/0x0059ed60-0x0059ee0c.UserListPaneOpenSayToUserMessageInputPane.md`
- `by-memory/0x0059ee10-0x0059efd0.UserListPaneOnDoubleClick.md`
- `by-memory/0x0059efe0-0x0059efeb.ClearUserListDialogPaneSingleton.md`
- `by-memory/0x0059efeb-0x0059f043.UserListFeatureAdjustorThunks.md`
- `by-memory/0x0059f0b0-0x0059f105.PartySearchEditPaneScalarDeletingDestructor.md`
- `by-memory/0x0059f110-0x0059f181.UserListDialogPaneScalarDeletingDestructor.md`
- `by-memory/0x0059f190-0x0059f25b.UserListPaneScalarDeletingDestructor.md`

Modified:

- `tools/leaser/Agents/Agent-B002/research/0001KI-UserListDialogPaneAndUserListPane-source-quality.md`
- `by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md`
- `by-file/UserListDialogPane.md`
- `by-class/UserListDialogPane.md`
- `by-class/UserListPane.md`
- `by-class/PartySearchEditPane.md`
- `by-global/g_bShowHuntersListOnly.md`
- `by-global/g_pUserListDialogPane.md`
- `by-global/g_useEpfAssets.md`

Renamed:

- None.

Report execution: leave blank during the B-agent pass. The supervisor runs `tools/validator.py execute_report ... --apply` after verification.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation.
- [x] Target/support docs to update listed with edit vs inspect/leave-unchanged dispositions.
- [x] Current target state and live metadata recorded.
- [x] Actual MCP evidence checked and recorded, including session/status, function starts, bytes, xrefs, callees, decompilation, strings, globals, and negative checks.
- [x] Metadata/score recommendation recorded for preferred split-complete state: parent `90/91`, owner [UID:0000OZ], `RECONSTRUCTABLE:FALSE`, blank emitters, blank C++.
- [x] Guard condition recorded: do not apply parent false/blank-emitter state until replacement child pages exist and validate.
- [x] Score-limiting blockers researched to resolution or implementation-ready repair: exact child coverage gap, aggregate C++ risk, raw/no-route helpers, stale global alias, generated tracker staleness, packet/record/helper names.
- [x] Owner/emitter/reconstructable changes to apply recorded.
- [x] Split/new-child changes to apply recorded with exact ranges, proposed paths, owner/emitter disposition, reconstructable state, scores, and no-code disposition.
- [x] Source-placement and range/split/padding/reclassification analysis recorded.
- [x] IDA rename/type/comment recommendations recorded as source-facing doc recommendations only; no IDA DB edits requested.
- [x] First-draft C++ decision recorded: parent not eligible, exact parent no-code proof supplied, exact formal child C++ blocks supplied for code-emitting children, and child-specific no-code/no-improvement proofs supplied for non-emitting children.
- [x] Exact target/support doc facts to incorporate at report-level detail recorded.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Validator commands listed using `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240`.
- [x] Generated/project-level/manual coverage/tool-state/IDA DB files explicitly excluded from edits.

Implementation callback checklist:

- [x] Lease discipline followed for implementation edits. Proof: no active conflicts were present in `tools/leaser/Agents/current_leases.md`; B002 leased the target/support files immediately before edit/validator batches, released the child reference-fix leases successfully, released the parent/support leases successfully, and final lease status was rechecked after validation.
- [x] Split-first plan applied before parent conversion. Proof: all child pages below were created first, validator-assigned UIDs were obtained, and [UID:0001KI] was converted only after child validators exited `0`.

| UID | Child path | Applied disposition and validator proof |
| --- | --- | --- |
| `000470` | `by-memory/0x0059bc90-0x0059d198.UserListDialogPaneConstructor.md` | `86/90`, owner `0000FN`, blank emitter/C++; initial validator `000000003346` at `2026-06-26T20:38:49-04:00`, exit `0`, `ok:1`, generated refresh deferred. |
| `000471` | `by-memory/0x0059d198-0x0059d1e0.UserListDialogPaneConstructorCleanupTail.md` | `86/90`, `RECONSTRUCTABLE:FALSE`, blank emitter/C++; initial validator `000000003349` at `20:38:52`, exit `0`, `ok:1`; reference-link revalidation `000000003439` at `20:44:17`, exit `0`, `ok:1`; generated refresh deferred. |
| `000472` | `by-memory/0x0059d1e0-0x0059d1e3.UserListDialogPaneNullsub61.md` | `88/91`, `RECONSTRUCTABLE:FALSE`, blank emitter/C++; validator `000000003352` at `20:38:55`, exit `0`, `ok:1`, generated refresh deferred. |
| `000473` | `by-memory/0x0059d1f0-0x0059d24f.UserListDialogPaneSortListsByStatus.md` | `88/90`, owner `0000FN`, emitter `0000OZ`, exact formal C++; validator `000000003355` at `20:38:57`, exit `0`, `ok:1`, generated refresh deferred. |
| `000474` | `by-memory/0x0059d250-0x0059d2af.UserListDialogPaneSortListsByName.md` | `88/90`, owner `0000FN`, emitter `0000OZ`, exact formal C++; validator `000000003357` at `20:39:00`, exit `0`, `ok:1`, generated refresh deferred. |
| `000475` | `by-memory/0x0059d2b0-0x0059d5fe.UserListDialogPaneRefreshCategoryView.md` | `86/90`, owner `0000FN`, blank emitter/C++; initial validator `000000003359` at `20:39:02`; reference-link revalidation `000000003440` at `20:44:30`; both exit `0`, `ok:1`, generated refresh deferred. |
| `000476` | `by-memory/0x0059d5fe-0x0059d620.UserListDialogPaneRefreshCategorySwitchTable.md` | `87/91`, `RECONSTRUCTABLE:FALSE`, blank emitter/C++; validator `000000003361` at `20:39:04`, exit `0`, `ok:1`, generated refresh deferred. |
| `000477` | `by-memory/0x0059d620-0x0059d8f5.UserListDialogPaneHandleUserListPacket.md` | `86/90`, owner `0000FN`, blank emitter/C++; initial validator `000000003363` at `20:39:06`; reference-link revalidation `000000003441` at `20:44:41`; both exit `0`, `ok:1`, generated refresh deferred. |
| `000478` | `by-memory/0x0059d900-0x0059da82.UserListDialogPaneOnKeyEvent.md` | `86/90`, owner `0000FN`, blank emitter/C++; validator `000000003365` at `20:39:08`, exit `0`, `ok:1`, generated refresh deferred. |
| `000479` | `by-memory/0x0059da90-0x0059dbe3.UserListDialogPaneOnControlCommand.md` | `87/90`, owner `0000FN`, emitter `0000OZ`, exact formal C++; initial validator `000000003367` at `20:39:10`; reference-link revalidation `000000003442` at `20:44:53`; both exit `0`, `ok:1`, generated refresh deferred. |
| `00047A` | `by-memory/0x0059dbe3-0x0059dc20.UserListDialogPaneOnControlCommandSwitchTable.md` | `87/91`, `RECONSTRUCTABLE:FALSE`, blank emitter/C++; validator `000000003369` at `20:39:12`, exit `0`, `ok:1`, generated refresh deferred. |
| `00047B` | `by-memory/0x0059dc20-0x0059de4a.UserListDialogPaneLocalSourceUpdateSendHelperRaw.md` | `84/90`, `CANONICAL_OWNER:NONE`, blank emitter/C++, no-route proof preserved; initial validator `000000003371` at `20:39:14`; reference-link revalidation `000000003443` at `20:45:04`; both exit `0`, `ok:1`, generated refresh deferred. |
| `00047C` | `by-memory/0x0059de60-0x0059decf.AddUserListSourceMessage.md` | `88/91`, owner/emitter `0000OZ`, exact formal C++; validator `000000003373` at `20:39:16`, exit `0`, `ok:1`, generated refresh deferred. |
| `00047D` | `by-memory/0x0059e0d0-0x0059e393.PartySearchEditPaneConstructor.md` | `86/90`, owner `0000A7`, blank emitter/C++; initial validator `000000003375` at `20:39:18`; checkbox UID correction revalidation `000000003445` at `20:45:17`; both exit `0`, `ok:1`, generated refresh deferred. |
| `00047E` | `by-memory/0x0059e3a0-0x0059e3bf.PartySearchEditPaneCleanupHelper.md` | `86/90`, `RECONSTRUCTABLE:FALSE`, blank emitter/C++; validator `000000003377` at `20:39:20`, exit `0`, `ok:1`, generated refresh deferred. |
| `00047F` | `by-memory/0x0059e3c0-0x0059e3c1.PartySearchEditPaneOnDestroyChildControlsNoop.md` | `88/91`, `RECONSTRUCTABLE:FALSE`, blank emitter/C++; validator `000000003379` at `20:39:22`, exit `0`, `ok:1`, generated refresh deferred. |
| `00047G` | `by-memory/0x0059e3d0-0x0059e707.PartySearchEditPaneOnAction.md` | `86/90`, owner `0000A7`, blank emitter/C++; initial validator `000000003381` at `20:39:24`; reference-link revalidation `000000003447` at `20:45:29`; both exit `0`, `ok:1`, generated refresh deferred. |
| `00047H` | `by-memory/0x0059e710-0x0059e899.UserListPaneConstructor.md` | `86/90`, owner `0000FO`, blank emitter/C++; validator `000000003383` at `20:39:26`, exit `0`, `ok:1`, generated refresh deferred. |
| `00047I` | `by-memory/0x0059e8a0-0x0059e943.UserListPaneDestructor.md` | `86/90`, owner `0000FO`, blank emitter/C++; validator `000000003385` at `20:39:28`, exit `0`, `ok:1`, generated refresh deferred. |
| `00047J` | `by-memory/0x0059e950-0x0059e983.CompareUserListRecordsByStatus.md` | `90/92`, owner/emitter `0000OZ`, exact formal C++; validator `000000003387` at `20:39:31`, exit `0`, `ok:1`, generated refresh deferred. |
| `00047K` | `by-memory/0x0059e990-0x0059e9a6.CompareUserListRecordsByName.md` | `90/92`, owner/emitter `0000OZ`, exact formal C++; validator `000000003389` at `20:39:33`, exit `0`, `ok:1`, generated refresh deferred. |
| `00047L` | `by-memory/0x0059e9b0-0x0059e9cf.UserListPaneSortByStatusNoRouteWrapper.md` | `84/90`, `CANONICAL_OWNER:NONE`, blank emitter/C++, no-route proof preserved; validator `000000003391` at `20:39:36`, exit `0`, `ok:1`, generated refresh deferred. |
| `00047M` | `by-memory/0x0059e9d0-0x0059e9ef.UserListPaneSortByNameNoRouteWrapper.md` | `84/90`, `CANONICAL_OWNER:NONE`, blank emitter/C++, no-route proof preserved; validator `000000003394` at `20:39:38`, exit `0`, `ok:1`, generated refresh deferred. |
| `00047N` | `by-memory/0x0059e9f0-0x0059ea8f.SyncUserListSourceTextIntoBucket.md` | `88/91`, owner/emitter `0000OZ`, exact formal C++; validator `000000003397` at `20:39:42`, exit `0`, `ok:1`, generated refresh deferred. |
| `00047O` | `by-memory/0x0059ea90-0x0059ed18.UserListPaneDrawUserEntry.md` | `86/90`, owner `0000FO`, blank emitter/C++; validator `000000003400` at `20:39:45`, exit `0`, `ok:1`, generated refresh deferred. |
| `00047P` | `by-memory/0x0059ed20-0x0059ed5e.UserListPaneOnItemSelected.md` | `87/90`, owner `0000FO`, emitter `0000OZ`, exact formal C++; validator `000000003403` at `20:39:47`, exit `0`, `ok:1`, generated refresh deferred. |
| `00047Q` | `by-memory/0x0059ed60-0x0059ee0c.UserListPaneOpenSayToUserMessageInputPane.md` | `87/90`, owner `0000FO`, emitter `0000OZ`, exact formal C++; initial validator `000000003406` at `20:39:51`; reference-link revalidation `000000003449` at `20:45:32`; both exit `0`, `ok:1`, generated refresh deferred. |
| `00047R` | `by-memory/0x0059ee10-0x0059efd0.UserListPaneOnDoubleClick.md` | `87/90`, owner `0000FO`, emitter `0000OZ`, exact formal C++; validator `000000003409` at `20:39:54`, exit `0`, `ok:1`, generated refresh deferred. |
| `00047S` | `by-memory/0x0059efe0-0x0059efeb.ClearUserListDialogPaneSingleton.md` | `90/92`, owner/emitter `0000OZ`, exact formal C++; initial validator `000000003412` at `20:39:59`; reference-link revalidation `000000003451` at `20:45:34`; both exit `0`, `ok:1`, generated refresh deferred. |
| `00047T` | `by-memory/0x0059efeb-0x0059f043.UserListFeatureAdjustorThunks.md` | `87/91`, `RECONSTRUCTABLE:FALSE`, blank emitter/C++; validator `000000003415` at `20:40:01`, exit `0`, `ok:1`, generated refresh deferred. |
| `00047U` | `by-memory/0x0059f0b0-0x0059f105.PartySearchEditPaneScalarDeletingDestructor.md` | `87/91`, `RECONSTRUCTABLE:FALSE`, blank emitter/C++; validator `000000003417` at `20:40:05`, exit `0`, `ok:1`, generated refresh deferred. |
| `00047V` | `by-memory/0x0059f110-0x0059f181.UserListDialogPaneScalarDeletingDestructor.md` | `87/91`, `RECONSTRUCTABLE:FALSE`, blank emitter/C++; initial validator `000000003419` at `20:40:07`; reference-link revalidation `000000003453` at `20:45:36`; both exit `0`, `ok:1`, generated refresh deferred. |
| `00047W` | `by-memory/0x0059f190-0x0059f25b.UserListPaneScalarDeletingDestructor.md` | `87/91`, `RECONSTRUCTABLE:FALSE`, blank emitter/C++; validator `000000003421` at `20:40:10`, exit `0`, `ok:1`, generated refresh deferred. |

- [x] Parent [UID:0001KI] updated to `90/91`, owner `0000OZ`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++, exact item summary, revised split child table with real UIDs, parent no-code proof, no-route negative evidence, and generated-state staleness note. Proof: validator `000000003521` at `2026-06-26T20:58:45-04:00`, exit `0`, `ok:1`, generated refresh deferred. Residual missing-ref warnings are stale registry mappings for older unchanged checkbox/read-only/global UIDs and generated coverage references, not missing accepted B002 child links.
- [x] [UID:0000OZ] `by-file/UserListDialogPane.md` edited with real child UID inventory, source-file route, no-route raw children, parent split/index status, user-list globals/record/opcode context preserved. Proof: validator `000000003522` at `20:58:57`, exit `0`, `ok:1`, generated refresh deferred.
- [x] [UID:0000FN] `by-class/UserListDialogPane.md` edited with constructor/sort/refresh/packet/key/control/artifact child links and class-level declaration-only placement. Proof: validator `000000003523` at `20:58:59`, exit `0`, `ok:1`, generated refresh deferred.
- [x] [UID:0000FO] `by-class/UserListPane.md` edited with constructor/destructor/draw/selection/direct-message/double-click/no-route wrapper/scalar deleting destructor child links. Proof: validator `000000003524` at `20:59:10`, exit `0`, `ok:1`, generated refresh deferred.
- [x] [UID:0000A7] `by-class/PartySearchEditPane.md` edited with constructor/action/cleanup/no-op/adjustor/scalar deleting destructor child links and outbound `0x84` behavior preserved. Proof: validator `000000003525` at `20:59:22`, exit `0`, `ok:1`, generated refresh deferred.
- [x] [UID:0002ZX] `by-global/g_bShowHuntersListOnly.md` inspected and edited because it lacked the explicit `OnControlCommand` control id `0x15` child link. Proof: validator `000000003526` at `20:59:33`, exit `0`, `ok:1`, generated refresh deferred.
- [x] [UID:0003EI] `by-global/g_pUserListDialogPane.md` inspected and edited because it lacked the exact [UID:00047S] clear-helper child link. Proof: validator `000000003527` at `20:59:35`, exit `0`, `ok:1`, generated refresh deferred.
- [x] [UID:0000SW] `by-global/g_useEpfAssets.md` inspected and edited because it lacked the user-list EPF/EPD resource branch and direct-message input-pane branch evidence. Proof: validator `000000003528` at `20:59:47`, exit `0`, `ok:1`, generated refresh deferred.
- [x] `by-type/by-enum/MapServerPacketOpcode.md` inspected and left unchanged: it already documents server opcode `0x36` as user-list dialog routing and excludes outbound packet builders/feature-private response opcodes from the inbound enum.
- [x] Checkbox support docs inspected and left unchanged. Current UID for the class is [UID:000022] `by-class/CheckBoxTextControlPane.md` rather than the stale report-side [UID:00007U]; `by-file/SpecializedButtonPanes.md` and exact checkbox children [UID:0003FE]-[UID:0003FJ] already preserve reusable-control ownership, setter/getter/paint/destructor evidence, and no contradiction was found.
- [x] User-list read-only/vtable/resource support docs inspected and left unchanged: [UID:00026U], [UID:0003E6], [UID:0003E8], and [UID:0003E9] already document exact mixed `.rdata` ownership, vtable/resource boundaries, checkbox separation, and user-list source-file/class routing at same-or-greater detail. The report's old [UID:0001BD]/[UID:0001BE]/[UID:0001BG]/[UID:0001BH] labels are stale relative to current validator-assigned UIDs.
- [x] No generated/project-level/manual coverage/tool-state/IDA DB files were manually edited. Scoped validators were run only as required by the callback; generated refresh state reported `deferred`.
- [x] Report checklist updated with applied, already-present, and intentionally unchanged items plus concrete validator/lease proof.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0001KI-UserListDialogPaneAndUserListPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0001KI-UserListDialogPaneAndUserListPane-source-quality.md","timestamp":"2026-06-26T22:10:31","uid":"0001KI"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001KI-UserListDialogPaneAndUserListPane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0001KI-UserListDialogPaneAndUserListPane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001KI"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
