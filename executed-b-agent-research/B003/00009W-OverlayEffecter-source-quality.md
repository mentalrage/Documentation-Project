** TARGET-REPORT-UID:00009W **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B003 Source-Quality Report: [UID:00009W] OverlayEffecter

Assignment: `B003-report-00009W-overlay-effecter-source-quality-20260625`  
Target: `by-class/OverlayEffecter.md`  
Report path: `tools/leaser/Agents/Agent-B003/research/00009W-OverlayEffecter-source-quality.md`  
Agent: `Agent-B003`  
Mode: report-only research

## Report-Only Compliance

- No target, support, generated, project-level, manual coverage, validator/cache, or IDA database files were edited.
- No leases were taken for this report-only pass.
- No subagents were spawned.
- IDA MCP evidence is current and mandatory evidence was gathered from endpoint `http://127.0.0.1:13337/mcp`.
- Active IDA database/session provenance: `80de0a67`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.

## Final Recommendation

Update `by-class/OverlayEffecter.md` from the current source header `COMPLETION:86`, `CONFIDENCE:88` to:

- `COMPLETION:90`
- `CONFIDENCE:91`
- Preserve `CANONICAL_OWNER:0000IZ`
- Preserve `RECONSTRUCTABLE:TRUE`
- Preserve `EMITTER_UIDS:0000IZ`
- Keep `EMITTER_POSITION_OPTIONAL` blank

The generated tracker row is stale at `76/82`; the source page is already ahead at `86/88`. Implementation should treat the source page as the authoritative target, apply the accepted source-quality changes there, then run scoped validators to refresh generated state. Do not hand-edit generated tracker or manual coverage files.

Recommended Item Summary:

`Pane-backed base class for overlay screen effects: constructs the inherited Pane view, registers it against the active MapPane bounds inset by map-tile dimensions, stores two overlay placement words, and relies on compiler-generated destructor wrappers/thunks for the Pane/GrafPort views.`

## Current State Problems

The target page has useful prior research but still contains source-quality blockers that should be resolved in the implementation callback:

- The page still references stale blank-C++ gate reasoning tied to old strict/final thresholds. The active gate is reconstructable true, nonblank emitter route, and average score above 85; this class clears that gate for declaration-level first-draft C++.
- The generated tracker row is older than the source page and should be reconciled by normal validator refresh, not by report-only edits.
- The base-helper ambiguity can now be tightened: `0x00544460` is `Pane::Pane`, `0x00544c70` is the layer-registration helper, `0x00544ce0` is Pane layer cleanup/removal, and `0x00544580` is `Pane::~Pane`.
- The vtable and adjusted-view layout should be documented with current MCP evidence, including the primary deleting-destructor slot and the three adjusted deleting-destructor thunks.
- The class should not emit handwritten scalar deleting destructor logic. The source-facing representation is a virtual destructor declaration, with the scalar deleting wrapper and adjustor thunks documented as compiler ABI output.

## Current MCP Evidence

MCP endpoint and status:

- `initialize` succeeded; server reported `ida-pro-mcp` protocol `2025-06-18`.
- `server_health` JSON-RPC id `4` returned status `ok`; Hex-Rays and string cache were ready.
- `idb_list` confirmed session/database `80de0a67`.

Core lookup and boundary evidence:

- `lookup_funcs` id `6` resolved `0x0055a2e0` as a 234-byte constructor range, `0x0055a560` as a 117-byte ordinary destructor range, and `0x0055bbf0` as a 157-byte scalar deleting destructor wrapper.
- The same lookup resolved support helpers `0x00544460`, `0x00544c70`, `0x00544ce0`, `0x00544580`, and `0x004f4ac0`.
- `int_convert` id `8` confirmed the important layout constants: `0xfc` is 252, `0xfe` is 254, `0xa4` is 164, and `0xa8` is 168.
- `get_bytes` id `17` confirmed the function bytes and MSVC prologues for the constructor, ordinary destructor, scalar deleting destructor, and nearby thunk island.

Constructor evidence:

- `decompile` id `10` and `disasm` id `19` show `0x0055a2e0` first installs the `PixelEffecter` primary vtable, then calls `Pane::Pane` at `0x00544460` with the first constructor byte argument on `this + 0x04`.
- The constructor installs four `OverlayEffecter` vtable views: primary `0x006235e8` at offset `0x00`, view `0x0062360c` at offset `0x04`, view `0x00623658` at offset `0xa4`, and view `0x00623688` at offset `0xa8`.
- It allocates a 16-byte rectangle object, asks `g_activeMapPane` at `0x0067a764` through virtual slot `+0x28` to fill that rectangle, insets left/right by `g_mapTilePixelWidth` at `0x0066da9c`, and insets top/bottom by `g_mapTilePixelHeight` at `0x0066daa0`.
- It stores the two 16-bit placement arguments at `this + 0xfc` and `this + 0xfe`.
- It then calls the Pane layer-registration helper at `0x00544c70` on `this + 0x04`, passing the rectangle, `g_activeMapPane`, zero, and the broader Main UI layer slot/global at `0x0069b364`.

Destructor evidence:

- `decompile` id `11` and `disasm` id `21` show the ordinary destructor range `0x0055a560-0x0055a5d5` restores the four `OverlayEffecter` views, calls the Pane cleanup/removal helper at `0x00544ce0`, calls `Pane::~Pane` at `0x00544580`, then resets the primary view to the `ScreenEffecter` vtable at `0x006235a4`.
- `xrefs_to` id `14` found no direct code xrefs to the ordinary destructor, which is expected for a compiler-emitted complete-object destructor body that can be reached through cleanup paths and deleting-destructor wrappers.
- `decompile` id `12` and `disasm` id `22` show scalar deleting destructor range `0x0055bbf0-0x0055bc8d` performs the same Pane teardown and then calls `OperatorDeleteWrapper` at `0x004f4ac0` only when `(flags & 1)` is set and `(flags & 4)` is clear.
- The flag-4 path uses guard/runtime glue with object size `0x100`; it should be documented as compiler/runtime glue and not translated into source-level class logic.

Vtable and thunk evidence:

- `get_int` id `16` read the primary group at `0x006235e8`: the primary deleting-destructor slot at `0x00623600` points to `0x0055bbf0`.
- The same read showed the adjusted-view first entries: `0x0062360c -> 0x0055ba40`, `0x00623658 -> 0x0055ba48`, and `0x00623688 -> 0x0055ba53`.
- `disasm` id `15` proves the adjusted thunks: `0x0055ba40` subtracts `0x04` from `ecx` and jumps to `0x0055bbf0`; `0x0055ba48` subtracts `0xa4`; `0x0055ba53` subtracts `0xa8`.
- `lookup_funcs` id `20` confirmed the surrounding vtable targets are short default stubs, no-op slots, inherited helper slots, and the scalar deleting destructor wrapper.
- `xrefs_to` id `14` tied the scalar wrapper to the primary vtable data xref at `0x00623600` and the three adjusted thunk code xrefs in the thunk island.

Helper evidence:

- `decompile 0x00544460` confirms the base helper is `Pane::Pane`: it initializes GrafPort/event/timer subobjects, installs Pane/GrafPort vtables, and stores the incoming Pane mode byte.
- `decompile 0x00544c70` confirms the helper attaches the Pane to a layer/list using either the parent-derived list or the supplied layer slot argument.
- `decompile 0x00544ce0` confirms the helper removes/unregisters a Pane from its layer state and clears the stored layer pointer.
- `decompile 0x00544580` confirms `Pane::~Pane`: it restores Pane vtables, removes/unregisters the Pane, frees subobjects, and runs GrafPort cleanup.
- `callees` id `13` confirms the constructor calls only `Pane::Pane`, `operator new(0x10)`, and the Pane layer-registration helper; the ordinary destructor calls only the Pane cleanup and Pane destructor helpers; the scalar wrapper adds `OperatorDeleteWrapper` and guard/runtime glue.

Sibling and support evidence:

- `xrefs_to` id `14` shows the constructor is called by OverlayImage, OverlayFrameImage, OverlayImageOnPoint, and OverlayMoving constructors.
- Current sibling pages and reports agree that derived overlay effecters call the base constructor with a fixed Pane mode byte and two 16-bit placement/dimension words, then install their own vtable groups.
- Existing accepted sibling reports reject handwritten scalar deleting destructors and treat adjusted view thunks as compiler ABI output, which matches the current OverlayEffecter evidence.
- `by-global/MapTilePixelDimensions.md` supports source-facing names `g_mapTilePixelWidth` and `g_mapTilePixelHeight`.
- `by-global/g_activeMapPane.md` and the active-map singleton support docs support source-facing `g_activeMapPane`, while preserving spelling caveats.
- `by-global/MainUiLayerSlots.md` supports treating `0x0069b364` as a broader UI layer slot/global dependency, not as an OverlayEffecter-owned global.

## Source Ownership and Placement

`OverlayEffecter` should remain canonically owned by [UID:0000IZ] `by-file/Effects.md`. It is part of the ScreenEffecter/PixelEffecter overlay effect family and is consumed by the derived overlay classes in that family. It is not owned by MapPane, Pane, Main UI layer globals, the vtable-data page, or the runtime-cluster aggregate.

The implementation path should continue to present the emitted source route through the Effects module. The old one-class recovered file path is staging evidence only; it should not override the source-facing owner. Exact source split remains below final audit: `render/Effects.cpp` is still the best supported route, while a private header or subfolder split is not disproven.

## Field, Helper, and Source-Facing Names

Recommended source-facing names and interpretations:

- `sub_544460` -> `Pane::Pane`
- `sub_544c70` -> Pane layer-registration helper, source-facing `Pane::AddToLayer` unless the broader Pane pass selects a more exact public name
- `sub_544ce0` -> Pane layer cleanup/removal helper, source-facing `Pane::RemoveFromLayer`/cleanup with final spelling deferred to Pane docs
- `sub_544580` -> `Pane::~Pane`
- `sub_4f4ac0` -> `OperatorDeleteWrapper`
- `dword_67a764` -> `g_activeMapPane`
- `word_66da9c` -> `g_mapTilePixelWidth`
- `word_66daa0` -> `g_mapTilePixelHeight`
- `unk_69b364` -> Main UI layer slot/global dependency; do not preserve the stale `g_pScreenEffecterList` alias as final source
- `this + 0xfc` and `this + 0xfe` -> two inherited overlay placement/dimension words; `m_overlayX` and `m_overlayY` are the best current class-page names, with a caveat that sibling reports still leave `paneWidth`/`paneHeight`, `overlayWidth`/`overlayHeight`, or `originX`/`originY` spelling variants open

The first constructor byte should be described as a Pane mode/type argument. Existing sibling calls pass a fixed byte value, and `Pane::Pane` stores that byte in Pane state.

## C++ Readiness and Exact Formal Block

The target clears the current code-entry gate because it is reconstructable, has a nonblank emitter route, and the recommended score average is above 85. The stale 95+/blank-C++ gate wording should be removed.

The correct class-page C++ is declaration-level. Method bodies should not be inserted on this class page in this pass because the constructor/destructor implementation ranges live in the broader runtime cluster, scalar deleting destructor logic is compiler-generated, and the exact original field/argument spelling remains below final audit. That is a target-specific source-placement policy, not a no-code gate failure.

Exact formal `RECONSTRUCTION_CPP CODE` insertion text:

```cpp
class OverlayEffecter : public PixelEffecter, public Pane
{
public:
    OverlayEffecter(unsigned char paneMode,
                    unsigned short overlayX,
                    unsigned short overlayY);
    virtual ~OverlayEffecter();

protected:
    unsigned short m_overlayX;
    unsigned short m_overlayY;
};
```

## Rejected Alternatives and Negative Evidence

