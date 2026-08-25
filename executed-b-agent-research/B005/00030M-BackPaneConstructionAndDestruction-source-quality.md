** TARGET-REPORT-UID:00030M **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B005 Report - [UID:00030M] BackPaneConstructionAndDestruction Source Quality

Assignment: `B005-report-backpane-construction-destruction-source-quality-00030M-mcp-20260623`

Target: [UID:00030M] `by-memory/0x00467830-0x0046795c.BackPaneConstructionAndDestruction.md`

Report status: accepted by supervisor and implemented by B005 on 2026-06-23. During the report-only pass no by-* docs, generated/project-level files, IDB state, tool state, or `-coverage-report.md` files were edited; during the implementation callback only accepted target/support by-* docs were manually edited, and validator-owned generated/project-level side effects are recorded in the checklist.

## Current Target State

- Current metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:00000S`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000S`, blank `EMITTER_POSITION_OPTIONAL`, blank C++.
- Current owner route: [UID:00000S] `BackPane` class, emitted through [UID:0000HO] `BackPane` file at `NexusTK/map/BackPane.cpp`.
- Current target text already identifies the range as an exact BackPane constructor/non-deleting-destructor child before [UID:0002GX] `ApplicationSendShutdownMessage`.
- Current stale blocker: the target and support pages still say C++ remains blank because final declarations/member names/helper ownership are below an old `95/95` reconstruction-code gate. That is no longer a correct first-draft C++ reason for this target. Under the active B-agent standard, this target is reconstructable, has a valid owner/emitter chain, clears the source-quality score threshold after this pass, and has source-shaped behavior/naming support.

## MCP Evidence Checked

Live IDA MCP session:

