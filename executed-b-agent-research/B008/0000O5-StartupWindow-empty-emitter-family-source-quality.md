** TARGET-REPORT-UID:0000O5 **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0000O5 StartupWindow Empty-Emitter Family Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0000O5] `by-file/StartupWindow.md` as the `NexusTK/app/StartupWindow.cpp` source-file route, preserve current metadata `89/88`, and resolve the current twelve empty emitters with file-specific formal output rather than broad duplicate bodies.
- Final disposition: the first implementation callback must include the split/child repair for [UID:0001IO] and [UID:0000VI], not only marker cleanup. Create exact child `by-memory` pages for every source-bearing body currently covered by `0x005807d0-0x0058206e`, validate those new pages so the validator assigns real UIDs, then reclassify [UID:0001IO] as a non-emitting split index and [UID:0000VI] as a non-emitting tracker. Use `[TMP:"..."]` links in edited parent/support docs until validation replaces them with real UIDs; do not guess UIDs.
- Required action: do not create broad method bodies on [UID:0000DZ], [UID:0000VI], or [UID:0001IO]. Preserve source-owned bodies by creating exact child pages with address ranges, owner/emitter metadata, and formal first-draft C++ for every source-bearing child that clears the emitter gate. Existing [UID:0001IP] already emits the curl callback. Only padding, broad containers, storage-only pages, `.rdata` support, and the compiler scalar-deleting destructor wrapper remain no-code/no-emitter.
- Confidence: high for the source-file route, global declarations, pointer-data declaration, no-code dispositions, generated baseline, and raw-helper split boundaries. Confidence is medium-high for final original spelling of `g_pStartupWindow`, `g_startupWindowClassAtom`, `g_useEpfAssets`, `g_szBaramNoticeWndClass`, and `g_szNoticeTitle`; the chosen names are best current source-facing documentation names and are already used in current docs.

## Target

- Target UID: `0000O5`
- Target path: `by-file/StartupWindow.md`
- Generated output: `auto-generated/NexusTK/app/StartupWindow.cpp`
- Queue row: `auto-generated/-ag-research-tracker.md` -> `Files With Empty Emitters`
- Current tracker state from `goal.md`: `14` total emitters, `2` filled, `12` empty, `14.3%` filled, no exact executed by-file family report found by supervisor duplicate check.
- Current by-file metadata: `COMPLETION:89`, `CONFIDENCE:88`, `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/app/"`.

## Current Target State

Generated `StartupWindow.cpp` header at research time:

- `validator-command-id: 000000003503`
- `validator-refreshed-at: 2026-07-01T06:05:24-04:00`
- source by-file UID `0000O5`

Current filled emitters:

- [UID:0001IP] `by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md` emits `static size_t CurlWriteCallback(...)`.
- [UID:000484] `by-memory/0x00612980-0x00612b24.ApplicationRegistryDisplayStringData.md` emits a shared registry/display string no-standalone marker.

Current empty markers in `auto-generated/NexusTK/app/StartupWindow.cpp`:

| UID | Path | Current metadata | Current disposition issue |
| --- | --- | --- | --- |
| `0000DZ` | `by-class/StartupWindow.md` | `88/89`, owner/emitter `0000O5` | Broad class route, not a method body. |
| `0002ZS` | `by-global/g_pStartupWindow.md` | `86/88`, owner/emitter `0000O5` | Exact source-level singleton pointer declaration is ready. |
| `0002ZT` | `by-memory/0x0069bac8-0x0069bacc.g_pStartupWindow.md` | `86/88`, owner/emitter `0002ZS` | Exact storage child should not duplicate the global declaration. |
| `0002ZQ` | `by-global/g_startupWindowClassAtom.md` | `87/90`, owner/emitter `0000O5` | Exact source-level atom declaration is ready. |
| `0002ZR` | `by-memory/0x0069bac4-0x0069bac6.g_startupWindowClassAtom.md` | `87/90`, owner/emitter `0002ZQ` | Exact storage child should not duplicate the global declaration. |
| `0000SW` | `by-global/g_useEpfAssets.md` | `88/90`, owner/emitter `0000O5` | Exact source-level process-wide mode byte declaration is ready. |
| `0001OH` | `by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md` | `88/90`, owner/emitter `0000SW` | Exact storage child should not duplicate the global declaration; item summary has stale "autogen-unassigned" wording. |
| `0000VI` | `by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md` | `87/90`, owner/emitter `0000O5` | Boundary-debt tracker, not a standalone source body. |
| `0001IO` | `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md` | `86/88`, owner/emitter `0000O5` | Broad executable aggregate/split index, not one function body. |
| `00026K` | `by-memory/0x0062d418-0x0062d5a8.StartupWindowReadOnlyData.md` | `88/92`, owner/emitter `0000O5` | Mixed `.rdata` vtable/string/source-literal island, not a hand-authored data table. |
| `000288` | `by-memory/0x00670260-0x00670268.StartupWindowNoticePointerData.md` | `86/90`, owner/emitter `0000O5` | Exact source-level initialized pointer-slot declarations are ready. |
| `0002AM` | `by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md` | `87/89`, owner/emitter `0000O5` | Aggregate for atom/reserved/singleton cluster, not a duplicate source body. |

## Evidence Checked

Direct current IDA MCP evidence:

- MCP endpoint `http://127.0.0.1:13337/mcp`.
- `initialize` returned server `ida-pro-mcp`, protocol `2025-06-18`.
- `idb_list`: active session `supervisor_resume_20260629`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input `NexusTK.exe.i64`, `is_analyzing:false`, active worker PID `14860`.
- `server_health`: `status:ok`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
- 2026-07-01 revision recheck: `initialize` and `server_health` succeeded again for database `supervisor_resume_20260629`; MCP remained live with `status:ok`, `auto_analysis_ready:true`, and `hexrays_ready:true`.
- `lookup_funcs`: constructor `0x005807d0` size `0x3c`; `0x00580810` not a function; `RunUpdateCheck` `0x00580870` size `0x88d`; WndProc `0x00581100` size `0x4aa`; raw starts `0x005815b0`, `0x005817e0`, `0x00581860`, `0x005818d0`, `0x005819d0` not functions; modeled helpers `0x00581660`, `0x00581670`, `0x00581730`, `0x005817a0`; callback `0x00581b80` size `0x166`; successor helpers `0x00581cf0`, `0x00581d30`, `0x00581dc0`, `0x00581e40`, `0x00581f50`; successor function `0x00582070`.
- `decompile 0x005807d0`: constructor writes `unk_69BAC8 = this`, installs `StartupWindow::vftable`, writes `byte_66DA97 = 1`, stores `HINSTANCE` at `this[2]`, clears bytes at `this+4` and `this+0x54`.
- `decompile 0x00580870`: `RunUpdateCheck` uses `lpClassName`, `lpWindowName`, `sub_581100` WndProc, `unk_69BAC4` RegisterClassExA cache, creates a 500x430 notice window, embeds `http://www.nexustk.com/news/news.asp`, reads `HKCU\Software\KRU\NexusTK` value `L"updvr"`, fetches update URL, passes `sub_581B80` as curl write callback twice, parses `version` and `minimap`, fetches minimap `HashList.txt`, updates minimap manager, runs the notice message loop, then destroys the notice window.
- `decompile 0x00581100`: WndProc reads `unk_69BAC8`, handles key/mouse/paint/link paths, loads `brm_main.pcx`, `brm_st_a/b/c.pcx`, `brm_ex_a/b.pcx`, calls button helpers `0x00581670`, `0x00581730`, `0x005817a0`, calls draw helper `0x00581dc0`, and opens `http://www.nexustk.com`.
- `xrefs_to`: `0x0069bac4` has four refs (`0x00580a57`, `0x00580a6e`, raw `0x00581af4`, raw `0x00581b08`); `0x0069bac6` has zero refs; `0x0069bac8` has four refs (`0x005807e5`, raw `0x00580864`, `0x00581114`, `0x00581d94`); `0x00670260` has two refs (`0x005808ac`, raw `0x005819e1`); `0x00670264` has two refs (`0x00580ab1`, raw `0x00581b47`); `0x0062d470` has three refs (`0x005807ed`, raw `0x00580817`, `0x00581d3a`).
- `xref_query 0x0066da97`: current total `366` data refs; constructor decompile confirms the write at `0x005807f3`, and B001's executed report remains the accepted read/write classification proof for `365` reads and `1` write.
- `get_bytes`: `0x0069bac4-0x0069bacc` all zero; `0x0066da97` byte `0x1`; `0x00670260-0x00670268` dwords `0x0062d418` and `0x0062d430`; `0x0062d46c-0x0062d474` dwords `0x00650938` and `0x00581d30`; `0x0058080c-0x00580810` four `0xcc`; `0x005815aa-0x005815b0` six `0xcc`; `0x00581b75-0x00581b80` eleven `0xcc`; `0x0058206e-0x00582070` two `0xcc`.
- `get_string`: StartupWindow literals include `"BaramNoticeWnd_Class"`, `"Notice"`, `"http://www.nexustk.com/news/news.asp"`, `updvr`, update URL, `"minimap"`, minimap `HashList.txt` URL, six `brm_*.pcx` names, and `"http://www.nexustk.com"`.
- `insn_query`: raw helper ranges `0x00580810-0x00580870`, `0x005815b0-0x0058165a`, `0x005817e0-0x00581854`, `0x00581860-0x005818c3`, `0x005818d0-0x005819cc`, and `0x005819d0-0x00581b75` disassemble as source-shaped bodies ending in `ret`/`ret 4`; `0x005819d0` builds a `WNDCLASSEXA`, uses WndProc `0x00581100`, checks/stores `g_startupWindowClassAtom`, creates a centered notice window, and stores the HWND at `this+0x0c`.
- `find code_ref`, `find data_ref`, and `find immediate` for raw starts `0x00580810`, `0x005815b0`, `0x005817e0`, `0x00581860`, `0x005818d0`, and `0x005819d0`: zero matches for all queried starts.

Current docs checked:

- `by-file/StartupWindow.md`
- `by-class/StartupWindow.md`
- `by-global/g_pStartupWindow.md`
- `by-memory/0x0069bac8-0x0069bacc.g_pStartupWindow.md`
- `by-global/g_startupWindowClassAtom.md`
- `by-memory/0x0069bac4-0x0069bac6.g_startupWindowClassAtom.md`
- `by-global/g_useEpfAssets.md`
- `by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md`
- `by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md`
- `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`
- `by-memory/0x0062d418-0x0062d5a8.StartupWindowReadOnlyData.md`
- `by-memory/0x00670260-0x00670268.StartupWindowNoticePointerData.md`
- `by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md`
- `auto-generated/NexusTK/app/StartupWindow.cpp`

Executed reports opened:

- `executed-b-agent-research/B010/0001IO-StartupWindowUpdateCheck-source-quality.md`
- `executed-b-agent-research/B001/00026K-startupwindow-rdata-source-quality.md`
- `executed-b-agent-research/B001/0000SW-g_useEpfAssets.md`
- `executed-b-agent-research/B003/0001IP-CurlWriteCallback-source-quality.md`