- Reject treating the inherited Pane as a private data member. The four vtable views, adjusted thunks, and FilterEffecter precedent support multiple-inheritance source shape, not composition.
- Reject a handwritten `ScalarDeletingDestructor` source method. `0x0055bbf0` is an MSVC scalar deleting destructor wrapper, and the `0x0055ba40`, `0x0055ba48`, and `0x0055ba53` entries are adjustor thunks.
- Reject moving ownership to MapPane or Main UI layer globals. OverlayEffecter consumes `g_activeMapPane`, map tile dimensions, and a layer slot; those dependencies do not own the class.
- Reject moving ownership to `Pane` or `GrafPort`. The class constructs an inherited Pane view, but the semantic class family is the Effects module.
- Reject preserving generated placeholder names where current support names exist. The target should not leave `sub_544460`, `sub_544580`, `dword_67a764`, `word_66da9c`, or `word_66daa0` as final source-facing prose.
- Reject stale one-class generated source placement as final evidence. It is recovered staging output, not the best source route.
- Reject treating security-cookie and SEH cleanup blocks as source-level logic. They are compiler frame protection and exception cleanup scaffolding.
- Reject interpreting the flag-4 scalar deleting destructor path as user-authored class behavior. It is compiler/runtime glue.

## Score Rationale

Completion should rise to `90` because the class identity, owner/emitter, base layout, constructor flow, destructor flow, vtable layout, helper names, and compiler-generated destructor policy are now resolved enough for a declaration-level formal C++ block and detailed implementation notes.

Confidence should rise to `91` because the current MCP session directly confirms boundaries, bytes, decompilation, disassembly, xrefs, vtable slots, thunks, callees, and helper behavior. It should remain below final-audit confidence because exact original spelling for the two stored words and first constructor byte is not source-file proven, exact Effects source split/header placement remains open, and the final public names/signatures of Pane layer helper functions are owned by Pane/support docs.

## Residual Caveats

- `m_overlayX` and `m_overlayY` are high-confidence descriptive names, not final symbol-proven names.
- The first constructor byte is best described as a Pane mode/type; exact original parameter name is still not proven.
- The layer slot/global at `0x0069b364` is a dependency with support-level naming, not a final public Effects identifier.
- The exact original file split between `Effects.cpp`, a private header, or a subfolder remains support-level.
- The ordinary destructor has no direct code xrefs in the current query; its identity is supported by vtable/destructor-wrapper/cleanup evidence rather than direct callsite evidence.

## Implementation Tracking Checklist For Callback