- Session/database: `80de0a67`
- `server_health`: `status=ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- `idb_list`: one active worker session `80de0a67`.
- `survey_binary minimal`: module `NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`, `.text` `0x401000-0x60d000`, `.rdata` `0x60d670-0x66d000`, `.data` `0x66d000-0x69d000`.

Targeted MCP calls used:

- `lookup_funcs` for `0x00467820`, `0x00467830`, `0x004678ee`, `0x004678f0`, `0x0046795c`, `0x00467960`, `0x004679bf`, `0x004679c0`, `0x00467a50`, `0x00467a5b`, `0x00467a66`, `0x00467a80`, `0x00467b30`.
- `analyze_function` for `0x00467830`, `0x004678f0`, `0x00467960`, and `0x00467a80`.
- `callees` for `0x00467830`, `0x004678f0`, `0x00467960`, and `0x00467a80`.
- `xrefs_to` for the BackPane constructor/destructor/tail starts.
- `xref_query` for `g_pBackPane` `0x0067a740`, `g_pEPFLib` `0x0067a744`, `g_pChangeMan` `0x0067ab2c`, screen-dimension words `0x0066da94` and `0x0066da98`, BackPane vtable anchors `0x00612fc8`, `0x00613014`, `0x00613044`, and negative BackGroundPane controls `0x0067ab7c`, `0x00612f3c`, `0x00612f88`, `0x00612fb8`.
- `get_bytes` for code padding windows around `0x00467820`, `0x004678e0`, `0x00467950`, `0x004679b0`, `0x00467b20`, data/vtable bytes at `0x0067a740`, `0x00612fc8`, `0x00613014`, `0x00613044`, and wide resource strings at `0x0061e100`, `0x0061e114`, `0x0061304c`, `0x00610fd0`.
- `decompile` for `0x004f7d10` to verify both `InitializeMainUiGraph` constructor call sites and their resource operands.
- `int_convert` for size and offset conversions: `0xbe == 190`, `0x6c == 108`, `0xf8 == 248`, `0xa0 == 160`, `0xa4 == 164`, `0x120 == 288`, and `0x124 == 292`.

## Boundary And Function Evidence

`lookup_funcs` confirms the target consists of two modeled functions plus padding:

| Address/query | MCP result | Source-quality meaning |
| --- | --- | --- |
| `0x00467830` | `sub_467830`, size `0xbe` / 190 | BackPane constructor body, half-open `0x00467830-0x004678ee`. |
| `0x004678ee` | not a function | First post-constructor byte; padding follows. |
| `0x004678f0` | `sub_4678F0`, size `0x6c` / 108 | BackPane ordinary/non-deleting destructor body, half-open `0x004678f0-0x0046795c`. |
| `0x0046795c` | not a function | First post-destructor byte; padding follows. |
| `0x00467960` | `sub_467960`, size `0x5f` | Separate [UID:0002GX] Application message helper; not BackPane. |
| `0x004679bf` | not a function | End of Application helper. |
| `0x004679c0` | `sub_4679C0`, size `0x1d` | BackPane tail cluster resumes after the Application helper. |
| `0x00467b30` | `sub_467B30`, size `0x711` | Next owner island after [UID:00030N], confirming the later boundary. |

`get_bytes` confirms exact padding:

- Predecessor function `sub_4677D0` returns with `c2 04 00` at `0x0046782c-0x0046782e`; byte `0x0046782f` is `0xcc`; constructor prologue starts at `0x00467830`.
- Constructor returns with `c2 04 00` at `0x004678eb-0x004678ed`; bytes `0x004678ee-0x004678ef` are `0xcc 0xcc`; destructor prologue starts at `0x004678f0`.
- Non-deleting destructor returns at `0x0046795b`; bytes `0x0046795c-0x0046795f` are four `0xcc`; [UID:0002GX] prologue starts at `0x00467960`.
- [UID:0002GX] returns at `0x004679be`; byte `0x004679bf` is `0xcc`; [UID:00030N] `OnActivate` starts at `0x004679c0`.
- The tail cluster before `0x00467b30` ends with `c2 04 00`; bytes `0x00467b2d-0x00467b2f` are `0xcc cc cc`; `0x00467b30` begins the next `BalloonObjectPane` island.

The target boundary is therefore exact and implementation-ready. There is no range reason to keep the target at `85`.

## Body Evidence

### `0x00467830-0x004678ee` Constructor

MCP `analyze_function 0x00467830` decompiles the body as a `__thiscall` constructor-shaped method with one explicit `unsigned __int16 *ArgList` parameter, now best source-facing as `const wchar_t *frameResourceName`:

- Calls `sub_544460((char *)this, 0)` at `0x0046785c`, matching `Pane::Pane(0)` / base-pane construction.
- Computes the embedded tile context at `this + 0xf8` / 248.
- Publishes `g_pBackPane` at `0x00467878` as `this`; the decompiler-visible guard path clears `g_pBackPane` at `0x0046787f` when the adjusted member pointer would be null. That branch is recorded as a compiler/decompiler adjusted-member guard, not as evidence of a normal source-level null constructor call.
- Installs BackPane vtable views:
  - primary `0x00612fc8` at `0x0046788f`,
  - secondary `0x00613014` at `0x00467895`,
  - tertiary `0x00613044` at `0x0046789f`.
- Calls `sub_457A60(this + 0xf8)` at `0x004678a9`, matching `EPFTileContext::Initialize()`.
- Reads `g_screenWidth` / `word_66DA94` at `0x004678ae` and stores it at `this + 0x120` / 288 at `0x004678b6`.
- Reads `g_screenHeight` / `word_66DA98` at `0x004678bc` and stores it at `this + 0x124` / 292 at `0x004678c8`.
- Calls `sub_4D02F0(g_pEPFLib, frameResourceName, 0, this + 0xf8)` at `0x004678d4`, matching `ResourceLayoutTable::LookupLayoutEntry(frameResourceName, 0, &m_frameTileContext)`.
- Returns `this` in decompiler form; source C++ constructor has no explicit return.

Constructor direct callees:

- `0x00544460` `sub_544460`, documented as `Pane::Pane`, size `0x118`.
- `0x00457a60` `sub_457A60`, documented as `EPFTileContext::Initialize`, size `0x44`.
- `0x004d02f0` `sub_4D02F0`, documented as `ResourceLayoutTableLookupLayoutEntry`, size `0xae`.

Constructor callers:

- `xrefs_to 0x00467830` reports exactly two code xrefs: `0x004f7d7d` and `0x004f8573`, both inside `sub_4F7D10` / `InitializeMainUiGraph`.
- `decompile 0x004f7d10` confirms EPF/current branch allocates `296` bytes and calls `sub_467830(v2, &off_61E100)` at `0x004f7d82`; the same function then reads `g_pBackPane + 0x120/+0x124` for the root rectangle setup.
- The legacy branch allocates `296` bytes and calls `sub_467830(v38, &off_61E114)` at `0x004f8578`; it then uses the same root pane setup path with `word_66DA94` and `word_66DA98`.
- Resource literal bytes decode as UTF-16 `FRAME.EPF` at `0x0061e100` and `FRAME.EPD` at `0x0061e114`; xrefs are exactly `0x004f7d76` and `0x004f856c` from `InitializeMainUiGraph`.

### `0x004678f0-0x0046795c` Non-Deleting Destructor

MCP `analyze_function 0x004678f0` decompiles the destructor as:

- Reinstalls the same BackPane vtable views:
  - primary `0x00612fc8` at `0x00467915`,
  - secondary `0x00613014` at `0x0046791b`,
  - tertiary `0x00613044` at `0x00467925`.
- Reads `g_pChangeMan` / `0x0067ab2c` at `0x0046792f`.
- Calls `sub_47EEA0(g_pChangeMan, this)` at `0x00467936`, documented as `ChangeMan::UnregisterObject`.
- Clears `g_pBackPane` at `0x0046793d`.
- Calls `sub_544580(this)` at `0x00467947`, documented as `Pane::~Pane` ordinary teardown.

Destructor direct callees:

- `0x0047eea0` `sub_47EEA0`, documented as `ChangeManUnregisterObject`, size `0x3f`.
- `0x00544580` `sub_544580`, documented as `Pane::~Pane`, size `0x107`.

`xrefs_to 0x004678f0` reports zero direct xrefs. That is expected for an ordinary non-deleting destructor: callers reach it through compiler EH/destructor scheduling and deleting-destructor/vtable routes rather than a normal source call. This is not a no-route/source-authorship blocker because the paired scalar deleting destructor at `0x00467a80` duplicates the same body and the BackPane vtable family references the deleting-destructor slots.

### Relationship To [UID:00030N] Deleting Destructor

MCP `analyze_function 0x00467a80` confirms the scalar deleting destructor repeats the same source destructor sequence:

- Writes vtables at `0x00467aa5`, `0x00467aab`, and `0x00467ab5`.
- Calls `ChangeMan::UnregisterObject` at `0x00467acd`.
- Clears `g_pBackPane` at `0x00467ad4`.
- Calls `Pane::~Pane` at `0x00467ade`.
- Conditionally calls the free helper `0x004f4ac0` depending on delete flags.

This strengthens source readiness for the target destructor. The handwritten source method should be `BackPane::~BackPane()`, while MSVC regenerates the scalar deleting wrapper from the virtual destructor declaration.

## Data, Vtable, Resource, And Global Evidence

### `g_pBackPane`

`xref_query 0x0067a740` reports `106` total xrefs. The authoritative lifecycle refs around this target are:

- `0x00467878`: constructor publishes `this`.
- `0x0046787f`: constructor adjusted-member guard clear path.
- `0x0046793d`: non-deleting destructor clears the singleton.
- `0x00467a50`: singleton clear thunk in [UID:00030N].
- `0x00467ad4`: scalar deleting destructor clears the singleton.
- `0x004f7d88`: `InitializeMainUiGraph` consumes the just-constructed root BackPane in the current/EPF branch.
- `0x00504a74` and `0x00504a83`: `sub_5047F0` / Application-side caller context reads the root pane around the [UID:0002GX] call site; this is consumer evidence, not BackPane ownership for [UID:0002GX].

`get_bytes 0x0067a740 size 16` returns sixteen zero bytes, confirming zero-initialized `.data` storage for the BackPane/ImageLib/global window around this slot.

### BackPane Vtables

BackPane vtable anchors are exact and owner-local:

- `0x00612fc8`: three xrefs, from constructor `0x0046788f`, non-deleting destructor `0x00467915`, and scalar deleting destructor `0x00467aa5`.
- `0x00613014`: three xrefs, from constructor `0x00467895`, non-deleting destructor `0x0046791b`, and scalar deleting destructor `0x00467aab`.
- `0x00613044`: three xrefs, from constructor `0x0046789f`, non-deleting destructor `0x00467925`, and scalar deleting destructor `0x00467ab5`.

`get_bytes` confirms the vtable slot starts:

- `0x00612fc8`: begins with pointer `0x00467a80`, the BackPane scalar deleting destructor.
- `0x00613014`: begins with pointer `0x00467a5b`, an adjustor thunk, then `0x004679c0` `OnActivate`.
- `0x00613044`: begins with pointer `0x00467a66`, an adjustor thunk; nearby bytes continue into wide `FRAME.PAL` data after this short secondary table.

### Resource And Layout Dependencies

- `g_pEPFLib` / `0x0067a744` has `231` total xrefs; the target constructor's relevant read is `0x004678ce`.
- `sub_4D02F0` is [UID:0002KP] `ResourceLayoutTableLookupLayoutEntry`: exact `0x004d02f0-0x004d039e`, broad central layout lookup, not BackPane-owned.
- `EPFTileContext::Initialize` is `0x00457a60-0x00457aa4`, a shared render-support initializer under [UID:00004I].
- `g_screenWidth` / `0x0066da94` has `98` total xrefs; the target read is `0x004678ae`.
- `g_screenHeight` / `0x0066da98` has `96` total xrefs; the target read is `0x004678bc`.
- The screen-dimension globals are Application-owned default display-dimension globals; BackPane consumes them and caches them at local fields `+0x120/+0x124`.

### ChangeMan Dependency

`g_pChangeMan` / `0x0067ab2c` has `11` total xrefs. BackPane-specific reads are:

- `0x0046792f` in the non-deleting destructor.
- `0x00467abf` in the scalar deleting destructor.

`sub_47EEA0` is [UID:000100] `ChangeManUnregisterObject`. The target consumes `ChangeMan` during teardown but does not own `ChangeMan`, its singleton, or message-router methods.

## Positive Evidence

- Exact source-owned function bodies with modeled IDA starts and tight `0xcc` padding before/after.
- Constructor has exactly two direct callers, both from `InitializeMainUiGraph`, matching current/EPF and legacy root-pane creation branches.
- The constructor argument is the root background frame resource name, with MCP-proven `FRAME.EPF` and `FRAME.EPD` operands from the two branches.
- Constructor writes only BackPane vtables, not BackGroundPane vtables.
- Constructor publishes `g_pBackPane`, initializes embedded `EPFTileContext`, caches display dimensions, and performs central resource-layout lookup into the tile context.
- Non-deleting destructor repeats the ordinary BackPane teardown sequence also present in the scalar deleting destructor: vtable reset, `ChangeMan::UnregisterObject`, `g_pBackPane` clear, base `Pane` teardown.
- Vtable and singleton xrefs prove class-local lifecycle ownership rather than feature/caller ownership.
- Successor [UID:0002GX] has separate function start, separate caller (`0x00504a7e` from `sub_5047F0`), Application `ForwardMessage` callee, and stack message literal `0x676f6f67`; it is not part of BackPane source.

## Negative Evidence And Rejected Alternatives

1. `BackPane` class ownership - accepted.
   - Direct evidence: BackPane vtable triad, `g_pBackPane` lifecycle, constructor/destructor behavior, and source file route through [UID:0000HO].

2. `BackGroundPane` ownership - rejected.
   - MCP control check: `g_pBackGroundPane` / `0x0067ab7c` has six xrefs, all in `0x00467510`, `0x004675b0`, `0x004675e0`, `0x004677a0`, and `0x004677d0`.
   - BackGroundPane vtables `0x00612f3c`, `0x00612f88`, and `0x00612fb8` each have three xrefs confined to the `0x00467510-0x0046782f` sibling child.
   - This target does not touch `g_pBackGroundPane` or BackGroundPane vtables.

3. `ApplicationLifecycle` / Application ownership - rejected for this target.
   - `0x00467960` is the nearby Application-owned [UID:0002GX] helper, but it starts after four `0xcc` bytes at `0x00467960`.
   - The target constructor/destructor use BackPane vtables and `g_pBackPane`; [UID:0002GX] constructs/dispatches a stack message through `Application::ForwardMessage`.

4. `InitializeMainUiGraph` ownership - rejected.
   - It is the allocator/caller for both constructor branches and chooses the frame resource operand, but the callee body is a BackPane constructor publishing the BackPane singleton and installing BackPane vtables.
   - Caller-specific resource selection should be documented as constructor call-site evidence, not as ownership transfer.

5. Shared tile/image/resource helpers - rejected.
   - `EPFTileContext::Initialize`, `g_pEPFLib`, and `ResourceLayoutTableLookupLayoutEntry` are central render/resource dependencies with broad fan-in. The target consumes them for its frame context but does not own their declarations or implementations.

6. `ChangeMan` ownership - rejected.
   - The target destructor calls `ChangeMan::UnregisterObject` through `g_pChangeMan`; `ChangeMan` owns the singleton and router methods. BackPane is only a listener/user being removed during teardown.

7. Parent aggregate [UID:0000YY] ownership - rejected as a direct owner/emitter.
   - The parent is a non-emitting mixed index over BackGroundPane, BackPane, and the cross-owned Application helper. The exact target child has the direct class owner and should remain the emitting item.

8. No-owner / non-emitting - rejected.
   - The constructor/destructor are normal source-authored class methods. The only compiler material is vtable stores, EH scaffolding, padding, and the separate scalar deleting wrapper. Source C++ can represent the behavior with a constructor and ordinary destructor.

## Heuristic And Inference Reanalysis

The old blocker was not an evidence blocker; it was stale threshold wording. Current evidence supports a first-draft source reconstruction because:

- The target is not a mixed aggregate after the split. It contains exactly one source constructor and one ordinary destructor, plus padding between them and adjacent functions.
- The direct class owner and source file route are already documented and remain supported by current MCP.
- The dependency names are no longer just `sub_` placeholders: current docs and MCP map them to `Pane::Pane`, `EPFTileContext::Initialize`, `ResourceLayoutTable::LookupLayoutEntry`, `g_pEPFLib`, `g_screenWidth`, `g_screenHeight`, `ChangeMan::UnregisterObject`, and `Pane::~Pane`.
- Member names `m_frameTileContext`, `m_frameWidth`, and `m_frameHeight` are inferred source-facing names from role and layout. Exact original spellings remain caveats, but they no longer block first-draft C++ because the field roles are directly proven and the names are realistic human C++ names for this module.
- The adjusted-member null/clear path at `0x00467870/0x0046787f` is retained as a documented compiler/decompiler shape. The implementation-ready first draft can preserve it with a local `EPFTileContext *frameContext` guard while still presenting normal source-level constructor behavior.
- The destructor should be source-authored as `BackPane::~BackPane()`. Vtable writes, EH data, base destructor invocation, and scalar deleting wrapper code are compiler output from that source declaration and do not need handwritten code.

## Ranked Ownership And Source Placement

| Rank | Candidate | Decision | Evidence |
| ---: | --- | --- | --- |
| 1 | [UID:00000S] `BackPane` class, through [UID:0000HO] `BackPane.cpp` | Keep | Direct vtables, `g_pBackPane`, constructor/destructor lifecycle, `InitializeMainUiGraph` root-pane callers, and source file pages align. |
| 2 | [UID:0000HO] `BackPane.cpp` file root | Keep as source root, not direct child owner | File owns the BackPane/BackGroundPane module, but direct method ownership should stay on the class. |
| 3 | [UID:0000YY] split parent/index | Reject as emitter | Mixed non-emitting index containing BackGroundPane, BackPane, and [UID:0002GX]. |
| 4 | [UID:00000R] `BackGroundPane` | Reject | Separate singleton/vtable family confined to predecessor child. |
| 5 | [UID:00000D] `Application` / lifecycle | Reject | Only the successor helper at `0x00467960` is Application-owned. |
| 6 | `InitializeMainUiGraph` | Reject | Caller/allocator and resource selector only. |
| 7 | `EPFTileContext`, `ImageLib`, `ResourceLayoutTable`, `ChangeMan`, screen-dimension globals | Reject as target owners | Dependencies consumed by BackPane, not method owners. |
| 8 | no-owner/non-emitting | Reject | Source-authored constructor/destructor with valid owner/emitter route. |

## Score And Metadata Recommendation

Target [UID:00030M]:

- Change `COMPLETION` from `85` to `88`.
- Change `CONFIDENCE` from `88` to `91`.
- Keep `CANONICAL_OWNER:00000S`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:00000S`.
- Keep blank `EMITTER_POSITION_OPTIONAL`.
- Add first-draft C++.