Search terms used:

- `TARGET-REPORT-UID:0000O5`, `StartupWindow`, `0000O5`, `0001IO`, `0000VI`, `00026K`, `000288`, `0002AM`, `g_pStartupWindow`, `g_startupWindowClassAtom`, `g_useEpfAssets`, `0x005807d0`, `0x005815b0`, `0x0069bac4`, `0x0066da97`.

No validators were run because this is report-only research and no by-* docs were edited.

## Heuristic / Inference Reanalysis And Validation

The current generated source is not missing one large `StartupWindow.cpp` body. It is polluted by broad pages that are eligible emitters but are not eligible source-body homes. The high-confidence repair is to distinguish exact source declarations from aggregate/support pages:

- Direct source declarations ready now:
  - `g_pStartupWindow` as file-local StartupWindow singleton pointer.
  - `g_startupWindowClassAtom` as file-local Win32 `ATOM` registration cache.
  - `g_useEpfAssets` as process-wide current EPF/layout selector defined with initial value `true`.
  - `g_szBaramNoticeWndClass` and `g_szNoticeTitle` as StartupWindow notice class/title pointer slots.
- No-standalone pages ready now:
  - `StartupWindow` broad class page, exact memory storage children, raw-helper tracker, executable aggregate, read-only data island, and update-state cluster.
- Split repair ready for implementation now:
  - B010's exact range map is validated by current MCP and is sufficient for child-page creation. The broad [UID:0001IO] executable aggregate should become a non-emitting split index only in the same callback that creates the exact child pages below. [UID:0000VI] should become a non-emitting tracker only after its five raw-helper bodies are represented by exact child pages. This avoids both broad duplicate C++ and loss of the source-owned bodies inside the aggregate/tracker ranges.

Rejected alternatives:

- Reject emitting all of [UID:0001IO] as one C++ block. The range mixes constructor, destructor-like body, `RunUpdateCheck`, WndProc, raw helper starts, padding, existing exact callback child, string helpers, draw helper, scalar deleting wrapper, and successor boundary.
- Reject adding method bodies to [UID:0000DZ] `StartupWindow`. The class page is a route/inventory page; exact by-memory children should own constructor/destructor/method/helper bodies.
- Reject duplicating global declarations from both by-global and by-memory storage pages. The by-global pages should emit the C++ declaration; the exact storage children should emit marker comments only.
- Reject hand-authoring the StartupWindow vtable, complete-object locator, raw `.rdata` table, or pooled string table from [UID:00026K]. Compiler output and source literals should fall out of class declarations, exact method bodies, and exact globals/pointer data.
- Reject treating the five raw notice helper starts as padding or false positives. Current MCP disassembly proves source-shaped helper bodies; negative start refs prove only that the route remains unresolved.
- Reject moving Browser, PCX decoding, libcurl implementation, MD5, or minimap persistence into StartupWindow. StartupWindow orchestrates those dependencies but does not own their implementations.
- Reject `Application`, `Config`, `MainUiGraph`, pane/render consumers, or a new display-mode globals file as stronger owners for `g_useEpfAssets` under current evidence. Current and executed B001 evidence still makes StartupWindow the best existing source-file owner for the one-byte declaration.

## Positive Evidence Summary

- Source route: `by-file/StartupWindow.md` already owns `NexusTK/app/StartupWindow.cpp`, and current MCP ties all twelve empty emitters to StartupWindow's update notice source route or exact storage/data support for that route.
- Global declarations: constructor/current xrefs prove `g_pStartupWindow`, `g_startupWindowClassAtom`, and `g_useEpfAssets` are concrete source-level declarations with known storage and uses.
- Pointer declarations: `0x00670260` and `0x00670264` hold pointers to the class/title strings, and current xrefs show they are consumed by `RunUpdateCheck` and the raw alternate setup helper.
- No-code broad pages: current MCP and executed B010/B001 reports prove [UID:0000VI], [UID:0001IO], [UID:00026K], and [UID:0002AM] are aggregate/support pages rather than standalone bodies. For [UID:0001IO] and [UID:0000VI], the no-code disposition is only valid when paired with exact child pages for their source-bearing bodies.
- Generated baseline: current generated file is fresh at command `000000003503`, still has exactly the twelve empty markers listed in `goal.md`, and already emits the exact [UID:0001IP] callback body.

## Negative Evidence Summary

- No code/data/immediate refs to raw helper starts `0x00580810`, `0x005815b0`, `0x005817e0`, `0x00581860`, `0x005818d0`, or `0x005819d0` were found by current MCP `find`.
- `lookup_funcs` still reports no IDA function objects for the raw starts, so source C++ should not pretend these are clean public APIs.
- `0x0069bac6` has zero xrefs and remains reserved/filler between the atom and pointer children; it should not be emitted as a named source global.
- `g_useEpfAssets` has broad read traffic across UI/render/dialog/map systems; those consumers do not own the declaration.
- [UID:00026K] includes runtime/STL parse exception literals and compiler-emitted vtable/COL data, so a hand-authored constants table would be partial and misleading.

## Ranked Ownership Analysis

### 1. [UID:0000O5] `by-file/StartupWindow.md`

- Evidence for: source route already valid; current MCP constructor, `RunUpdateCheck`, WndProc, raw helper, class/title pointer, update-state globals, and read-only strings all lead to StartupWindow update notice behavior.
- Evidence against: exact method/helper bodies are currently split only for [UID:0001IP].
- Decision: accepted source-file route and callback destination for both the empty-emitter repair and the exact child split. New source-bearing child pages should emit through [UID:0000O5] with the formal first-draft C++ blocks in this report; broad pages stay marker/container-only.

### 2. [UID:0000DZ] `by-class/StartupWindow.md`

- Evidence for: class identity, vtable, singleton, constructor/destructor, WndProc, fields, and class-owned method inventory.
- Evidence against: not an exact address-range body page; adding method bodies here would duplicate or bypass the exact by-memory children proposed in this report.
- Decision: emit a class route marker plus `[[CHILDREN]]`; no duplicate method bodies.

### 3. By-global semantic pages

- Evidence for: `g_pStartupWindow`, `g_startupWindowClassAtom`, and `g_useEpfAssets` are exact global declarations with known storage and source route.
- Evidence against: exact by-memory children already document storage; both layers must not define the same symbol.
- Decision: by-global pages emit the source declaration and child insertion; exact storage pages emit no-duplicate storage markers.

### 4. Broad by-memory/by-item aggregate pages

- Evidence for: [UID:0001IO], [UID:0000VI], [UID:00026K], and [UID:0002AM] preserve necessary evidence for split, raw route, vtable/string data, and global cluster state.
- Evidence against: none is one source-level body.
- Decision: create exact child pages first, then emit no-standalone/non-emitting markers for [UID:0001IO] and [UID:0000VI]. [UID:00026K] and [UID:0002AM] remain marker-only support pages.

### 5. Rejected external owners

- `Browser`, `ImageLoaders`, `MiniMapVersionManager`, `MD5`, libcurl, `Application`, `Config`, `MainUiGraph`, and pane/render consumers remain dependencies or readers, not direct owners of the current empty emitters.

## Source Placement

Recommended source placement remains `NexusTK/app/StartupWindow.cpp`.

The source file should contain:

- StartupWindow class method bodies through exact child pages created by this split plan.
- File-local notice update helper callbacks, WndProc, and raw helper bodies through exact child pages created by this split plan.
- `static StartupWindow *g_pStartupWindow;`
- `static ATOM g_startupWindowClassAtom;`
- process-visible `bool g_useEpfAssets = true;`
- `static const char *g_szBaramNoticeWndClass = "BaramNoticeWnd_Class";`
- `static const char *g_szNoticeTitle = "Notice";`
- the already emitted `static size_t CurlWriteCallback(...)`.

Rejected placements:

- Browser source owns browser/OLE hosting, not the startup news URL or update notice orchestration.
- ImageLoaders owns PCX decoding, not startup notice resource choices.
- MiniMapVersionManager owns local minimap version/hash persistence, not the remote startup fetch path.
- `Application.cpp` and `Config`/`RegistryConfig` do not have direct refs to `g_useEpfAssets` under the accepted B001 owner audit.

## Range / Split / Padding / Reclassification Analysis

The exact [UID:0001IO] split plan is implementation-ready now. The first callback should create the exact child pages below, validate them so real UIDs are assigned, update parent/support docs with validator-resolved links, and only then change [UID:0001IO] and [UID:0000VI] to non-emitting documentation containers. Use temporary links such as `[TMP:"by-memory/0x005807d0-0x0058080c.StartupWindowConstructor.md"]` until the validator assigns real UIDs; do not guess UIDs.

Primary metadata policy for new source-bearing children:

- `CANONICAL_OWNER:0000DZ` for class methods/destructor/accessor children.
- `CANONICAL_OWNER:0000O5` for file-local WndProc/helper/string-helper children.
- `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, and the exact formal first-draft C++ block from `Formal C++ For Proposed Child Emitters` for every source-authored executable child that clears the current `(COMPLETION + CONFIDENCE) / 2 > 85` gate, including the tiny `StartupWindowGetInstanceHandle` accessor.
- `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank formal C++ for padding and compiler-generated wrapper/no-hand-authored-source children.
- New child pages should carry `Item Summary`, `Status`, `Covered Range`, `Evidence`, `Boundary And Padding`, `Ownership / Source Placement`, `C++ Disposition`, `Cross-References`, and `Changes` sections at the same factual detail as [UID:0001IO] and [UID:0000VI].

Exact child/source-body split matrix:

| Range | Existing/proposed child page | Owner/emitter metadata | Formal C++ or no-code disposition | Required proof to preserve |
| --- | --- | --- | --- | --- |
| `0x005807d0-0x0058080c` | Create `by-memory/0x005807d0-0x0058080c.StartupWindowConstructor.md` | `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000DZ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5` | Emit formal `StartupWindow::StartupWindow(HINSTANCE instance)` block from this report. | `_WinMain@16` caller, singleton/vtable/HINSTANCE/global writes, clears flags, exact constructor boundary. |
| `0x0058080c-0x00580810` | No new page; record as ignored padding only in parent/child boundary prose. | `RECONSTRUCTABLE:FALSE` if a padding row is ever materialized. | No code. | Four `0xcc` bytes; do not fold into constructor or destructor. |
| `0x00580810-0x00580870` | Create `by-memory/0x00580810-0x00580870.StartupWindowOrdinaryDestructor.md` | `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000DZ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5` | Emit formal `StartupWindow::~StartupWindow()` block from this report; no-direct-start-ref caveat remains source-route evidence, not a no-code blocker. | Valid destructor-like body, vtable/global refs, object-release behavior, no rel32/VA/RVA/direct start refs. |
| `0x00580870-0x005810fd` | Create `by-memory/0x00580870-0x005810fd.StartupWindowRunUpdateCheck.md` | `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000DZ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5` | Emit formal `int StartupWindow::RunUpdateCheck(bool *runUpdater)` block from this report. | `_WinMain@16` caller, class registration/window creation, Browser URL, registry `updvr`, libcurl fetches, version/minimap parse, message loop/cleanup. |
| `0x005810fd-0x00581100` | No new page; ignored padding. | `RECONSTRUCTABLE:FALSE` if materialized. | No code. | Three `0xcc` bytes. |
| `0x00581100-0x005815aa` | Create `by-memory/0x00581100-0x005815aa.StartupWindowUpdateCheckWindowProc.md` | `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5` | Emit formal `static LRESULT CALLBACK StartupWindowUpdateCheckWindowProc(...)` block from this report. | WndProc data refs from `RunUpdateCheck` and raw setup, reads `g_pStartupWindow`, key/mouse/paint/link behavior, PCX draw/helper calls. |
| `0x005815aa-0x005815b0` | No new page; ignored padding. | `RECONSTRUCTABLE:FALSE` if materialized. | No code. | Six `0xcc` bytes before raw helper. |
| `0x005815b0-0x0058165a` | Create `by-memory/0x005815b0-0x0058165a.StartupNoticePostButtonResult.md` | `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5` | Emit formal `static void StartupNoticePostButtonResult(...)` block from this report; no-function/no-direct-ref caveat remains documented. | Security-cookie frame, update/close activation, state update, posts `WM_USER+11`, corrected final `ret 4`, no direct refs. |
| `0x0058165a-0x00581660` | No new page; ignored padding. | `RECONSTRUCTABLE:FALSE` if materialized. | No code. | Six `0xcc` bytes. |
| `0x00581660-0x00581664` | Create `by-memory/0x00581660-0x00581664.StartupWindowGetInstanceHandle.md` | `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000DZ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5` | Emit formal `HINSTANCE StartupWindow::GetInstanceHandle() const` block from this report; no-current-caller caveat remains evidence, not a no-code blocker. | Returns `this+0x08` HINSTANCE; no current callers; exact four-byte IDA function. |
| `0x00581664-0x00581670` | No new page; ignored padding. | `RECONSTRUCTABLE:FALSE` if materialized. | No code. | Twelve `0xcc` bytes. |
| `0x00581670-0x00581724` | Create `by-memory/0x00581670-0x00581724.StartupNoticeResetButtonStates.md` | `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5` | Emit formal `static void StartupNoticeResetButtonStates(...)` block from this report. | WndProc callers, clears two button states, invalidates changed rects, exact `0xb4` IDA function. |
| `0x00581724-0x00581730` | No new page; ignored padding. | `RECONSTRUCTABLE:FALSE` if materialized. | No code. | Twelve `0xcc` bytes. |
| `0x00581730-0x005817a0` | Create `by-memory/0x00581730-0x005817a0.StartupNoticeSetButtonState.md` | `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5` | Emit formal `static void StartupNoticeSetButtonState(...)` block from this report. | WndProc/raw-helper callers, two `0x20`-stride button state slots, invalidates changed rect, `ret 8` immediate belongs to body. |
| `0x005817a0-0x005817dd` | Create `by-memory/0x005817a0-0x005817dd.StartupNoticeHitTestButton.md` | `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5` | Emit formal `static int StartupNoticeHitTestButton(...)` block from this report. | WndProc callers, scans two button rectangles and returns index or `-1`. |
| `0x005817dd-0x005817e0` | No new page; ignored padding. | `RECONSTRUCTABLE:FALSE` if materialized. | No code. | Three `0xcc` bytes. |
| `0x005817e0-0x00581854` | Create `by-memory/0x005817e0-0x00581854.StartupNoticeInvalidateButtons.md` | `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5` | Emit formal `static void StartupNoticeInvalidateButtons(...)` block from this report. | Invalidates both button rectangles, corrected final `ret`, no direct start refs. |
| `0x00581854-0x00581860` | No new page; ignored padding. | `RECONSTRUCTABLE:FALSE` if materialized. | No code. | Twelve `0xcc` bytes. |
| `0x00581860-0x005818c3` | Create `by-memory/0x00581860-0x005818c3.StartupNoticeInvalidateButton.md` | `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5` | Emit formal `static void StartupNoticeInvalidateButton(...)` block from this report. | Invalidates one indexed button rectangle, corrected final `ret 4`, no direct start refs. |
| `0x005818c3-0x005818d0` | No new page; ignored padding. | `RECONSTRUCTABLE:FALSE` if materialized. | No code. | Thirteen `0xcc` bytes. |
| `0x005818d0-0x005819cc` | Create `by-memory/0x005818d0-0x005819cc.StartupNoticeLoadAssets.md` | `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5` | Emit formal `static void StartupNoticeLoadAssets(...)` block from this report. | Lazy PCX loader for `brm_main`, `brm_st_a/b/c`, `brm_ex_a/b`, initializes button rects/state, corrected final `ret 4`. |
| `0x005819cc-0x005819d0` | No new page; ignored padding. | `RECONSTRUCTABLE:FALSE` if materialized. | No code. | Four `0xcc` bytes. |
| `0x005819d0-0x00581b75` | Create `by-memory/0x005819d0-0x00581b75.StartupNoticeCreateWindowRaw.md` | `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5` | Emit formal `static bool StartupNoticeCreateWindowRaw(...)` block from this report; name stays private/static, not public API. | Builds `WNDCLASSEXA`, uses WndProc/class/title slots, registers class, creates centered 500x430 HWND, stores `this+0x0c`, no direct start refs. |
| `0x00581b75-0x00581b80` | No new page; ignored padding. | `RECONSTRUCTABLE:FALSE` if materialized. | No code. | Eleven `0xcc` bytes. |
| `0x00581b80-0x00581ce6` | Existing [UID:0001IP] `by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md` | Already `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5` | Already emits formal `static size_t CurlWriteCallback(...)`; do not duplicate it. | Two libcurl callback-pointer setup refs in `RunUpdateCheck`; text append behavior; direct StartupWindow route already applied. |
| `0x00581ce6-0x00581cf0` | No new page; ignored padding. | `RECONSTRUCTABLE:FALSE` if materialized. | No code. | Ten `0xcc` bytes. |
| `0x00581cf0-0x00581d30` | Create `by-memory/0x00581cf0-0x00581d30.StartupAnsiRangeToWideString.md` | `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5` | Emit formal `static std::wstring StartupAnsiRangeToWideString(...)` block from this report. | Only observed callers in `RunUpdateCheck`; converts selected ANSI response ranges into UTF-16 strings. |
| `0x00581d30-0x00581db2` | Create `by-memory/0x00581d30-0x00581db2.StartupWindowScalarDeletingDestructor.md` | `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000DZ`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS` | No code. Compiler-generated scalar deleting destructor wrapper should be regenerated from the class destructor, not hand-authored. | Vtable slot at `0x0062d470`, vtable write refs, conditional delete wrapper shape, duplicated release behavior. |
| `0x00581db2-0x00581dc0` | No new page; ignored padding. | `RECONSTRUCTABLE:FALSE` if materialized. | No code. | Fourteen `0xcc` bytes. |
| `0x00581dc0-0x00581e35` | Create `by-memory/0x00581dc0-0x00581e35.StartupNoticeDrawPcxImage.md` | `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5` | Emit formal `static void StartupNoticeDrawPcxImage(...)` block from this report. | WndProc callers, compatible DC, bitmap select/blit/delete path. |
| `0x00581e35-0x00581e40` | No new page; ignored padding. | `RECONSTRUCTABLE:FALSE` if materialized. | No code. | Eleven `0xcc` bytes. |
| `0x00581e40-0x00581f46` | Create `by-memory/0x00581e40-0x00581f46.AnsiSmallStringFindFrom.md` | `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5` | Emit formal `static int AnsiSmallStringFindFrom(...)` block from this report. | All observed callers in `RunUpdateCheck`; ANSI SSO-like find-from-offset behavior. |
| `0x00581f46-0x00581f50` | No new page; ignored padding. | `RECONSTRUCTABLE:FALSE` if materialized. | No code. | Ten `0xcc` bytes. |
| `0x00581f50-0x0058206e` | Create `by-memory/0x00581f50-0x0058206e.AnsiSmallStringSubstring.md` | `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5` | Emit formal `static std::string AnsiSmallStringSubstring(...)` block from this report. | All observed callers in `RunUpdateCheck`; bounded ANSI SSO-like substring extraction. |
| `0x0058206e-0x00582070` | No new page; ignored padding before [UID:0001IR] successor. | `RECONSTRUCTABLE:FALSE` if materialized. | No code. | Two `0xcc` bytes before `StdioFile` successor. |

[UID:0000VI] reconciliation: the tracker covers the five raw helper bodies at `0x005815b0-0x0058165a`, `0x005817e0-0x00581854`, `0x00581860-0x005818c3`, `0x005818d0-0x005819cc`, and `0x005819d0-0x00581b75`. Those exact ranges are included above as proposed child pages. [UID:0000VI] should not absorb `0x00580810-0x00580870` because that destructor-like body is outside the tracker title/range; [UID:0001IO] owns that broader split inventory.

After these children exist, [UID:0001IO] should change to `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank formal C++. [UID:0000VI] should change to `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0001IO`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank formal C++. If the validator rejects a by-item owner of [UID:0001IO], keep [UID:0000VI] `CANONICAL_OWNER:0000O5` but still make it non-emitting and record the validator limitation; do not keep it as an emitter. These blank formal blocks are valid because they are containers/trackers, not source-bearing executable children.

## First-Draft C++ Recommendation

Eligible for declaration C++ now:

### [UID:0002ZS] `by-global/g_pStartupWindow.md`

Recommended formal `RECONSTRUCTION_CPP CODE`:

```cpp
static StartupWindow *g_pStartupWindow;
[[CHILDREN]]
```

Rationale: exact singleton pointer storage is proven at `0x0069bac8`; constructor writes it, WndProc reads it, destructor paths clear it. The declaration belongs at by-global level; [UID:0002ZT] should not duplicate it.

### [UID:0002ZQ] `by-global/g_startupWindowClassAtom.md`

Recommended formal `RECONSTRUCTION_CPP CODE`:

```cpp
static ATOM g_startupWindowClassAtom;
[[CHILDREN]]
```

Rationale: `RegisterClassExA` returns/stores an `ATOM` in the two-byte cache. Current MCP confirms four refs and zeroed initial storage.

### [UID:0000SW] `by-global/g_useEpfAssets.md`

Recommended formal `RECONSTRUCTION_CPP CODE`:

```cpp
bool g_useEpfAssets = true;
[[CHILDREN]]
```

Rationale: current and executed evidence prove a one-byte `.data` item initialized to `1`, with constructor write `byte_66DA97 = 1`, broad reads as a current EPF/layout selector, and StartupWindow as the best current source-file owner. `bool` is the best current source-facing type; exact original declaration spelling remains unproven and caps score below final audit.

### [UID:000288] `by-memory/0x00670260-0x00670268.StartupWindowNoticePointerData.md`

Recommended formal `RECONSTRUCTION_CPP CODE`:

```cpp
static const char *g_szBaramNoticeWndClass = "BaramNoticeWnd_Class";
static const char *g_szNoticeTitle = "Notice";
```