- [x] `by-class/OverlayEffecter.md`: metadata is `COMPLETION:90`, `CONFIDENCE:91`; `CANONICAL_OWNER:0000IZ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000IZ`, and blank `EMITTER_POSITION_OPTIONAL` are preserved. The source `Item Summary` matches the accepted concise summary exactly. Proof: re-read header lines after validation on 2026-06-25.
- [x] `by-class/OverlayEffecter.md`: stale generated/source mismatch and old blank-C++ gate prose are replaced by the current `(COMPLETION + CONFIDENCE) / 2 > 85` gate result and declaration-level C++ policy. Proof: `## Reconstruction C++ Policy` section.
- [x] `by-class/OverlayEffecter.md`: exact formal class-declaration `RECONSTRUCTION_CPP CODE` block is present, with no constructor/destructor method bodies inserted on the class page. Proof: managed C++ block contains only `class OverlayEffecter : public PixelEffecter, public Pane`, constructor/destructor declarations, and `m_overlayX`/`m_overlayY`.
- [x] `by-class/OverlayEffecter.md`: current MCP session `80de0a67` evidence is incorporated for constructor/destructor/scalar-wrapper boundaries, sizes, bytes/prologues, lookup/decompile/disasm, callees, xrefs, vtable dwords, adjusted thunks, helper identities, and `int_convert` layout constants. Proof: `Constructor Data Flow`, `Destructor And Delete-Flag Policy`, `Vtable And Adjusted-View Layout`, `Helper And Global Naming Decisions`, and `Changes`.
- [x] `by-class/OverlayEffecter.md`: constructor behavior is documented at report-level detail: `Pane::Pane(this + 0x04, paneMode)`, four vtable stores, active MapPane rectangle query, map-tile inset, stores at `+0xfc/+0xfe`, and Pane layer registration through the Main UI layer slot dependency. Proof: `Constructor Data Flow`.
- [x] `by-class/OverlayEffecter.md`: ordinary destructor and scalar deleting destructor policy are documented: Pane cleanup/removal, `Pane::~Pane`, primary reset to `ScreenEffecter`, optional `OperatorDeleteWrapper` only for `(flags & 1) && !(flags & 4)`, and flag-4 runtime glue as non-source. Proof: `Destructor And Delete-Flag Policy`.
- [x] `by-class/OverlayEffecter.md`: vtable group layout and adjusted thunks are documented: primary `0x006235e8`, views `0x0062360c`, `0x00623658`, `0x00623688`, primary slot `0x00623600 -> 0x0055bbf0`, and thunks subtracting `0x04`, `0xa4`, and `0xa8`. Proof: `Vtable And Adjusted-View Layout`.
- [x] `by-class/OverlayEffecter.md`: stale helper/global placeholders are replaced or preserved only as evidence aliases. Proof: `Helper And Global Naming Decisions` maps `sub_544460`, `sub_544c70`, `sub_544ce0`, `sub_544580`, `sub_4f4ac0`, `dword_67a764`, `word_66da9c`, `word_66daa0`, and `unk_69b364` to source-facing names/caveats.
- [x] `by-class/OverlayEffecter.md`: residual caveats are preserved for exact field/parameter spelling, exact Effects source split, Main UI layer slot naming, Pane helper final public names, and no direct ordinary-destructor xrefs. Proof: `Residual Caveats`.
- [x] `by-file/Effects.md`: OverlayEffecter row and evidence are updated from stale parcel/render-layer wording to active MapPane bounds, map-tile-dimension inset, Pane registration, declaration-level C++ route, and compiler-generated destructor-wrapper policy. Proof: `File Role`, `Proposed Contents`, `Evidence`, and 2026-06-25 `Changes` entry.
- [x] `by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md`: OverlayEffecter constructor/destructor/scalar-wrapper evidence is synchronized and the runtime-cluster formal C++ block remains blank as broad aggregate policy. Proof: `Covered Ranges`, `2026-06-25 B003 OverlayEffecter base recheck`, and 2026-06-25 `Changes`.
- [x] `by-type/by-vtable/ScreenEffecterVtableFamily.md`: current OverlayEffecter primary deleting-destructor slot and three adjusted deleting-destructor thunks are present with compiler-generated no-source-body policy. Proof: `Overlay Effecter Tables` support sync and 2026-06-25 `Changes`.
- [x] `by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md`: same OverlayEffecter slot/thunk details are present and static handwritten vtable C++ remains blank. Proof: `Observed Contents`, `Evidence`, `Reconstruction Notes`, and 2026-06-25 `Changes`.
- [x] `by-class/ScreenEffecter.md`: checked for stale old-threshold wording. No edit was needed; the page already says blank C++ is a target-specific root/interface policy and not an old score-threshold rule.
- [x] `by-class/PixelEffecter.md`: inherited-base consistency was checked and the page contains the B003 support-gate note. It remains consistent with `OverlayEffecter : public PixelEffecter, public Pane`; validator command below covered this file.
- [x] `by-global/g_activeMapPane.md`, `by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md`, `by-global/MapTilePixelDimensions.md`, and `by-global/MainUiLayerSlots.md`: checked for direct contradictions. No edit was needed; they already describe `g_activeMapPane`, map-tile dimensions, and `0x0069b364` as external dependencies/slot storage, not OverlayEffecter-owned globals. The assignment path spelling `0x0067a764-0x0067a767...` resolves in-tree as `0x0067a764-0x0067a768.ActiveMapPaneSingleton.md`.
- [x] Do not edit generated files, manual coverage files, validator state/cache, project-level files, or the IDA database during implementation. Proof: no manual edits were made to generated/manual coverage/tool state/IDA DB; validator-owned generated/project-level outputs were updated only by validator commands.
- [x] Lease only exact files being edited/validated immediately and release leases immediately after the validator batch. Proof: B003 leased `by-class/OverlayEffecter.md`, `by-file/Effects.md`, `by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md`, `by-type/by-vtable/ScreenEffecterVtableFamily.md`, `by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md`, and `by-class/PixelEffecter.md`; final `unlease` returned `Success` for all six, and `current_leases.md` showed no B003 active leases afterward.
- [x] Run scoped validators for every changed by-* doc, including the required target command:
  - `python .\tools\validator.py --mode file --file by-class\OverlayEffecter.md --apply --queue-timeout 240 --wait-generated` -> exit `0`, `command_id: 000000001313`, `command_timestamp: 2026-06-25T06:03:53-04:00`, `ok: 1`, `generated_refresh: completed`, generated refresh id/timestamp `000000001313` / `2026-06-25T06:03:53-04:00`. Side effects: validator-owned autogen/report/projected-stats updates; unrelated stale-registry and memory coverage missing-file diagnostics were reported.
  - `python .\tools\validator.py --mode file --file by-file\Effects.md --apply --queue-timeout 240` -> exit `0`, `command_id: 000000001318`, `command_timestamp: 2026-06-25T06:04:17-04:00`, `ok: 1`, `generated_refresh: deferred`. Warnings: pre-existing `missing_ref_uid` for Lake child UIDs `0003HA/0003HC/0003HB/0003HD` and stale `0001GG` target path.
  - `python .\tools\validator.py --mode file --file by-memory\0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md --apply --queue-timeout 240` -> exit `0`, `command_id: 000000001323`, `command_timestamp: 2026-06-25T06:04:37-04:00`, `ok: 1`, `generated_refresh: deferred`. Warnings: pre-existing missing UID/path refs for StaticCloud/YFlip/Lake children and stale `0001GG` target path.
  - `python .\tools\validator.py --mode file --file by-type\by-vtable\ScreenEffecterVtableFamily.md --apply --queue-timeout 240` -> exit `0`, `command_id: 000000001324`, `command_timestamp: 2026-06-25T06:04:48-04:00`, `ok: 1`, `generated_refresh: deferred`. Warning: pre-existing stale `0001GG` target path.
  - `python .\tools\validator.py --mode file --file by-memory\0x006235a0-0x00623d18.ScreenEffecterVtableData.md --apply --queue-timeout 240` -> exit `0`, `command_id: 000000001325`, `command_timestamp: 2026-06-25T06:04:59-04:00`, `ok: 1`, `generated_refresh: deferred`. Warning: pre-existing stale `0001GG` target path.
  - `python .\tools\validator.py --mode file --file by-class\PixelEffecter.md --apply --queue-timeout 240` -> exit `0`, `command_id: 000000001328`, `command_timestamp: 2026-06-25T06:05:09-04:00`, `ok: 1`, `generated_refresh: deferred`. Warning: pre-existing stale `0001GG` target path.