Rationale:

- Completion rises because this pass resolves the stale code-gate blocker, validates exact boundaries/padding, decompiles both target bodies, proves the two constructor callers and resource operands, maps every target-local dependency to current source-facing names, and rejects plausible alternate owners with MCP evidence.
- Confidence rises because MCP session `80de0a67` supplies live function, decompile, xref, byte, vtable, resource, and negative-control evidence. It remains below final-audit range because exact original member spellings (`m_frameTileContext`, `m_frameWidth`, `m_frameHeight`), the precise constructor parameter spelling, and the public type of `g_pEPFLib` remain inferred source-facing names rather than recovered source symbols.

No support-doc metadata change is required in this report. Support docs should be synchronized for stale wording and current evidence, but their broader class/file scores include other unresolved BackPane-family items and should not be raised solely from this target.

## First-Draft C++ Recommendation

Add first-draft C++ to [UID:00030M]. This target is source-ready.

```cpp
BackPane::BackPane(const wchar_t* frameResourceName)
    : Pane(0)
{
    EPFTileContext* frameContext = &m_frameTileContext;

    g_pBackPane = frameContext != NULL ? this : NULL;

    frameContext->Initialize();
    m_frameWidth = g_screenWidth;
    m_frameHeight = g_screenHeight;
    g_pEPFLib->LookupLayoutEntry(frameResourceName, 0, frameContext);
}

BackPane::~BackPane()
{
    g_pChangeMan->UnregisterObject(this);
    g_pBackPane = NULL;
}
```