Rationale: bytes are initialized pointers to `0x0062d418` and `0x0062d430`; current xrefs show `RunUpdateCheck` and raw alternate setup consume the slots as class name and notice title. These pointer declarations are source-level data, unlike the mixed [UID:00026K] `.rdata` island.

Executable-range C++ disposition for the first callback:

- [UID:0000DZ] class page remains a class route/inventory page with `[[CHILDREN]]`; no method bodies are pasted into the class page.
- [UID:0001IO] becomes a non-emitting split index only after the exact child pages in the split matrix are created and validated; its formal C++ remains blank.
- [UID:0000VI] becomes a non-emitting tracker only after the five raw-helper child pages in the split matrix are created and validated; its formal C++ remains blank.
- New source-bearing child pages are created with exact ranges and evidence, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, and exact formal first-draft C++ from this report. This prevents the split from creating new blank emitters while preserving child-specific source ownership on exact child pages.
- [UID:0001IP] already emits the accepted `CurlWriteCallback` formal C++; do not duplicate that body on any aggregate/tracker/class page.
- [UID:00026K] remains a no-standalone `.rdata` marker only.

### Formal C++ For Proposed Child Emitters

These blocks are the exact formal `RECONSTRUCTION_CPP CODE` insertion text recommended for the proposed child pages. Names are first-draft source-facing names; binary field offsets and behavior are preserved through the documented class fields and helper calls. The blocks intentionally avoid scalar-deleting-destructor output and do not duplicate [UID:0001IP] `CurlWriteCallback`.

`by-memory/0x005807d0-0x0058080c.StartupWindowConstructor.md`:

```cpp
StartupWindow::StartupWindow(HINSTANCE instance)
    : m_assetsLoaded(false),
      m_instance(instance),
      m_noticeWindow(NULL),
      m_backgroundImage(NULL),
      m_startNormalImage(NULL),
      m_startHoverImage(NULL),
      m_startPressedImage(NULL),
      m_exitNormalImage(NULL),
      m_exitPressedImage(NULL),
      m_resultReady(false)
{
    g_pStartupWindow = this;
    g_useEpfAssets = true;
    m_startButton.state = 0;
    m_exitButton.state = 0;
}
```

`by-memory/0x00580810-0x00580870.StartupWindowOrdinaryDestructor.md`:

```cpp
StartupWindow::~StartupWindow()
{
    ReleaseNoticeAssets();

    if (g_pStartupWindow == this) {
        g_pStartupWindow = NULL;
    }
}
```

`by-memory/0x00580870-0x005810fd.StartupWindowRunUpdateCheck.md`:

```cpp
int StartupWindow::RunUpdateCheck(bool *runUpdater)
{
    RECT windowRect = { 0, 0, 500, 430 };
    WNDCLASSEXA windowClass = {};

    windowClass.cbSize = sizeof(windowClass);
    windowClass.style = CS_OWNDC;
    windowClass.lpfnWndProc = StartupWindowUpdateCheckWindowProc;
    windowClass.hInstance = GetModuleHandleW(NULL);
    windowClass.hCursor = LoadCursorA(NULL, IDC_ARROW);
    windowClass.lpszClassName = g_szBaramNoticeWndClass;

    AdjustWindowRect(&windowRect, WS_POPUP | WS_BORDER | WS_SYSMENU, FALSE);

    int x = CW_USEDEFAULT;
    int y = CW_USEDEFAULT;
    RECT desktopRect;
    HWND desktopWindow = GetDesktopWindow();
    if (desktopWindow != NULL && GetWindowRect(desktopWindow, &desktopRect)) {
        OffsetRect(&windowRect,
                   desktopRect.left + (desktopRect.right - desktopRect.left) / 2 - (windowRect.right - windowRect.left) / 2 - windowRect.left,
                   desktopRect.top + (desktopRect.bottom - desktopRect.top) / 2 - (windowRect.bottom - windowRect.top) / 2 - windowRect.top);
        x = windowRect.left;
        y = windowRect.top;
    }

    if (g_startupWindowClassAtom == 0) {
        g_startupWindowClassAtom = RegisterClassExA(&windowClass);
        if (g_startupWindowClassAtom == 0) {
            return kAbortStartup;
        }
    }

    m_noticeWindow = CreateWindowExA(WS_EX_APPWINDOW,
                                    g_szBaramNoticeWndClass,
                                    g_szNoticeTitle,
                                    WS_POPUP | WS_BORDER | WS_SYSMENU,
                                    x,
                                    y,
                                    windowRect.right - windowRect.left,
                                    windowRect.bottom - windowRect.top,
                                    GetDesktopWindow(),
                                    NULL,
                                    windowClass.hInstance,
                                    NULL);
    if (m_noticeWindow == NULL) {
        return kAbortStartup;
    }

    ShowWindow(m_noticeWindow, SW_SHOW);
    UpdateWindow(m_noticeWindow);

    BrowserWindow *browser = new BrowserWindow(m_instance, m_noticeWindow, CRect(17, 96, 484, 336), "http://www.nexustk.com/news/news.asp");
    browser->SetVisible(true);

    DWORD localVersion = 0;
    DWORD valueType = REG_DWORD;
    DWORD valueSize = sizeof(localVersion);
    HKEY key = NULL;
    if (RegOpenKeyExW(HKEY_CURRENT_USER, L"Software\\KRU\\NexusTK", 0, KEY_READ, &key) == ERROR_SUCCESS) {
        RegQueryValueExW(key, L"updvr", NULL, &valueType, reinterpret_cast<BYTE *>(&localVersion), &valueSize);
        RegCloseKey(key);
    }

    std::string responseText;
    curl_global_init(CURL_GLOBAL_ALL);
    for (int attempt = 0; attempt < 2 && responseText.empty(); ++attempt) {
        CURL *curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_URL, "https://s3.amazonaws.com/kru-downloads/tk/update/nexustk.ver");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CurlWriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseText);
        if (curl_easy_perform(curl) != CURLE_OK) {
            responseText.clear();
        }
        curl_easy_cleanup(curl);
    }

    bool versionMatches = false;
    wchar_t minimapVersion[34] = {};
    if (!responseText.empty()) {
        int versionKey = AnsiSmallStringFindFrom(responseText, "version", 0);
        int versionColon = AnsiSmallStringFindFrom(responseText, ":", versionKey + 1);
        int versionStart = AnsiSmallStringFindFrom(responseText, "\n", versionColon + 1);
        int versionEnd = AnsiSmallStringFindFrom(responseText, "\n", versionStart + 1);
        int remoteVersion = atoi(AnsiSmallStringSubstring(responseText, versionStart + 1, versionEnd - versionStart - 1).c_str());
        versionMatches = (localVersion == static_cast<DWORD>(remoteVersion));

        int minimapKey = AnsiSmallStringFindFrom(responseText, "minimap", 0);
        if (minimapKey >= 0) {
            int minimapColon = AnsiSmallStringFindFrom(responseText, ":", minimapKey + 1);
            int minimapStart = AnsiSmallStringFindFrom(responseText, "\n", minimapColon + 1);
            int minimapEnd = AnsiSmallStringFindFrom(responseText, "\n", minimapStart + 1);
            std::wstring wideValue = StartupAnsiRangeToWideString(responseText.data() + minimapStart + 1, responseText.data() + minimapEnd);
            wcscpy_s(minimapVersion, 34, wideValue.c_str());
        }
    }

    if (_wcsicmp(g_pMiniMapVersionManager->GetVersionString(), minimapVersion) != 0) {
        std::string hashListText;
        for (int attempt = 0; attempt < 2 && hashListText.empty(); ++attempt) {
            CURL *curl = curl_easy_init();
            curl_easy_setopt(curl, CURLOPT_URL, "https://s3.amazonaws.com/kru-downloads/tk/minimaps/HashList.txt");
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(curl, CURLOPT_TIMEOUT, 20L);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CurlWriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &hashListText);
            if (curl_easy_perform(curl) != CURLE_OK) {
                hashListText.clear();
            }
            curl_easy_cleanup(curl);
        }
        if (!hashListText.empty()) {
            std::wstring wideHashList = StartupAnsiRangeToWideString(hashListText.data(), hashListText.data() + hashListText.length());
            g_pMiniMapVersionManager->UpdateHashList(minimapVersion, wideHashList.c_str(), true);
        }
    }

    m_resultReady = true;
    int result = kAbortStartup;
    if (versionMatches) {
        *runUpdater = false;
        MSG message;
        while (GetMessageA(&message, NULL, 0, 0) > 0) {
            TranslateMessage(&message);
            if (message.message == WM_CLOSE) {
                break;
            }
            if (message.message == WM_USER + 11) {
                result = static_cast<int>(message.wParam);
                break;
            }
            DispatchMessageA(&message);
        }
    } else {
        *runUpdater = true;
        result = kAbortStartup;
    }

    delete browser;
    ShowWindow(m_noticeWindow, SW_HIDE);
    DestroyWindow(m_noticeWindow);
    m_noticeWindow = NULL;
    return result;
}
```

`by-memory/0x00581100-0x005815aa.StartupWindowUpdateCheckWindowProc.md`:

```cpp
static LRESULT CALLBACK StartupWindowUpdateCheckWindowProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
    StartupWindow *startupWindow = g_pStartupWindow;
    if (startupWindow == NULL) {
        return DefWindowProcA(window, message, wParam, lParam);
    }

    if (message == WM_KEYDOWN || message == WM_SYSKEYDOWN) {
        if (wParam == VK_SPACE || wParam == VK_RETURN) {
            PostMessageA(window, WM_USER + 11, 1, 0);
        } else if (wParam == VK_ESCAPE) {
            PostMessageA(window, WM_CLOSE, 0, 0);
        } else if (wParam == VK_F4 && (GetAsyncKeyState(VK_LMENU) || GetAsyncKeyState(VK_RMENU))) {
            PostMessageA(window, WM_CLOSE, 0, 0);
        }
    }

    switch (message) {
    case WM_PAINT:
        if (GetUpdateRect(window, NULL, FALSE)) {
            PAINTSTRUCT paint;
            HDC dc = BeginPaint(window, &paint);
            if (!startupWindow->m_assetsLoaded) {
                StartupNoticeLoadAssets(startupWindow, dc);
            }
            StartupNoticeDrawPcxImage(dc, startupWindow->m_backgroundImage, 0, 0);
            for (int index = 0; index < 2; ++index) {
                const StartupNoticeButton &button = startupWindow->m_buttons[index];
                StartupNoticeDrawPcxImage(dc, button.images[button.state], button.rect.left, button.rect.top);
            }
            EndPaint(window, &paint);
        }
        return 1;

    case WM_MOUSEMOVE: {
        int button = StartupNoticeHitTestButton(startupWindow, LOWORD(lParam), HIWORD(lParam));
        if (button < 0) {
            StartupNoticeResetButtonStates(startupWindow);
        } else if ((wParam & MK_LBUTTON) != 0) {
            StartupNoticeSetButtonState(startupWindow, button, 1);
        } else if (button == 0) {
            StartupNoticeSetButtonState(startupWindow, 0, 2);
        }

        RECT linkRect;
        SetRect(&linkRect, 0, 0, 217, 64);
        OffsetRect(&linkRect, 147, 0);
        POINT cursorPoint;
        cursorPoint.x = LOWORD(lParam);
        cursorPoint.y = HIWORD(lParam);
        SetCursor(LoadCursorA(NULL, (PtInRect(&linkRect, cursorPoint) || button >= 0) ? MAKEINTRESOURCEA(0x92) : IDC_ARROW));
        return DefWindowProcA(window, message, wParam, lParam);
    }

    case WM_LBUTTONUP: {
        int button = StartupNoticeHitTestButton(startupWindow, LOWORD(lParam), HIWORD(lParam));
        if (button >= 0) {
            StartupNoticePostButtonResult(startupWindow, button);
        }
        StartupNoticeResetButtonStates(startupWindow);
        return 1;
    }

    case WM_LBUTTONDOWN: {
        int button = StartupNoticeHitTestButton(startupWindow, LOWORD(lParam), HIWORD(lParam));
        if (button >= 0) {
            StartupNoticeSetButtonState(startupWindow, button, 1);
        }
        RECT linkRect;
        SetRect(&linkRect, 0, 0, 217, 64);
        OffsetRect(&linkRect, 147, 0);
        POINT linkPoint;
        linkPoint.x = LOWORD(lParam);
        linkPoint.y = HIWORD(lParam);
        if (PtInRect(&linkRect, linkPoint)) {
            ShellExecuteA(NULL, NULL, "http://www.nexustk.com", NULL, NULL, SW_SHOWNORMAL);
        }
        return 1;
    }
    }

    return DefWindowProcA(window, message, wParam, lParam);
}
```