- [x] After validation, re-read `by-class/OverlayEffecter.md` and generated `auto-generated/NexusTK/render/Effects.cpp` to confirm metadata, summary, and formal C++ survived generated refresh. Proof: source page still has `90/91`, accepted summary, and formal class block; after the deferred B003 generated refresh through command `000000001328` cleared, generated Effects output has `validator-command-id: 000000001328`, `validator-refreshed-at: 2026-06-25T06:05:09-04:00`, `validator-refresh-source: deferred-generated-refresh`, and includes the `// UID:00009W | by-class/OverlayEffecter.md | Completion:90 | Confidence:91` declaration block at lines 45-57.
- [x] If normal validation reverts the source page to stale `76/82`, old summary text, or blank C++, stop and report `PAUSED_VALIDATOR_METADATA_CONFLICT` with exact command id/timestamp/current header instead of editing coverage or validator state. Not triggered: the source page and generated Effects output retained the accepted metadata/summary/C++.

## Validator Plan For Implementation Callback

Run validators from `E:\NTK\GhidraBridge\source-3\project-documentation` after edits. The minimum target command should be:

`python .\tools\validator.py --mode file --file by-class\OverlayEffecter.md --apply --queue-timeout 240 --wait-generated`

Run the same scoped file validator pattern for each support doc changed by the implementation callback. Capture command id, command timestamp, exit code, ok count, and generated-refresh state in the checklist before final implementation closeout.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/00009W-OverlayEffecter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/00009W-OverlayEffecter-source-quality.md","timestamp":"2026-06-25T06:22:35","uid":"00009W"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