Implementation notes for the target doc:

- The local `frameContext != NULL ? this : NULL` line preserves the observed adjusted-member publish/clear shape at `0x00467870-0x0046787f`. In ordinary C++ construction that guard is not expected to be false, but recording it in the draft keeps the source behavior close to the binary without introducing IDA labels.
- `Pane(0)` is the current best source-facing base-constructor shape. The final named pane mode enum/constant is not proven here.
- `frameResourceName` is inferred from `FRAME.EPF` / `FRAME.EPD` call-site operands.
- `m_frameTileContext`, `m_frameWidth`, and `m_frameHeight` are inferred member names from direct field behavior and current project vocabulary.
- `g_pEPFLib->LookupLayoutEntry(...)` follows current [UID:0002KP] / [UID:0000QU] vocabulary. The final public type may be `ImageLib`, `ResourceLayoutTable`, or a ResourceLayout facet, but the call behavior and source-facing role are sufficient for first draft.
- Vtable resets, EH scaffolding, `Pane::~Pane` chaining, and scalar deleting destructor behavior should be documented as compiler-generated effects from the constructor/destructor declarations, not handwritten C++ lines.

## Recommended Target And Support Doc Changes

### Required If Accepted

1. `by-memory/0x00467830-0x0046795c.BackPaneConstructionAndDestruction.md`
   - Set metadata to `88/91`, owner/emitter unchanged.
   - Replace old `95/95` C++ gate wording with the current source-quality rationale.
   - Add current MCP session `80de0a67`, PE SHA-256, exact function sizes, exact padding, decompilation/callee/caller evidence, vtable anchors, `g_pBackPane` lifecycle refs, `g_pEPFLib`/ResourceLayout lookup, `g_screenWidth`/`g_screenHeight` copies, `g_pChangeMan` unregister, successor separation, owner ranking/rejections, caveats, and first-draft C++.