`by-memory/0x005815b0-0x0058165a.StartupNoticePostButtonResult.md`:

```cpp
static void StartupNoticePostButtonResult(StartupWindow *startupWindow, int buttonIndex)
{
    if (buttonIndex < 0 || buttonIndex >= 2) {
        return;
    }

    StartupNoticeSetButtonState(startupWindow, buttonIndex, 1);
    PostMessageA(startupWindow->m_noticeWindow, WM_USER + 11, buttonIndex == 0 ? 1 : 2, 0);
}
```

`by-memory/0x00581660-0x00581664.StartupWindowGetInstanceHandle.md`:

```cpp
HINSTANCE StartupWindow::GetInstanceHandle() const
{
    return m_instance;
}
```

`by-memory/0x00581670-0x00581724.StartupNoticeResetButtonStates.md`:

```cpp
static void StartupNoticeResetButtonStates(StartupWindow *startupWindow)
{
    for (int index = 0; index < 2; ++index) {
        StartupNoticeButton &button = startupWindow->m_buttons[index];
        if (button.state > 0) {
            button.state = 0;
            InvalidateRect(startupWindow->m_noticeWindow, &button.rect, FALSE);
        }
    }
}
```

`by-memory/0x00581730-0x005817a0.StartupNoticeSetButtonState.md`:

```cpp
static void StartupNoticeSetButtonState(StartupWindow *startupWindow, int buttonIndex, int state)
{
    StartupNoticeButton &button = startupWindow->m_buttons[buttonIndex];
    if (button.state != state) {
        button.state = state;
        InvalidateRect(startupWindow->m_noticeWindow, &button.rect, FALSE);
    }
}
```

`by-memory/0x005817a0-0x005817dd.StartupNoticeHitTestButton.md`:

```cpp
static int StartupNoticeHitTestButton(StartupWindow *startupWindow, int x, int y)
{
    POINT point = { x, y };
    for (int index = 0; index < 2; ++index) {
        if (PtInRect(&startupWindow->m_buttons[index].rect, point)) {
            return index;
        }
    }
    return -1;
}
```

`by-memory/0x005817e0-0x00581854.StartupNoticeInvalidateButtons.md`:

```cpp
static void StartupNoticeInvalidateButtons(StartupWindow *startupWindow)
{
    for (int index = 0; index < 2; ++index) {
        InvalidateRect(startupWindow->m_noticeWindow, &startupWindow->m_buttons[index].rect, FALSE);
    }
}
```

`by-memory/0x00581860-0x005818c3.StartupNoticeInvalidateButton.md`:

```cpp
static void StartupNoticeInvalidateButton(StartupWindow *startupWindow, int buttonIndex)
{
    InvalidateRect(startupWindow->m_noticeWindow, &startupWindow->m_buttons[buttonIndex].rect, FALSE);
}
```

`by-memory/0x005818d0-0x005819cc.StartupNoticeLoadAssets.md`:

```cpp
static void StartupNoticeLoadAssets(StartupWindow *startupWindow, HDC dc)
{
    if (startupWindow->m_assetsLoaded) {
        return;
    }

    startupWindow->m_assetsLoaded = true;
    startupWindow->m_backgroundImage = LoadPcxImage(dc, "brm_main.pcx", -1);
    startupWindow->m_startNormalImage = LoadPcxImage(dc, "brm_st_a.pcx", -1);
    startupWindow->m_startHoverImage = LoadPcxImage(dc, "brm_st_b.pcx", -1);
    startupWindow->m_startPressedImage = LoadPcxImage(dc, "brm_st_c.pcx", -1);
    startupWindow->m_exitNormalImage = LoadPcxImage(dc, "brm_ex_a.pcx", -1);
    startupWindow->m_exitPressedImage = LoadPcxImage(dc, "brm_ex_b.pcx", -1);

    startupWindow->m_buttons[0].images[0] = startupWindow->m_startNormalImage;
    startupWindow->m_buttons[0].images[1] = startupWindow->m_startPressedImage;
    startupWindow->m_buttons[0].images[2] = startupWindow->m_startHoverImage;
    SetRect(&startupWindow->m_buttons[0].rect, 183, 348,
            183 + startupWindow->m_startNormalImage->GetWidth(),
            348 + startupWindow->m_startNormalImage->GetHeight());
    startupWindow->m_buttons[0].state = 0;

    startupWindow->m_buttons[1].images[0] = startupWindow->m_exitNormalImage;
    startupWindow->m_buttons[1].images[1] = startupWindow->m_exitPressedImage;
    startupWindow->m_buttons[1].images[2] = startupWindow->m_exitNormalImage;
    SetRect(&startupWindow->m_buttons[1].rect, 474, 0,
            474 + startupWindow->m_exitNormalImage->GetWidth(),
            startupWindow->m_exitNormalImage->GetHeight());
    startupWindow->m_buttons[1].state = 0;
}
```

`by-memory/0x005819d0-0x00581b75.StartupNoticeCreateWindowRaw.md`:

```cpp
static bool StartupNoticeCreateWindowRaw(StartupWindow *startupWindow)
{
    WNDCLASSEXA windowClass = {};
    windowClass.cbSize = sizeof(windowClass);
    windowClass.style = CS_OWNDC;
    windowClass.lpfnWndProc = StartupWindowUpdateCheckWindowProc;
    windowClass.hInstance = GetModuleHandleW(NULL);
    windowClass.hCursor = LoadCursorA(NULL, IDC_ARROW);
    windowClass.lpszClassName = g_szBaramNoticeWndClass;

    RECT windowRect = { 0, 0, 500, 430 };
    AdjustWindowRect(&windowRect, WS_POPUP | WS_BORDER | WS_SYSMENU, FALSE);

    RECT desktopRect;
    if (GetWindowRect(GetDesktopWindow(), &desktopRect)) {
        OffsetRect(&windowRect,
                   desktopRect.left + (desktopRect.right - desktopRect.left) / 2 - (windowRect.right - windowRect.left) / 2 - windowRect.left,
                   desktopRect.top + (desktopRect.bottom - desktopRect.top) / 2 - (windowRect.bottom - windowRect.top) / 2 - windowRect.top);
    }

    if (g_startupWindowClassAtom == 0) {
        g_startupWindowClassAtom = RegisterClassExA(&windowClass);
        if (g_startupWindowClassAtom == 0) {
            return false;
        }
    }

    startupWindow->m_noticeWindow = CreateWindowExA(WS_EX_APPWINDOW,
                                                   g_szBaramNoticeWndClass,
                                                   g_szNoticeTitle,
                                                   WS_POPUP | WS_BORDER | WS_SYSMENU,
                                                   windowRect.left,
                                                   windowRect.top,
                                                   windowRect.right - windowRect.left,
                                                   windowRect.bottom - windowRect.top,
                                                   GetDesktopWindow(),
                                                   NULL,
                                                   windowClass.hInstance,
                                                   NULL);
    return startupWindow->m_noticeWindow != NULL;
}
```

`by-memory/0x00581cf0-0x00581d30.StartupAnsiRangeToWideString.md`:

```cpp
static std::wstring StartupAnsiRangeToWideString(const char *first, const char *last)
{
    std::string narrow(first, last);
    if (narrow.empty()) {
        return std::wstring();
    }

    std::vector<wchar_t> buffer(narrow.length() + 1);
    size_t converted = 0;
    mbstowcs_s(&converted, &buffer[0], buffer.size(), narrow.c_str(), narrow.length());
    return std::wstring(&buffer[0]);
}
```

`by-memory/0x00581dc0-0x00581e35.StartupNoticeDrawPcxImage.md`:

```cpp
static void StartupNoticeDrawPcxImage(HDC targetDc, PcxImage *image, int x, int y)
{
    HDC imageDc = CreateCompatibleDC(targetDc);
    if (image != NULL && image->GetBitmap() != NULL) {
        SelectObject(imageDc, image->GetBitmap());
        BitBlt(targetDc, x, y, image->GetWidth(), image->GetHeight(), imageDc, 0, 0, SRCCOPY);
    }
    SelectObject(imageDc, NULL);
    DeleteDC(imageDc);
}
```

`by-memory/0x00581e40-0x00581f46.AnsiSmallStringFindFrom.md`:

```cpp
static int AnsiSmallStringFindFrom(const std::string &text, const char *needle, unsigned int offset)
{
    std::string::size_type found = text.find(needle, offset);
    return found == std::string::npos ? -1 : static_cast<int>(found);
}
```

`by-memory/0x00581f50-0x0058206e.AnsiSmallStringSubstring.md`:

```cpp
static std::string AnsiSmallStringSubstring(const std::string &text, unsigned int offset, unsigned int count)
{
    if (offset > text.length()) {
        throw std::out_of_range("invalid string position");
    }
    return text.substr(offset, count);
}
```

No third-party import directive is applicable.

## Recommended Target Doc Changes

### `by-file/StartupWindow.md`

Add a `2026-07-01 B008 Generated Output Audit` section preserving:

- Generated file `auto-generated/NexusTK/app/StartupWindow.cpp`.
- Validator command baseline `000000003503`.
- Refreshed `2026-07-01T06:05:24-04:00`.
- Pre-callback state: `14` total emitters, `2` filled, `12` empty, `14.3%` filled, reports `0`.
- Current filled emitters [UID:0001IP] and [UID:000484].
- Current twelve empty markers and their disposition.
- Route split: [UID:0000O5] is the source-file route; exact callback/global/pointer pages emit source declarations; broad class/data/cluster pages emit markers only; [UID:0001IO] and [UID:0000VI] become non-emitting only after the exact child pages from this report are created.
- Preserve rejected owners/dependencies: Browser, ImageLoaders, MiniMapVersionManager, MD5, libcurl, Application, Config, MainUiGraph, and pane/render consumers are not direct owners of the current empty emitters.

Metadata remains unchanged at `89/88`, `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/app/"`.

## Recommended Support Doc Changes

- `by-class/StartupWindow.md`: no metadata change; insert formal class-route marker plus `[[CHILDREN]]`. Preserve WinMain result constants, Error EH rejection, vtable/singleton evidence, and exact split plan; no method bodies here.
- `by-global/g_pStartupWindow.md`: no metadata change; insert `static StartupWindow *g_pStartupWindow;` plus `[[CHILDREN]]`; add current MCP proof for refs at `0x005807e5`, `0x00581114`, `0x00581d94`, raw `0x00580864`.
- `by-memory/0x0069bac8-0x0069bacc.g_pStartupWindow.md`: no metadata change; insert no-duplicate storage marker; keep exact storage evidence and destructor-like caveat.
- `by-global/g_startupWindowClassAtom.md`: no metadata change; insert `static ATOM g_startupWindowClassAtom;` plus `[[CHILDREN]]`; add current MCP proof for four refs and zeroed storage.
- `by-memory/0x0069bac4-0x0069bac6.g_startupWindowClassAtom.md`: no metadata change; insert no-duplicate storage marker.
- `by-global/g_useEpfAssets.md`: no metadata change; insert `bool g_useEpfAssets = true;` plus `[[CHILDREN]]`; add current MCP session proof that constructor still writes `byte_66DA97 = 1` and current xref total remains `366`.
- `by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md`: no metadata change; insert no-duplicate storage marker; update stale item summary text to remove "remains autogen-unassigned after Batch070" and say the current route is exact storage -> [UID:0000SW] by-global -> [UID:0000O5] source file.
- Create the exact new child pages listed in `Range / Split / Padding / Reclassification Analysis`. Use `[TMP:"..."]` references until validators assign real UIDs; validate each new child page individually, then update parent/support links to the assigned UIDs. New source-bearing children route through `EMITTER_UIDS:0000O5` and receive the exact formal C++ blocks from `Formal C++ For Proposed Child Emitters`; only padding/container/compiler-wrapper pages are blank/no-emitter.
- `by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md`: after the five raw-helper child pages exist, change to `COMPLETION:88`, `CONFIDENCE:90`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and `CANONICAL_OWNER:0001IO` if validator accepts it; otherwise keep `CANONICAL_OWNER:0000O5` with a validator-limitation note. Formal C++ remains blank because this is a noncanonical tracker. Preserve exact raw-helper ranges, child links, current MCP no-function/no-xref proof, and the statement that `0x00580810-0x00580870` belongs to the broader [UID:0001IO] split, not this tracker.
- `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`: after all exact child pages exist, change to `COMPLETION:88`, `CONFIDENCE:90`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++, and split-index prose. Preserve current MCP split map, raw-helper no-xref proof, child links, and already filled [UID:0001IP] child route. Do not emit a no-monolithic marker if `RECONSTRUCTABLE:FALSE` requires blank formal C++; use prose/status instead.
- `by-memory/0x0062d418-0x0062d5a8.StartupWindowReadOnlyData.md`: no metadata change; insert no-standalone `.rdata` marker; preserve constant guidance and no hand-authored vtable/string table proof.
- `by-memory/0x00670260-0x00670268.StartupWindowNoticePointerData.md`: no metadata change; insert exact pointer declarations shown above.
- `by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md`: no metadata change; insert no-standalone update-state cluster marker plus `[[CHILDREN]]`; update item summary to remove stale "current-session IDA xref retries timed out" because this B008 pass successfully reconfirmed xrefs and zeroed bytes with live MCP.

## Score And Metadata Recommendation

| UID | Current | Recommendation | Rationale |
| --- | --- | --- | --- |
| `0000O5` | `89/88`, file root | unchanged | Source route already strong; this report supplies the exact child-body split/C++ plan without changing file-root metadata. |
| `0000DZ` | `88/89`, owner/emitter `0000O5` | unchanged | Class route marker resolves empty output without pretending broad class owns method bodies. |
| `0002ZS` | `86/88`, owner/emitter `0000O5` | unchanged | Add declaration C++; score can remain conservative pending original spelling. |
| `0002ZT` | `86/88`, owner/emitter `0002ZS` | unchanged | Marker only; exact storage child remains useful evidence. |
| `0002ZQ` | `87/90`, owner/emitter `0000O5` | unchanged | Add declaration C++; score already reflects type/use confidence. |
| `0002ZR` | `87/90`, owner/emitter `0002ZQ` | unchanged | Marker only; exact storage child remains useful evidence. |
| `0000SW` | `88/90`, owner/emitter `0000O5` | unchanged | Add best source-facing `bool` declaration; score remains capped by original spelling/type uncertainty. |
| `0001OH` | `88/90`, owner/emitter `0000SW` | unchanged | Marker only; repair stale item summary. |
| `0000VI` | `87/90`, owner/emitter `0000O5` | after raw-helper child pages exist: `88/90`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, owner `0001IO` if validator accepts it, otherwise keep `0000O5` with limitation note | It is a noncanonical tracker; the five raw bodies must be preserved by exact child pages before the tracker stops emitting. |
| `0001IO` | `86/88`, owner/emitter `0000O5` | after exact child pages exist: `88/90`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++ | It is not one function body; the source-bearing ranges are preserved by exact child pages and [UID:0001IP]. |
| `00026K` | `88/92`, owner/emitter `0000O5` | unchanged | Marker only; mixed `.rdata` should not hand-emit a table. |
| `000288` | `86/90`, owner/emitter `0000O5` | unchanged | Add pointer declarations; score remains capped by exact original pointer names. |
| `0002AM` | `87/89`, owner/emitter `0000O5` | unchanged | Marker only; exact child globals own declarations; reserved word remains no-source. |

## Open Questions With Attempted Resolution

- Exact original names for the globals and pointer slots are not recovered. Current docs already use `g_pStartupWindow`, `g_startupWindowClassAtom`, `g_useEpfAssets`, `g_szBaramNoticeWndClass`, and `g_szNoticeTitle`; current MCP validates the roles behind those names. This caps confidence but does not block first-draft declarations.
- Exact method/helper child pages are now part of the proposed first callback. Every source-bearing child page in the split plan must be created as `RECONSTRUCTABLE:TRUE`, must route through nonblank `EMITTER_UIDS:0000O5`, and must receive the exact formal `RECONSTRUCTION_CPP CODE` block supplied in `Formal C++ For Proposed Child Emitters` during implementation. Blank formal C++ is reserved only for the documented no-code pages: padding, containers/trackers, storage-only globals, `.rdata` support, and the compiler scalar-deleting destructor wrapper.
- `g_useEpfAssets` may have been declared as `BYTE`, `bool`, or another one-byte typedef. Current behavior is boolean selector with initial value `1` and comparisons against `1`; `bool` is the best current source-facing type. If the supervisor wants byte-preserving conservatism, `unsigned char g_useEpfAssets = 1;` is an acceptable alternate, but `bool g_useEpfAssets = true;` is the recommended source shape.

## Validator Results

No validators were run during this report-only pass.

Expected callback validators, from `E:\NTK\GhidraBridge\source-3\project-documentation`, one scoped file at a time with `--wait-generated`:

> Executable block R001 was removed from this report and preserved verbatim in [0000O5-StartupWindow-empty-emitter-family-source-quality-removed.md](0000O5-StartupWindow-empty-emitter-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Generated output expectation:

- `auto-generated/NexusTK/app/StartupWindow.cpp` header should be newer than baseline command `000000003503` / `2026-07-01T06:05:24-04:00`.
- The twelve current empty markers should no longer appear as `Empty Emitter Marker`.
- [UID:0001IP] `CurlWriteCallback` should remain present exactly once.
- Global declarations should not duplicate storage-marker declarations.
- [UID:0001IO] and [UID:0000VI] should no longer appear as empty emitters after they become non-emitting containers, and the newly created source-bearing child pages should emit their formal first-draft C++ blocks through [UID:0000O5].
- Broad class/read-only-data/cluster pages should emit only comments and child insertion, not method bodies or raw tables.

## Changed Files

Created by-memory child pages and validator-assigned UIDs:

| UID | Path | Applied disposition |
| --- | --- | --- |
| `0004CQ` | `by-memory/0x005807d0-0x0058080c.StartupWindowConstructor.md` | `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, formal `StartupWindow::StartupWindow(HINSTANCE instance)` C++ inserted. |
| `0004CR` | `by-memory/0x00580810-0x00580870.StartupWindowOrdinaryDestructor.md` | `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, formal `StartupWindow::~StartupWindow()` C++ inserted. |
| `0004CS` | `by-memory/0x00580870-0x005810fd.StartupWindowRunUpdateCheck.md` | `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, formal `StartupWindow::RunUpdateCheck(bool *runUpdater)` C++ inserted. |
| `0004CT` | `by-memory/0x00581100-0x005815aa.StartupWindowUpdateCheckWindowProc.md` | `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, formal WndProc C++ inserted. |
| `0004CU` | `by-memory/0x005815b0-0x0058165a.StartupNoticePostButtonResult.md` | `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, formal notice post-result C++ inserted. |
| `0004CV` | `by-memory/0x00581660-0x00581664.StartupWindowGetInstanceHandle.md` | `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, formal instance-handle accessor C++ inserted. |
| `0004CW` | `by-memory/0x00581670-0x00581724.StartupNoticeResetButtonStates.md` | `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, formal reset-button-states C++ inserted. |
| `0004CX` | `by-memory/0x00581730-0x005817a0.StartupNoticeSetButtonState.md` | `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, formal set-button-state C++ inserted. |
| `0004CY` | `by-memory/0x005817a0-0x005817dd.StartupNoticeHitTestButton.md` | `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, formal hit-test C++ inserted. |
| `0004CZ` | `by-memory/0x005817e0-0x00581854.StartupNoticeInvalidateButtons.md` | `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, formal invalidate-buttons C++ inserted. |
| `0004D0` | `by-memory/0x00581860-0x005818c3.StartupNoticeInvalidateButton.md` | `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, formal invalidate-button C++ inserted. |
| `0004D1` | `by-memory/0x005818d0-0x005819cc.StartupNoticeLoadAssets.md` | `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, formal load-assets C++ inserted. |
| `0004D2` | `by-memory/0x005819d0-0x00581b75.StartupNoticeCreateWindowRaw.md` | `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, formal raw create-window C++ inserted. |
| `0004D3` | `by-memory/0x00581cf0-0x00581d30.StartupAnsiRangeToWideString.md` | `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, formal ANSI-to-wide helper C++ inserted. |
| `0004D4` | `by-memory/0x00581d30-0x00581db2.StartupWindowScalarDeletingDestructor.md` | `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++, compiler-wrapper proof preserved. |
| `0004D5` | `by-memory/0x00581dc0-0x00581e35.StartupNoticeDrawPcxImage.md` | `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, formal PCX draw helper C++ inserted. |
| `0004D6` | `by-memory/0x00581e40-0x00581f46.AnsiSmallStringFindFrom.md` | `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, formal find helper C++ inserted. |
| `0004D7` | `by-memory/0x00581f50-0x0058206e.AnsiSmallStringSubstring.md` | `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, formal substring helper C++ inserted. |

Modified existing by-* docs:

- `by-file/StartupWindow.md`
- `by-class/StartupWindow.md`
- `by-global/g_pStartupWindow.md`
- `by-memory/0x0069bac8-0x0069bacc.g_pStartupWindow.md`
- `by-global/g_startupWindowClassAtom.md`
- `by-memory/0x0069bac4-0x0069bac6.g_startupWindowClassAtom.md`
- `by-global/g_useEpfAssets.md`
- `by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md`
- `by-memory/0x00670260-0x00670268.StartupWindowNoticePointerData.md`
- `by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md`
- `by-memory/0x0062d418-0x0062d5a8.StartupWindowReadOnlyData.md`
- `by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md`
- `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`
- `tools/leaser/Agents/Agent-B008/research/0000O5-StartupWindow-empty-emitter-family-source-quality.md`

No generated reports, generated C++ files, project-level generated reports, manual `-coverage-report.md` files, validator/tool state, queue files, archives, supervisor ledgers, by-project-structure docs, or IDA DB were manually edited.

Leases:

- Short B008 leases were used only for the active by-* edit/validator batch.
- Lease cleanup confirmed `B008: No active leases`; current shared lease report showed no B008 leases remaining.

## Validator Results

All scoped validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` with `--apply --queue-timeout 240 --wait-generated`, ending with `by-file/StartupWindow.md`.

| Scope | Command id / timestamp | Exit / ok | Result |
| --- | --- | --- | --- |
| `by-memory/0x005807d0-0x0058080c.StartupWindowConstructor.md` | `000000003695` / `2026-07-01T07:02:41-04:00` | exit `0` | UID `0004CQ` assigned; generated refresh completed. |
| `by-memory/0x00580810-0x00580870.StartupWindowOrdinaryDestructor.md` | `000000003697` / `2026-07-01T07:02:53-04:00` | exit `0` | UID `0004CR` assigned; generated refresh completed. |
| `by-memory/0x00580870-0x005810fd.StartupWindowRunUpdateCheck.md` | `000000003699` / `2026-07-01T07:03:13-04:00` | exit `0` | UID `0004CS` assigned; generated refresh completed. |
| `by-memory/0x00581100-0x005815aa.StartupWindowUpdateCheckWindowProc.md` | `000000003701` / timestamp not retained in captured console output; ran between `2026-07-01T07:03:13-04:00` and `2026-07-01T07:03:54-04:00` | exit `0` | UID `0004CT` assigned; generated refresh completed. |
| `by-memory/0x005815b0-0x0058165a.StartupNoticePostButtonResult.md` | `000000003703` / `2026-07-01T07:03:54-04:00` | exit `0` | UID `0004CU` assigned; generated refresh completed. |
| `by-memory/0x00581660-0x00581664.StartupWindowGetInstanceHandle.md` | `000000003704` / `2026-07-01T07:04:16-04:00` | exit `0` | UID `0004CV` assigned; generated refresh completed. |
| `by-memory/0x00581670-0x00581724.StartupNoticeResetButtonStates.md` | `000000003705` / `2026-07-01T07:04:28-04:00` | exit `0` | UID `0004CW` assigned; generated refresh completed. |
| `by-memory/0x00581730-0x005817a0.StartupNoticeSetButtonState.md` | `000000003706` failed transient generated-write permission; retry `000000003707` / `2026-07-01T07:05:16-04:00` | retry exit `0`, `ok:1` | UID `0004CX` assigned; retry succeeded. Failure was unrelated write permission replacing `auto-generated/NexusTK/third_party/LodePNG.cpp`. |
| `by-memory/0x005817a0-0x005817dd.StartupNoticeHitTestButton.md` through `by-memory/0x00581f50-0x0058206e.AnsiSmallStringSubstring.md` | `000000003708` through `000000003717` | exit `0` after each scoped run | UIDs `0004CY` through `0004D7` assigned in path order; generated refresh completed. |
| `by-class/StartupWindow.md`; global/storage support docs through `by-memory/0x0069bac8-0x0069bacc.g_pStartupWindow.md` | `000000003718` through `000000003721` | exit `0` | Class route and early global/storage pages validated; generated refresh completed. |
| `by-global/g_startupWindowClassAtom.md` | `000000003722` / `2026-07-01T07:08:01-04:00` | exit `0`, `ok:1` | Atom global declaration validated. |
| `by-memory/0x0069bac4-0x0069bac6.g_startupWindowClassAtom.md` | `000000003723` / `2026-07-01T07:08:12-04:00` | exit `0`, `ok:1` | Atom storage marker validated. |
| `by-global/g_useEpfAssets.md` | `000000003724` failed transient generated-write permission; retry `000000003725` / `2026-07-01T07:08:45-04:00` | retry exit `0`, `ok:1` | `bool g_useEpfAssets = true;` validated. Failure was unrelated write permission replacing `auto-generated/NexusTK/social/SystemMessagePanes.cpp`. |
| `by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md` | `000000003726` / `2026-07-01T07:08:56-04:00` | exit `0`, `ok:1` | Storage marker and stale summary repair validated. |
| `by-memory/0x00670260-0x00670268.StartupWindowNoticePointerData.md` | `000000003727` / `2026-07-01T07:09:07-04:00` | exit `0`, `ok:1` | Pointer declarations validated. |
| `by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md` | `000000003728` / `2026-07-01T07:09:18-04:00` | exit `0`, `ok:1` | Cluster marker and stale summary repair validated. |
| `by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md` | `000000003729` / `2026-07-01T07:09:28-04:00` | exit `0`, `ok:11` | Non-emitting raw-helper tracker and child links validated. |
| `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md` | `000000003730` / `2026-07-01T07:09:39-04:00` | exit `0`, `ok:19` | Non-emitting split/index and child links validated. |
| `by-memory/0x0062d418-0x0062d5a8.StartupWindowReadOnlyData.md` | `000000003731` / `2026-07-01T07:09:51-04:00` | exit `0`, `ok:1` | `.rdata` no-standalone marker validated. |
| `by-file/StartupWindow.md` | `000000003732` / `2026-07-01T07:10:02-04:00` | exit `0`, `ok:19` | Target by-file audit, dispositions, child split, and rejected owners validated. |

Known warnings: validator output repeated unrelated `autogen_children_marker_missing`, `autogen_children_fallback_insert`, and `autogen_emitter_has_no_code` warnings on unrelated pages. No target-specific validation failure remained after the two transient generated-write retries.

Generated output check:

- `auto-generated/NexusTK/app/StartupWindow.cpp` refreshed to command `000000003753`, `2026-07-01T07:16:07-04:00`, newer than final scoped command `000000003732` and newer than baseline `000000003503` / `2026-07-01T06:05:24-04:00`.
- Generated `StartupWindow.cpp` no longer contains `Empty Emitter Marker` for UID0000DZ, UID0002ZS, UID0002ZT, UID0002ZQ, UID0002ZR, UID0000SW, UID0001OH, UID0000VI, UID0001IO, UID00026K, UID000288, or UID0002AM.
- [UID:0001IP] `CurlWriteCallback` remains present as one formal function body and is not duplicated by broad aggregates.
- [UID:0000VI] and [UID:0001IO] are no longer empty emitters; their exact source-bearing child pages emit through [UID:0000O5].

## Claim And Incorporation Ledger

| Claim ID | Claim | Destination doc/section | Action | Verification state | Proof |
| --- | --- | --- | --- | --- | --- |
| C01 | Generated baseline is command `000000003503`, refreshed `2026-07-01T06:05:24-04:00`, with `14` emitters, `2` filled, `12` empty, `14.3%`, reports `0`. | `by-file/StartupWindow.md` generated-output audit. | incorporate | applied | Added B008 generated-output audit; final by-file validator `000000003732` exit `0`, `ok:19`; generated header refreshed to `000000003753`. |
| C02 | The twelve empty markers are UID0000DZ, UID0002ZS, UID0002ZT, UID0002ZQ, UID0002ZR, UID0000SW, UID0001OH, UID0000VI, UID0001IO, UID00026K, UID000288, UID0002AM. | `by-file/StartupWindow.md` and support docs. | incorporate | applied | Disposition table added; generated inspection found no `Empty Emitter Marker` for those UIDs. |
| C03 | [UID:0000O5] remains the `NexusTK/app/StartupWindow.cpp` source-file route with metadata `89/88`, `CANONICAL_OWNER:FILE`, path `NexusTK/app/`. | `by-file/StartupWindow.md`. | already-present | already-present | Metadata preserved unchanged; route split prose added. |
| C04 | [UID:0000DZ] is a class route/inventory page and emits class marker plus `[[CHILDREN]]`, not method bodies. | `by-class/StartupWindow.md`. | incorporate | applied | Formal class marker inserted; validator range `000000003718`-`000000003721` completed. |
| C05 | [UID:0002ZS] emits `static StartupWindow *g_pStartupWindow;` plus `[[CHILDREN]]`. | `by-global/g_pStartupWindow.md`. | incorporate | applied | Formal declaration inserted; validator range `000000003718`-`000000003721` completed. |
| C06 | [UID:0002ZT] storage child emits a no-duplicate storage marker, not another pointer definition. | `by-memory/0x0069bac8-0x0069bacc.g_pStartupWindow.md`. | incorporate | applied | Storage marker inserted; validator `000000003721` exit `0`. |
| C07 | [UID:0002ZQ] emits `static ATOM g_startupWindowClassAtom;` plus `[[CHILDREN]]`. | `by-global/g_startupWindowClassAtom.md`. | incorporate | applied | Formal declaration inserted; validator `000000003722` exit `0`, `ok:1`. |
| C08 | [UID:0002ZR] storage child emits a no-duplicate storage marker, not another atom definition. | `by-memory/0x0069bac4-0x0069bac6.g_startupWindowClassAtom.md`. | incorporate | applied | Storage marker inserted; validator `000000003723` exit `0`, `ok:1`. |
| C09 | [UID:0000SW] emits `bool g_useEpfAssets = true;` plus `[[CHILDREN]]`. | `by-global/g_useEpfAssets.md`. | incorporate | applied | Formal declaration inserted; retry validator `000000003725` exit `0`, `ok:1`. |
| C10 | [UID:0001OH] storage child emits no-duplicate storage marker and removes stale autogen-unassigned wording. | `by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md`. | incorporate | applied | Marker and Item Summary repair validated by `000000003726`, exit `0`, `ok:1`. |
| C11 | [UID:0000VI] is a noncanonical raw-helper tracker, not a source body; after child creation it becomes non-emitting with child links. | `by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md`. | incorporate | applied | Metadata set to `88/90`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, child links to new UIDs; validator `000000003729`, exit `0`, `ok:11`. |
| C12 | [UID:0001IO] is a broad executable aggregate/split index, not one function body; after exact child pages it becomes non-emitting. | `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`. | incorporate | applied | Metadata set to `88/90`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++, child links; validator `000000003730`, exit `0`, `ok:19`. |
| C13 | [UID:00026K] emits only a no-standalone `.rdata` marker; no hand-authored vtable/COL/string table. | `by-memory/0x0062d418-0x0062d5a8.StartupWindowReadOnlyData.md`. | incorporate | applied | Formal no-standalone `.rdata` marker inserted; validator `000000003731`, exit `0`, `ok:1`. |
| C14 | [UID:000288] emits initialized pointer declarations for class/title slots. | `by-memory/0x00670260-0x00670268.StartupWindowNoticePointerData.md`. | incorporate | applied | Pointer declarations inserted; validator `000000003727`, exit `0`, `ok:1`. |
| C15 | [UID:0002AM] emits only a no-standalone cluster marker and stale MCP-timeout summary wording is removed. | `by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md`. | incorporate | applied | Formal cluster marker plus `[[CHILDREN]]` inserted; Item Summary repaired; validator `000000003728`, exit `0`, `ok:1`. |
| C16 | Browser, ImageLoaders, MiniMapVersionManager, MD5, libcurl, Application, Config, MainUiGraph, and pane/render consumers are rejected as direct owners. | `by-file/StartupWindow.md`; support prose. | incorporate | applied | Rejected-owner/source-placement rationale added to by-file audit; final validator `000000003732`, exit `0`, `ok:19`. |
| C17 | Generated reports, generated C++, project-level reports, coverage reports, validator/tool state, archives, supervisor ledgers, and IDA DB must not be manually edited. | Callback scope and final report. | not-applicable | excluded-with-reason | No manual edits were made to excluded files; generated C++ changed only via validators. |
| C18 | The callback creates exact child pages for every source-bearing body in `0x005807d0-0x0058206e` except existing [UID:0001IP], with validator-assigned UIDs. | New by-memory child pages; parent/support docs. | incorporate | applied | Created UIDs `0004CQ`-`0004D7`; parent/support TMP references resolved by validator. |
| C19 | Constructor, destructor-like body, `RunUpdateCheck`, WndProc, raw notice helpers, modeled helpers, string helpers, draw helper, scalar wrapper, padding, and successor boundary are enumerated with range and C++/no-code disposition. | `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`; child pages. | incorporate | applied | Split/index and all child pages document boundaries and dispositions; validator `000000003730`, exit `0`, `ok:19`. |
| C20 | The five [UID:0000VI] raw helper spans reconcile to child pages `0004CU`, `0004CZ`, `0004D0`, `0004D1`, and `0004D2`; `0x00580810-0x00580870` is outside [UID:0000VI]. | `by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md`; raw child pages. | incorporate | applied | Tracker rows link to exact child UIDs; validator `000000003729`, exit `0`, `ok:11`. |
| C21 | New source-bearing child pages use `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, and exact formal first-draft C++; only compiler-wrapper/container/storage pages remain blank/no-emitter. | New child metadata/formal C++ blocks; generated output. | incorporate | applied | Source-bearing children `0004CQ`-`0004D3` and `0004D5`-`0004D7` emit formal C++; `0004D4`, trackers, and storage pages are no-code/non-emitting with proof. |
| C22 | `0x00581d30-0x00581db2.StartupWindowScalarDeletingDestructor` is a `RECONSTRUCTABLE:FALSE` compiler wrapper child, not hand-authored C++. | `by-memory/0x00581d30-0x00581db2.StartupWindowScalarDeletingDestructor.md`. | incorporate | applied | Created UID `0004D4` with blank formal C++, blank emitter, compiler-wrapper/vtable proof; validator in child batch exited `0`. |

## Implementation Tracking Checklist

- [x] `by-file/StartupWindow.md`: added generated-output audit baseline `000000003503`, refreshed `2026-07-01T06:05:24-04:00`, `14` total / `2` filled / `12` empty / `14.3%` / reports `0`; validator `000000003732`, exit `0`, `ok:19`.
- [x] `by-file/StartupWindow.md`: preserved metadata `89/88`, `CANONICAL_OWNER:FILE`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/app/"`.
- [x] `by-file/StartupWindow.md`: added twelve-empty-marker disposition, exact split/child repair summary, source route split, rejected owners/dependencies, and no-duplicate broad body policy.
- [x] `by-class/StartupWindow.md`: inserted class-route marker plus `[[CHILDREN]]`; no method bodies duplicated; validated in command range `000000003718`-`000000003721`.
- [x] `by-global/g_pStartupWindow.md`: inserted `static StartupWindow *g_pStartupWindow;` plus `[[CHILDREN]]`; no metadata change; validated in command range `000000003718`-`000000003721`.
- [x] `by-memory/0x0069bac8-0x0069bacc.g_pStartupWindow.md`: inserted no-duplicate storage marker; validator `000000003721`, exit `0`.
- [x] `by-global/g_startupWindowClassAtom.md`: inserted `static ATOM g_startupWindowClassAtom;` plus `[[CHILDREN]]`; validator `000000003722`, exit `0`, `ok:1`.
- [x] `by-memory/0x0069bac4-0x0069bac6.g_startupWindowClassAtom.md`: inserted no-duplicate storage marker; validator `000000003723`, exit `0`, `ok:1`.
- [x] `by-global/g_useEpfAssets.md`: inserted `bool g_useEpfAssets = true;` plus `[[CHILDREN]]`; retry validator `000000003725`, exit `0`, `ok:1` after unrelated transient generated-write failure `000000003724`.
- [x] `by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md`: inserted no-duplicate storage marker and removed stale autogen-unassigned Item Summary wording; validator `000000003726`, exit `0`, `ok:1`.
- [x] Created `by-memory/0x005807d0-0x0058080c.StartupWindowConstructor.md` as UID `0004CQ`; metadata/formal constructor C++ applied; validator `000000003695`, exit `0`.
- [x] Created `by-memory/0x00580810-0x00580870.StartupWindowOrdinaryDestructor.md` as UID `0004CR`; metadata/formal destructor C++ applied; validator `000000003697`, exit `0`.
- [x] Created `by-memory/0x00580870-0x005810fd.StartupWindowRunUpdateCheck.md` as UID `0004CS`; metadata/formal update-check C++ applied; validator `000000003699`, exit `0`.
- [x] Created `by-memory/0x00581100-0x005815aa.StartupWindowUpdateCheckWindowProc.md` as UID `0004CT`; metadata/formal WndProc C++ applied; validator `000000003701`, exit `0`.
- [x] Created `by-memory/0x005815b0-0x0058165a.StartupNoticePostButtonResult.md` as UID `0004CU`; metadata/formal raw helper C++ applied; validator `000000003703`, exit `0`.
- [x] Created `by-memory/0x00581660-0x00581664.StartupWindowGetInstanceHandle.md` as UID `0004CV`; metadata/formal accessor C++ applied; validator `000000003704`, exit `0`.
- [x] Created `by-memory/0x00581670-0x00581724.StartupNoticeResetButtonStates.md` as UID `0004CW`; metadata/formal helper C++ applied; validator `000000003705`, exit `0`.
- [x] Created `by-memory/0x00581730-0x005817a0.StartupNoticeSetButtonState.md` as UID `0004CX`; metadata/formal helper C++ applied; retry validator `000000003707`, exit `0`, `ok:1` after unrelated transient generated-write failure `000000003706`.
- [x] Created `by-memory/0x005817a0-0x005817dd.StartupNoticeHitTestButton.md` through `by-memory/0x00581f50-0x0058206e.AnsiSmallStringSubstring.md` as UIDs `0004CY` through `0004D7`; metadata/formal C++ or no-code wrapper proof applied; validators `000000003708`-`000000003717`, exit `0`.
- [x] Confirmed existing [UID:0001IP] `by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md` remained unchanged as the single curl callback emitter; generated output contains one formal `CurlWriteCallback` body.
- [x] `by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md`: converted to non-emitting tracker with metadata `88/90`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++; linked five exact child pages; validator `000000003729`, exit `0`, `ok:11`.
- [x] `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`: converted to non-emitting split/index with metadata `88/90`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++; linked exact children and preserved padding/no-broad-C++ proof; validator `000000003730`, exit `0`, `ok:19`.
- [x] `by-memory/0x0062d418-0x0062d5a8.StartupWindowReadOnlyData.md`: inserted no-standalone `.rdata` marker; validator `000000003731`, exit `0`, `ok:1`.
- [x] `by-memory/0x00670260-0x00670268.StartupWindowNoticePointerData.md`: inserted exact pointer declarations for `g_szBaramNoticeWndClass` and `g_szNoticeTitle`; validator `000000003727`, exit `0`, `ok:1`.
- [x] `by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md`: inserted no-standalone cluster marker plus `[[CHILDREN]]` and removed stale MCP-timeout Item Summary wording; validator `000000003728`, exit `0`, `ok:1`.
- [x] Preserved exact raw-helper split plan in `by-file/StartupWindow.md`, `by-class/StartupWindow.md`, new child pages, `by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md`, and `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`; no broad method body was created.
- [x] Ran scoped validators with `--wait-generated` for every edited accepted file; final target validator `000000003732`, `2026-07-01T07:10:02-04:00`, exit `0`, `ok:19`.
- [x] Inspected generated `auto-generated/NexusTK/app/StartupWindow.cpp`: header command `000000003753`, refreshed `2026-07-01T07:16:07-04:00`, newer than baseline `000000003503` and final by-file validator `000000003732`.
- [x] Inspected generated `StartupWindow.cpp`: UID0000DZ, UID0002ZS, UID0002ZT, UID0002ZQ, UID0002ZR, UID0000SW, UID0001OH, UID0000VI, UID0001IO, UID00026K, UID000288, and UID0002AM no longer appear as `Empty Emitter Marker`; new blank-emitter pages are non-emitting no-code pages.
- [x] Inspected generated `StartupWindow.cpp`: [UID:0001IP] `CurlWriteCallback` remains present once as a formal body and is not duplicated by the broad aggregate.
- [x] Did not manually edit generated reports, generated `auto-generated/NexusTK/**` files, project-level generated reports, coverage reports, validator/tool state, queue files, archives, supervisor ledgers, by-project-structure docs, or IDA DB.
- [x] Released B008 leases after the edit/validator batch; `python .\tools\leaser\leaser.py B008 unlease` returned `B008: No active leases`, and the shared lease report showed no B008 entries.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0000O5-StartupWindow-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0000O5-StartupWindow-empty-emitter-family-source-quality.md","timestamp":"2026-07-01T07:18:33","uid":"0000O5"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000O5-StartupWindow-empty-emitter-family-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/0000O5-StartupWindow-empty-emitter-family-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000O5"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