2. `by-class/BackPane.md`
   - Update method notes for [UID:00030M] to include current MCP session `80de0a67`, constructor signature direction `BackPane::BackPane(const wchar_t *frameResourceName)`, ordinary destructor direction `BackPane::~BackPane()`, and first-draft readiness.
   - Replace stale `95/95` blank-C++ wording for this target with the accepted target-specific decision.
   - Preserve broader class caveats for help helpers and other BackPane family items.

3. `by-file/BackPane.md`
   - Add a concise but specific support note that [UID:00030M] now carries first-draft constructor/destructor C++ through [UID:00000S], with `FRAME.EPF`/`FRAME.EPD` caller operands, `g_pBackPane` lifecycle, embedded `EPFTileContext`, screen-dimension cache fields, and `ChangeMan` unregister.
   - Preserve the source root as `NexusTK/map/BackPane.cpp`.
   - Keep product callers and shared render/resource helpers as dependencies, not owners.

4. `by-memory/0x00467510-0x00467b2d.BackPaneAndBackGroundPane.md`
   - Update the [UID:00030M] row/note with new `88/91`, first-draft-ready status, current MCP evidence, exact padding, and the [UID:0002GX] separation.
   - Keep the parent aggregate non-emitting and mixed-owner.

5. `by-memory/0x0067a740-0x0067a744.g_pBackPane.md`
   - Add current `80de0a67` evidence for constructor publish/guard clear and non-deleting destructor clear from [UID:00030M].
   - Replace stale `95/95` wording as it applies to this target's constructor/destructor use. The global declaration can still remain blank because no dedicated by-global declaration/type decision is being made here.
   - Preserve exact `106` total xref context and broad consumer caveats.

6. `by-memory/0x00467960-0x004679bf.ApplicationSendShutdownMessage.md`
   - If touched, keep ownership unchanged and add only the boundary note that [UID:00030M] ends at `0x0046795c`, `0x0046795c-0x00467960` is padding, and this helper remains Application-owned.
   - No metadata/C++ change recommended for [UID:0002GX] from this report.

7. `by-memory/0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor.md`
   - If touched, add the current relationship note: its scalar deleting destructor duplicates the same `BackPane::~BackPane()` body from [UID:00030M] plus optional free, so [UID:00030M] is first-draft-ready and [UID:00030N] remains a separate tail-cluster source-quality item.
   - Do not add [UID:00030N] C++ in this implementation unless supervisor explicitly broadens scope.

8. `by-memory/0x00612f3c-0x006131b4.BackGroundBalloonBlackHoleReadOnlyData.md`
   - If stale or too terse, add current vtable anchor evidence for BackPane primary/secondary anchors and negative BackGroundPane control refs.
   - Keep the `.rdata` aggregate non-emitting mixed data.

9. `by-resource/backpane-background-resources.md`
   - Already contains same-or-greater detail for `FRAME.EPF`, `FRAME.EPD`, `FRAME.PAL`, and `NPAL5.PAL` routes. Implementation can mark it already sufficient unless a local stale contradiction appears.

### Not Recommended In This Callback

- Do not edit `by-file/Application.md`, `by-class/Application.md`, or ApplicationLifecycle pages for this target except if a direct stale contradiction says [UID:00030M] owns [UID:0002GX]. Current [UID:0002GX] docs are already strong.
- Do not edit EPFTileContext, ImageLib, ResourceLayoutTable, ChangeMan, or screen-dimension globals unless a direct stale contradiction appears. Their current pages already supply source-facing dependency names at sufficient detail for this target.
- Do not create new child pages. The target is already an exact constructor/non-deleting-destructor child.

## Expected Validators After Implementation

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` for every changed by-* file:

> Executable block R001 was removed from this report and preserved verbatim in [00030M-BackPaneConstructionAndDestruction-source-quality-removed.md](00030M-BackPaneConstructionAndDestruction-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If changed, also validate:

> Executable block R002 was removed from this report and preserved verbatim in [00030M-BackPaneConstructionAndDestruction-source-quality-removed.md](00030M-BackPaneConstructionAndDestruction-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Supervisor-Owned Coverage Text

Do not edit `by-memory/-coverage-report.md` as B005. If supervisor accepts this report, replace the current [UID:00030M] row with:

```text
        - [UID:00030M][0x00467830-0x0046795c.BackPaneConstructionAndDestruction](by-memory/0x00467830-0x0046795c.BackPaneConstructionAndDestruction.md) 0x00467830-0x0046795c | class-method-cluster | BackPaneConstructionAndDestruction : reconstructable : 88% : very strong : B005 2026-06-23 MCP source-quality pass recommends first-draft C++ for `BackPane::BackPane(const wchar_t*)` and `BackPane::~BackPane`; confirms session `80de0a67`, PE SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`, exact constructor `0x00467830-0x004678ee`, non-deleting destructor `0x004678f0-0x0046795c`, two `InitializeMainUiGraph` callers with `FRAME.EPF`/`FRAME.EPD` operands, BackPane vtable stores at `0x00612fc8`/`0x00613014`/`0x00613044`, `g_pBackPane` publish/clear refs, `EPFTileContext::Initialize`, `g_screenWidth`/`g_screenHeight` copies, `g_pEPFLib` ResourceLayout lookup, `ChangeMan::UnregisterObject` teardown, padding before [UID:0002GX], and rejected BackGroundPane/Application/ChangeMan/resource-helper ownership.
```

No by-class or by-file coverage row change is required unless the supervisor chooses to update those broader rows for support wording later.

## Open Caveats With Score/C++ Impact

- Original constructor parameter spelling is not recovered. `frameResourceName` is the best source-facing name because the two call-site operands are `FRAME.EPF` and `FRAME.EPD`. This does not block first-draft C++.
- `m_frameTileContext`, `m_frameWidth`, and `m_frameHeight` are inferred member names. Their offsets and roles are directly proven; exact spellings are not. This caps confidence below final-audit range but does not block C++.
- `g_pEPFLib` final public type remains open between `ImageLib*`, `ResourceLayoutTable*`, or a ResourceLayout facet. Current source vocabulary supports `g_pEPFLib->LookupLayoutEntry(...)` as a draft call and the dependency pages keep the type caveat.
- The constructor's adjusted-member guard clear path is unusual in source form. The draft preserves it with a local `frameContext` guard so the report does not silently drop the observed `0x0046787f` clear.
- [UID:00030N] contains different methods (`OnActivate`, `OnPaint`, clear thunk, adjustor thunks, and scalar deleting destructor). It should stay unchanged unless the supervisor explicitly scopes that sibling page. It does not block [UID:00030M] because the current target's constructor and ordinary destructor are already exact and source-shaped.

## Implementation Tracking Checklist

- [x] Update `by-memory/0x00467830-0x0046795c.BackPaneConstructionAndDestruction.md` metadata from `85/88` to `88/91`, owner/emitter unchanged, blank emitter position unchanged.
  - Proof: target metadata now reads `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00000S`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000S`, blank `EMITTER_POSITION_OPTIONAL`.

- [x] Add first-draft C++ for `BackPane::BackPane(const wchar_t* frameResourceName)` and `BackPane::~BackPane()` to [UID:00030M].
  - Proof: target `RECONSTRUCTION_CPP` block now contains the accepted constructor/destructor draft with `Pane(0)`, `EPFTileContext* frameContext = &m_frameTileContext`, `g_pBackPane = frameContext != NULL ? this : NULL`, `frameContext->Initialize()`, `m_frameWidth = g_screenWidth`, `m_frameHeight = g_screenHeight`, `g_pEPFLib->LookupLayoutEntry(frameResourceName, 0, frameContext)`, `g_pChangeMan->UnregisterObject(this)`, and `g_pBackPane = NULL`.

- [x] In [UID:00030M], replace stale `95/95` code-gate wording with current MCP-backed source-quality rationale.
  - Proof: target `Assignment Gate`, `Source Reconstruction Notes`, `Ownership And Rejected Routes`, and `Score Rationale` sections now explain the active first-draft C++ gate, target-specific readiness, remaining spelling/type caveats, and why the old blank-C++ language is superseded.

- [x] In [UID:00030M], add MCP session `80de0a67`, PE SHA-256, function sizes, exact padding, constructor/destructor decompilation behavior, callees, two constructor callers, `FRAME.EPF`/`FRAME.EPD` operands, vtable anchors, `g_pBackPane` lifecycle, `g_pEPFLib` lookup, screen-dimension copies, `ChangeMan::UnregisterObject`, successor separation, rejected alternatives, score rationale, and caveats.
  - Proof: target sections `Scope`, `Covered Ranges`, `Current IDA MCP Evidence`, `Constructor Body Evidence`, `Destructor Body Evidence`, `Data, Vtable, Resource, And Global Evidence`, `Successor And Boundary Separation`, `Ownership And Rejected Routes`, `Score Rationale`, and `Changes` now carry these facts at report-level detail.

- [x] Update `by-class/BackPane.md` with [UID:00030M] first-draft readiness, current evidence, and target-specific stale gate replacement.
  - Proof: method notes now use `BackPane::BackPane(const wchar_t *frameResourceName)` and `BackPane::~BackPane()`; data notes now include `m_frameTileContext`, `m_frameWidth`, `m_frameHeight`, and the lifecycle refs; evidence/changes record MCP session `80de0a67`, PE SHA-256, exact sizes/padding, callers/resources, vtable anchors, `g_pEPFLib`, `ChangeMan`, and target-specific stale-gate replacement.

- [x] Update `by-file/BackPane.md` with [UID:00030M] constructor/destructor support detail, resource operands, source route, and dependency/owner boundaries.
  - Proof: proposed contents and evidence notes now state [UID:00030M] emits first-draft constructor/destructor C++ through `BackPane.cpp`, records `FRAME.EPF`/`FRAME.EPD`, `g_pBackPane`, embedded `EPFTileContext`, screen-dimension fields, `g_pEPFLib`, `ChangeMan`, and scalar deleting destructor duplication, while keeping [UID:0002GX] and shared helpers as non-owners.

- [x] Update `by-memory/0x00467510-0x00467b2d.BackPaneAndBackGroundPane.md` with [UID:00030M] `88/91`, first-draft-ready status, exact range/padding, and continued mixed-index/no-emission status.
  - Proof: covered-range row now records [UID:00030M] `88/91` and first-draft constructor/destructor readiness; IDA MCP evidence and change log record current session `80de0a67`, sizes, padding, callers, operands, vtables, singleton lifecycle, dependency calls, and continued non-emitting mixed-index status.

- [x] Update `by-memory/0x0067a740-0x0067a744.g_pBackPane.md` with current `80de0a67` BackPane publish/clear evidence and target-specific gate correction while keeping global declaration policy unchanged.
  - Proof: evidence, reconstruction notes, and change log now record [UID:00030M] publish/guard-clear/destructor-clear refs, [UID:00030N] clear/deleting refs, target C++ readiness, and the storage-page reason for retaining a blank standalone declaration.

- [x] Check `by-memory/0x00467960-0x004679bf.ApplicationSendShutdownMessage.md`; update only if it lacks the current boundary separation at same-or-greater detail.
  - Proof: reread showed same-or-greater boundary separation already present: the page documents exact `0x00467960-0x004679bf`, exclusive end `0x004679bf`, next BackPane function at `0x004679c0`, caller `0x00504a7e`, Application owner, `0x676f6f67` message, and mixed-index placement. No edit needed.

- [x] Check `by-memory/0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor.md`; update only if it lacks the scalar-deleting-destructor duplicate-body relationship at same-or-greater detail.
  - Proof: file was updated because it lacked the explicit relationship. Covered ranges, IDA evidence, Assignment Gate, and Changes now record that scalar deleting destructor `0x00467a80` duplicates the ordinary [UID:00030M] destructor body plus optional free, and that [UID:00030M] now carries the handwritten destructor source.

- [x] Check `by-memory/0x00612f3c-0x006131b4.BackGroundBalloonBlackHoleReadOnlyData.md`; update only if it lacks the current BackPane/BackGroundPane vtable anchor split at same-or-greater detail.
  - Proof: reread showed same-or-greater detail already present: `0x00612f3c`/`0x00612f88`/`0x00612fb8` BackGroundPane anchors and `0x00612fc8`/`0x00613014`/`0x00613044` BackPane anchors, with constructor/destructor xref counts and ownership split. No edit needed.

- [x] Mark `by-resource/backpane-background-resources.md` already sufficient unless implementation reread finds stale contradictions.
  - Proof: reread found no stale contradiction. It already records `FRAME.EPF`, `FRAME.EPD`, `FRAME.PAL`, `NPAL5.PAL`, constructor resource branch, paint palette branch, IDA xrefs, packaging boundaries, and BackPane source/resource contract at same-or-greater detail.

- [x] Do not edit any `-coverage-report.md` file; leave the replacement row above for supervisor-owned application.
  - Proof: no manual `-coverage-report.md` edits were made. The exact supervisor-owned replacement row remains in `Supervisor-Owned Coverage Text`. Validator-owned generated report updates are listed below as side effects, not manual coverage edits.

- [x] Lease and release/expire edit locks under B005 rules.
  - Proof: leased six immediate edit files successfully with `python leaser.py B005 lease ...`: target, `by-class/BackPane.md`, `by-file/BackPane.md`, aggregate, `g_pBackPane`, and [UID:00030N] tail page. After validators, `python leaser.py B005 unlease ...` returned `Rejected[No active lease]` for each because the leases had already expired; `tools/leaser/Agents/current_leases.md` then showed no active B005 leases, only unrelated B002 Browser leases.

- [x] Run scoped validator for every changed by-* doc and record command, exit code, ok count, warnings, and generated side effects.
  - Proof:
    - `python .\tools\validator.py --mode file --file by-memory\0x00467830-0x0046795c.BackPaneConstructionAndDestruction.md --apply --queue-timeout 240` -> exit code `0`, `ok: 1`. Side effects: `completion_update 00030M 88`, `confidence_update 00030M 91`, UID link/reference index inserts, `autogen_cpp_update` for validator-owned `auto-generated/NexusTK/map/BackPane.cpp`, `autogen_report_update` for validator-owned `auto-generated/-ag-memory-coverage.md`, `projected_stats_update`, `autogen_registry_rebuild`, `validator.ini` registry updates, `tools/validator_autogen_backup/20260623-161331` backup, and known unrelated warnings `autogen_registry_stale` for missing `0003E6`/`00026U`.
    - `python .\tools\validator.py --mode file --file by-class\BackPane.md --apply --queue-timeout 240` -> exit code `0`, `ok: 1`. Side effects: UID link inserts, `stats_row_update` for `00000S`, `projected_stats_update`, `autogen_registry_rebuild`; known unrelated warnings include `autogen_registry_stale 0003E6/00026U`, `autogen_children_marker_missing`, and `autogen_cpp_conflict` counts from global validator state.
    - `python .\tools\validator.py --mode file --file by-file\BackPane.md --apply --queue-timeout 240` -> exit code `0`, `ok: 1`. Side effects: UID link inserts, `projected_stats_update`, `autogen_registry_rebuild`; file not present in generated stats lists. Same unrelated global validator warnings remained.
    - `python .\tools\validator.py --mode file --file by-memory\0x00467510-0x00467b2d.BackPaneAndBackGroundPane.md --apply --queue-timeout 240` -> exit code `0`, `ok: 1`. Side effects: UID link inserts, `projected_stats_update`, `autogen_registry_rebuild`; aggregate not present in generated stats lists. Same unrelated global validator warnings remained.
    - `python .\tools\validator.py --mode file --file by-memory\0x0067a740-0x0067a744.g_pBackPane.md --apply --queue-timeout 240` -> exit code `0`, `ok: 1`. Side effects: UID link inserts, `reference_index_add` for `00030M`/`00030N`, `projected_stats_update`, `autogen_registry_rebuild`; file not present in generated stats lists. Same unrelated global validator warnings remained.
    - `python .\tools\validator.py --mode file --file by-memory\0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor.md --apply --queue-timeout 240` -> exit code `0`, `ok: 1`. Side effects: UID link inserts, `reference_index_add 00030M`, `stats_row_update 00030N`, `projected_stats_update`, `autogen_registry_rebuild`. Same unrelated global validator warnings remained.

- [x] After implementation callback only, update this checklist with checked items and proof paths/sections/validator results.
  - Proof: this checklist was updated after edits, validators, and lease expiry verification.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/00030M-BackPaneConstructionAndDestruction-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:17","uid":"00030M"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00030M-BackPaneConstructionAndDestruction-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/00030M-BackPaneConstructionAndDestruction-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00030M"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
