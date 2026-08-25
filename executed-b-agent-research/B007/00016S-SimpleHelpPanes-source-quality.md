** TARGET-REPORT-UID:00016S **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B007 Report - [UID:00016S] SimpleHelpPanes Source Quality

Assignment id: `B007-report-00016S-SimpleHelpPanes-source-quality-20260627`

## Current Target State

- Target: [UID:00016S] `by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md`
- Current source header: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000JU`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JU`, blank formal `RECONSTRUCTION_CPP`.
- Current generated/tracker state is stale or not refreshed relative to the source header: `auto-generated/-ag-research-tracker.md` still lists this row under `## by-memory` / `### Not-Covered Files - Reconstructable` as `80/86`, and generated `auto-generated/NexusTK/ui/controls/HelpPanes.cpp` still shows an empty emitter marker for UID `00016S` with stale `80/86` metadata.
- Current owner route is correct: [UID:0000JU] `by-file/HelpPanes.md`.
- Current problem is not ownership. The problem is that this by-memory page is a broad method cluster over two classes (`SimpleHelpPane` and `SimpleHelpPane2`) plus internal padding. Inserting one aggregate C++ block here would conflate exact class methods and conflict with the split-index pattern already used for neighboring HelpPaneCore and ItemHelpPaneCore.

## MCP Health And Session Provenance

- Prior session `80de0a67` was invalidated by the MCP restart and is not used as live evidence here.
- Live MCP verification used current session `398b87c1`.
- `idb_list` returned one active worker session:
  - `session_id:398b87c1`
  - `input_path:E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
  - `filename:NexusTK.exe.i64`
  - `is_active:true`
  - `owned:true`
  - `adopted:true`
  - `pid:2704`
  - `worker_pid:2704`
- `server_health` for `398b87c1` returned `status:ok`, `module:NexusTK.exe`, `imagebase:0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and `strings_cache_size:2067`.

## Actual Evidence Checked

Documentation and generated state checked:

- Target `by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md`.
- Support docs: `by-file/HelpPanes.md`, `by-class/SimpleHelpPane.md`, `by-class/SimpleHelpPane2.md`, `by-class/HelpPane.md`, `by-memory/0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate.md`, `by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md`, `by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md`, `by-memory/0x0069ae00-0x0069ae04.g_pSimpleHelpPane.md`, and `by-memory/0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2.md`.
- Pattern docs checked for correct split handling: `by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md`, `by-memory/0x004c82d0-0x004ce160.ItemHelpPaneCore.md`, `by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md`, and `by-memory/0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes.md`.
- Generated state checked: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/-ag-memory-coverage.md`, and `auto-generated/NexusTK/ui/controls/HelpPanes.cpp`.
- Existing executed reports checked for direct/relevant context: B009 `00016T-SimpleHelpPane2Factory-source-quality.md`, B009 `00022O` implementation as incorporated into docs, B012 `00022N-HelpPaneFadeStateUpdate-source-quality.md`, B003 `00016W-help-tooltip-destructor-thunks-source-quality.md`, and B001 `000228-help-pane-singleton-close-source-quality.md`.

Live MCP tools used on session `398b87c1`:

- `lookup_funcs` for `0x004c6f90`, `0x004c7290`, `0x004c7310`, `0x004c7440`, `0x004c7450`, `0x004c74a0`, `0x004c74b0`, `0x004c75e0`, `0x004c7610`, `0x004c7620`, `0x004c7670`, and successor `0x004c7680`.
- `xrefs_to` for `0x004c6f90`, `0x004c74b0`, `0x004c75e0`, `0x004c7610`, `0x004c7620`, `0x004c7670`, `0x004c7680`, `0x0069ae00`, and `0x0067a7d4`.
- `decompile` for `0x004c6f90`, `0x004c7290`, `0x004c7310`, `0x004c7440`, `0x004c7450`, `0x004c74a0`, `0x004c74b0`, `0x004c75e0`, `0x004c7610`, `0x004c7620`, and `0x004c7670`.
- `get_bytes` for internal padding/end-boundary checks at `0x004c7287`, `0x004c7307`, `0x004c743e`, `0x004c7491`, `0x004c75d5`, `0x004c7609`, `0x004c7668`, and `0x004c767d`.
- `lookup_funcs` / `callees` for key dependencies: `0x00544690`, `0x005975e0`, `0x004b7e80`, `0x004b7e10`, `0x005447c0`, `0x00544b80`, `0x004b7c30`, `0x004ba9a0`, `0x004baaa0`, `0x004bab70`, `0x004b9600`, `0x004b9660`, and `0x004b9680`.

One `get_bytes` request was first issued using an obsolete singular `addr`/`size` shape and returned `Invalid params: missing required parameters: ['regions']`. The corrected `regions` request succeeded and is the evidence used below.

## Live Method And Range Map

| Range | Current source-facing method | Live MCP result | Recommended disposition |
| --- | --- | --- | --- |
| `0x004c6f90-0x004c7287` | `SimpleHelpPane::SimpleHelpPane` | `lookup_funcs` `sub_4C6F90`, size `0x2f7`; `xrefs_to` reports 18 direct constructor call sites. | Split to exact child page; direct owner/emitter [UID:0000D6]. |
| `0x004c7287-0x004c7290` | padding | `get_bytes` nine `0xcc`. | Register/keep ignored padding, not target C++. |
| `0x004c7290-0x004c7307` | `SimpleHelpPane::~SimpleHelpPane` | `lookup_funcs` `sub_4C7290`, size `0x77`; decompile frees `this[62]` copied text and clears `g_pSimpleHelpPane`. | Split to exact child page; direct owner/emitter [UID:0000D6]. |
| `0x004c7307-0x004c7310` | padding | `get_bytes` nine `0xcc`. | Register/keep ignored padding. |
| `0x004c7310-0x004c743e` | `SimpleHelpPane::OnPaintFrame` | `lookup_funcs` `sub_4C7310`, size `0x12e`; decompile draws frame/background/text and walks copied wide text lines. | Split to exact child page; direct owner/emitter [UID:0000D6]. |
| `0x004c743e-0x004c7440` | padding | `get_bytes` starts with two `0xcc` before next handler. | Register/keep ignored padding. |
| `0x004c7440-0x004c7450` | `SimpleHelpPane::OnMouseDown` / close-on-mouse handler | `lookup_funcs` `sub_4C7440`, size `0x10`; decompile calls close/dismiss helper `0x00544690` on adjusted `this` and returns `0`. | Split to exact child page; direct owner/emitter [UID:0000D6]. |
| `0x004c7450-0x004c7491` | `SimpleHelpPane::OnTimerEvent` | `lookup_funcs` `sub_4C7450`, size `0x41`; decompile reads event byte at `event+4`, cancels timer through `0x005975e0` on event types `0`, `1`, and `4`, and returns handled only for `1`/`4`. | Split to exact child page; direct owner/emitter [UID:0000D6]. |
| `0x004c7491-0x004c74a0` | padding | `get_bytes` fifteen `0xcc` before key handler. | Register/keep ignored padding. |
| `0x004c74a0-0x004c74b0` | `SimpleHelpPane::OnKeyPress` / close-on-key handler | `lookup_funcs` `sub_4C74A0`, size `0x10`; decompile calls `0x00544690` on adjusted `this` and returns `0`. | Split to exact child page; direct owner/emitter [UID:0000D6]. |
| `0x004c74b0-0x004c75d5` | `SimpleHelpPane2::SimpleHelpPane2` | `lookup_funcs` `sub_4C74B0`, size `0x125`; decompile calls `HelpPane::HelpPane`, publishes `g_pSimpleHelpPane2`, installs three vtables, stores/clears anchor rect at `+0x224`, and schedules timer. | Split to exact child page; direct owner/emitter [UID:0000D7]. |
| `0x004c75d5-0x004c75e0` | padding | `get_bytes` eleven `0xcc`. | Register/keep ignored padding. |
| `0x004c75e0-0x004c7609` | `SimpleHelpPane2::~SimpleHelpPane2` | `lookup_funcs` `sub_4C75E0`, size `0x29`; `xrefs_to` no direct refs; singleton xrefs show clear at `0x004c75fa`; target docs already record vtable rewrite and tail jump to `HelpPane` teardown. | Split to exact child page; direct owner/emitter [UID:0000D7]. |
| `0x004c7609-0x004c7610` | padding | `get_bytes` seven `0xcc`. | Register/keep ignored padding. |
| `0x004c7610-0x004c7620` | `SimpleHelpPane2::OnAccept` | `lookup_funcs` `sub_4C7610`, size `0x10`; `xrefs_to` data ref at vtable slot `0x0061acec`; decompile calls close/dismiss helper and returns `1`. | Split to exact child page; direct owner/emitter [UID:0000D7]. |
| `0x004c7620-0x004c7668` | `SimpleHelpPane2::HandleEvent` | `lookup_funcs` `sub_4C7620`, size `0x48`; `xrefs_to` data ref at `0x0061acbc`; decompile cancels timer on event types `1`/`4` or event `0` outside anchor rect via `PointInRect`. | Split to exact child page; direct owner/emitter [UID:0000D7]. |
| `0x004c7668-0x004c7670` | padding | `get_bytes` eight `0xcc`. | Register/keep ignored padding. |
| `0x004c7670-0x004c7680` | `SimpleHelpPane2::OnCancel` | `lookup_funcs` `sub_4C7670`, size `0x10`; `xrefs_to` data ref at `0x0061acc0`; decompile calls close/dismiss helper and returns `0`; bytes `0x004c767d-0x004c7680` are the `retn 4`. | Split to exact child page; direct owner/emitter [UID:0000D7]. |
| `0x004c7680` | successor boundary | `lookup_funcs` `sub_4C7680`, size `0x160`; owned by [UID:00016T] factory page. | Do not include in UID `00016S`; successor is already exact. |

## Positive Evidence

- The exact range is fully modeled as method-sized functions plus `0xcc` padding. There are no unresolved raw helper starts inside UID `00016S`.
- `SimpleHelpPane::SimpleHelpPane` has 18 direct constructor xrefs in the live session, matching broad tooltip use across UI feature code. This strongly supports a real source-authored constructor and HelpPanes ownership.
- `g_pSimpleHelpPane` has 23 live xrefs. The target constructor publishes/fallback-clears it at `0x004c6ff1/0x004c6ff8`, the ordinary destructor clears it at `0x004c72e8`, and support/scalar teardown paths clear it at `0x004ce330` and `0x004ce5bf`.
- `SimpleHelpPane2` has no direct call xrefs to constructor `0x004c74b0`, but the adjacent factory at `0x004c7680`, singleton publish/clear refs, vtable refs, and destructor/factory/helper pages close the source placement. The constructor is not orphaned or owner-unknown.
- `g_pSimpleHelpPane2` has nine live xrefs: UI dismissal read `0x00451adb`, constructor publish/fallback `0x004c751b/0x004c7522`, destructor clear `0x004c75fa`, factory read/write/fallback `0x004c76ad/0x004c772a/0x004c7731`, support clear `0x004ce320`, and scalar deleting destructor clear `0x004ce520`.
- `SimpleHelpPane2` event methods are vtable/data referenced: `OnAccept` at `0x0061acec`, `HandleEvent` at `0x0061acbc`, and `OnCancel` at `0x0061acc0`.
- `SimpleHelpPane2Factory` [UID:00016T] and `SimpleHelpPane2FactoryHelpers` [UID:00022O] already carry source-ready first-draft C++ and should remain outside this target. Their implementation resolves the old "factory cleanup needed" blocker for this target.
- Existing local pattern supports this exact repair: [UID:00016R] `HelpPaneCore`, [UID:00016V] `ItemHelpPaneCore`, and [UID:00016W] `HelpTooltipDestructorThunks` are non-emitting split/index pages over exact child method pages.

## Negative And Counter-Evidence

- `xrefs_to 0x004c74b0` and `xrefs_to 0x004c75e0` return no direct xrefs. This is a confidence cap for direct reachability, not a reason to leave the parent unchanged: constructor/factory adjacency, singleton refs, vtable refs, and destructor wrapper pages prove the class and source family.
- An aggregate formal C++ block in UID `00016S` would span methods from both [UID:0000D6] `SimpleHelpPane` and [UID:0000D7] `SimpleHelpPane2`, plus internal padding. That would diverge from current HelpPanes split structure and make later child-level source correction harder.
- Leaving UID `00016S` as `RECONSTRUCTABLE:TRUE` with blank C++ keeps it in the not-covered reconstructable queue even though the correct improvement is structural: it should become a non-emitting index while exact child pages carry source-bearing methods.
- Moving any part of the range to `MiniMap`, rectangle helpers, timer helpers, or singleton global pages is not supported. Those are dependencies/callers/state, not owners.
- Merging successor factory [UID:00016T] into UID `00016S` is rejected. The live `lookup_funcs` boundary puts `sub_4C7680` exactly at the successor start, and factory/helpers already have accepted source-quality docs.

## Heuristic / Inference Reanalysis And Validation

### Ownership And Source Placement

Best owner for the parent index remains [UID:0000JU] `HelpPanes`. The exact child methods should use direct class owners:

- `SimpleHelpPane` methods: `CANONICAL_OWNER:0000D6`, `EMITTER_UIDS:0000D6`, with class/file route through [UID:0000JU].
- `SimpleHelpPane2` methods: `CANONICAL_OWNER:0000D7`, `EMITTER_UIDS:0000D7`, with class/file route through [UID:0000JU].

Rejected owners:

- `MiniMap`: only the factory consumer is MiniMap-related; UID `00016S` is not MiniMap-owned.
- Rectangle/GrafPort/timer helpers: these are dependencies used by constructors, paint, and event handling.
- Singleton globals: `g_pSimpleHelpPane` and `g_pSimpleHelpPane2` are state owned by the help pane source family, not source owners for the executable methods.

### Field, Type, And Helper Names

Best current source-facing names from this pass:

- `SimpleHelpPane::m_textBuffer` or `m_copiedTextBuffer` for the owned wide text pointer at `+0xf8` / `this[62]`. Constructor allocates `2 * len + 2`, copies UTF-16 text, null-terminates it, and paint/destructor consume the same field.
- `SimpleHelpPane::m_initialOpacity` / inherited pane alpha at `+0x90`, initialized by the constructor to float bits `0x3e4ccccd` (`0.2f`) after scheduling the timer.
- `SimpleHelpPane2::m_anchorRect` for the four-dword rectangle at `+0x224` (`this + 137` dwords in decompile). Constructor copies the optional rectangle or clears all four dwords, and the adjacent helper predicate reads the same rectangle.
- `g_pSimpleHelpPane` and `g_pSimpleHelpPane2` are resolved singleton names; do not use `unk_69AE00` or `dword_67A7D4` in final source text.
- `sub_544690` is the pane close/dismiss helper used by short close handlers; exact project name remains owned by pane/control source, but child pages can describe it source-facing as `Close()` / `Dismiss()` on the current pane rather than emitting `sub_544690`.
- `sub_5975E0` is the timer schedule/remove wrapper already documented by [UID:0001K8]; child pages should describe zero-duration calls as timer cancel/remove operations.
- Event byte at `event + 4` is closed enough for local documentation as event type. Types `1` and `4` are immediate cancel/handled cases for `SimpleHelpPane::OnTimerEvent`; type `0` cancels but returns not-handled. `SimpleHelpPane2::HandleEvent` cancels on `1`/`4`, or on type `0` when point `(event+8,event+12)` is outside `m_anchorRect`.

These names are inferred source-facing names. Lack of original symbol proof should not cause future code to emit `sub_`, `unk_`, `dword_`, or decompiler local names.

### Constructor / Factory Split

The old "factory split needs cleanup" blocker is resolved enough for this target:

- [UID:00016T] owns the exact `0x004c7680-0x004c77e0` factory and already has formal first-draft C++.
- [UID:00022O] owns the exact raw wrapper/predicate cluster and already has formal first-draft C++.
- UID `00016S` ends before both pages. It should only index `SimpleHelpPane` and `SimpleHelpPane2` method bodies through `0x004c7680`.

### SimpleHelpPane2 No-Direct-Xref Caveat

The lack of direct xrefs to `0x004c74b0` and `0x004c75e0` is real and should remain documented, but it is not a blocker to source-quality repair:

- The constructor publishes `g_pSimpleHelpPane2`, installs the three `SimpleHelpPane2` vtables, stores the anchor rectangle, and schedules the timer.
- The singleton page and factory page prove active lifecycle use.
- The event handlers have vtable refs.
- The destructor has singleton clear evidence and matching scalar deleting destructor support.

Therefore the right action is not to keep UID `00016S` unchanged. The right action is an exact child split with the constructor/destructor child pages documenting the no-direct-xref caveat as confidence impact.

## Score And Metadata Recommendation

### Target [UID:00016S]

Recommended target metadata after implementation:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000JU`
- `RECONSTRUCTABLE:FALSE`
- `EMITTER_UIDS:` blank
- Formal C++ remains blank.
- Disposition text: reviewed non-emitting HelpPanes split index over exact `SimpleHelpPane` and `SimpleHelpPane2` child method pages.

Reason for raising from the current source header `85/88`:

- Current session `398b87c1` reconfirms all method boundaries, exact successor boundary, singleton refs, vtable refs, event behavior, constructor/destructor behavior, and padding.
- The report resolves the target's actual blocker by recommending an implementation-ready split, not by leaving aggregate C++ blank.

Reason not to make UID `00016S` a high-scoring code emitter:

- It is not the correct emission unit. It spans eleven methods across two classes plus padding.
- Existing project pattern for this exact HelpPanes region is split-index parent plus exact method children.

### Exact child pages to create

The implementation callback should create exact child pages with validator-assigned UIDs. Proposed filenames and initial metadata:

| Proposed file | Owner/emitter | Proposed score | C++ disposition |
| --- | --- | --- | --- |
| `by-memory/0x004c6f90-0x004c7287.SimpleHelpPaneConstructor.md` | `0000D6` | `86/89` | Insert formal first-draft block `SimpleHelpPane constructor` below. |
| `by-memory/0x004c7290-0x004c7307.SimpleHelpPaneDestructor.md` | `0000D6` | `86/90` | Insert formal first-draft block `SimpleHelpPane destructor` below. |
| `by-memory/0x004c7310-0x004c743e.SimpleHelpPaneOnPaintFrame.md` | `0000D6` | `86/88` | Insert formal first-draft block `SimpleHelpPane OnPaintFrame` below. |
| `by-memory/0x004c7440-0x004c7450.SimpleHelpPaneOnMouseDown.md` | `0000D6` | `85/90` | Insert formal first-draft block `SimpleHelpPane OnMouseDown` below. |
| `by-memory/0x004c7450-0x004c7491.SimpleHelpPaneOnTimerEvent.md` | `0000D6` | `86/90` | Insert formal first-draft block `SimpleHelpPane OnTimerEvent` below. |
| `by-memory/0x004c74a0-0x004c74b0.SimpleHelpPaneOnKeyPress.md` | `0000D6` | `85/90` | Insert formal first-draft block `SimpleHelpPane OnKeyPress` below. |
| `by-memory/0x004c74b0-0x004c75d5.SimpleHelpPane2Constructor.md` | `0000D7` | `87/90` | Insert formal first-draft block `SimpleHelpPane2 constructor` below and preserve the no-direct-xref caveat in prose. |
| `by-memory/0x004c75e0-0x004c7609.SimpleHelpPane2Destructor.md` | `0000D7` | `86/90` | Insert formal first-draft block `SimpleHelpPane2 destructor` below. |
| `by-memory/0x004c7610-0x004c7620.SimpleHelpPane2OnAccept.md` | `0000D7` | `85/90` | Insert formal first-draft block `SimpleHelpPane2 OnAccept` below. |
| `by-memory/0x004c7620-0x004c7668.SimpleHelpPane2HandleEvent.md` | `0000D7` | `86/90` | Insert formal first-draft block `SimpleHelpPane2 HandleEvent` below. |
| `by-memory/0x004c7670-0x004c7680.SimpleHelpPane2OnCancel.md` | `0000D7` | `85/90` | Insert formal first-draft block `SimpleHelpPane2 OnCancel` below. |

Padding rows to preserve or add to `-ignored` if not already present:

- `0x004c7287-0x004c7290`
- `0x004c7307-0x004c7310`
- `0x004c743e-0x004c7440`
- `0x004c7491-0x004c74a0`
- `0x004c75d5-0x004c75e0`
- `0x004c7609-0x004c7610`
- `0x004c7668-0x004c7670`

## Formal C++ Disposition

Do not insert aggregate C++ into UID `00016S`.

Parent no-code proof:

- The target is a multi-method split index over two class owners, not one source function.
- Exact child method boundaries are proven, and neighboring HelpPanes pages already use child method pages for broad clusters.
- Parent aggregate C++ would either duplicate child pages later or force unrelated class methods into one reconstruction block.
- The source-facing C++ belongs in the exact child pages listed above, not in the parent.

Child C++ disposition: every proposed child page gets exact formal first-draft C++ below. The implementation callback should insert the matching block into that child's formal `RECONSTRUCTION_CPP CODE` multiline block and keep companion prose explaining inferred member/helper/event names. No child page is left without an explicit formal C++ disposition. The helper/member/type names are source-facing inferred names based on the current evidence and local HelpPanes style; do not replace them with `sub_`, `dword_`, `unk_`, or decompiler temporary names.

### Formal Child C++: `SimpleHelpPane` Constructor

Intended child: `by-memory/0x004c6f90-0x004c7287.SimpleHelpPaneConstructor.md`.

```cpp
SimpleHelpPane::SimpleHelpPane(const wchar_t *text,
                               Pane *owner,
                               int x,
                               int y,
                               int timeoutMs)
    : Pane(2),
      m_textBuffer(0)
{
    g_pSimpleHelpPane = this;

    const wchar_t *sourceText = (text != 0) ? text : L"";
    const size_t textLength = wcslen(sourceText);

    m_textBuffer = new wchar_t[textLength + 1];
    wcscpy(m_textBuffer, sourceText);

    const int margin = 5;
    const int lineHeight = GetTextLineHeight();
    int lineCount = 1;
    int maxLineWidth = 0;

    const wchar_t *lineStart = m_textBuffer;
    for (const wchar_t *scan = m_textBuffer; ; ++scan)
    {
        const bool lineBreak =
            (*scan == L'\0') || (*scan == L'\r') ||
            (*scan == L'\n') || (*scan == L'\t');

        if (!lineBreak)
            continue;

        const int lineWidth = MeasureTextWidth(lineStart, scan - lineStart);
        if (lineWidth > maxLineWidth)
            maxLineWidth = lineWidth;

        if (*scan == L'\0')
            break;

        ++lineCount;
        if (*scan == L'\r' && scan[1] == L'\n')
            ++scan;
        lineStart = scan + 1;
    }

    RectBounds bounds;
    bounds.left = x;
    bounds.top = y;
    bounds.right = x + maxLineWidth + margin * 2;
    bounds.bottom = y + lineCount * lineHeight + margin * 2;

    if (owner != 0)
    {
        Point ownerOffset;
        owner->GetScreenOffset(&ownerOffset);
        bounds.Offset(ownerOffset.x, ownerOffset.y);
    }

    ClampPopupRectToScreen(&bounds);
    SetBounds(bounds);

    if (owner != 0)
        owner->AddChild(this);

    Show();
    SetTimer(timeoutMs);
    m_initialOpacity = 0.2f;
}
```

Evidence/prose to preserve on the child page: constructor has 18 direct xrefs; publishes/fallback-clears `g_pSimpleHelpPane`; copies a UTF-16 text buffer into `m_textBuffer` at `+0xf8`; measures multiline text with `\r`, `\n`, and `\t` delimiters; clamps the popup rectangle against owner/screen bounds; schedules the timer through the shared timer wrapper; initializes inherited alpha/opacity storage at `+0x90` to float `0.2f`.

### Formal Child C++: `SimpleHelpPane` Destructor

Intended child: `by-memory/0x004c7290-0x004c7307.SimpleHelpPaneDestructor.md`.

```cpp
SimpleHelpPane::~SimpleHelpPane()
{
    delete [] m_textBuffer;
    m_textBuffer = 0;
    g_pSimpleHelpPane = 0;
}
```

Evidence/prose to preserve on the child page: ordinary destructor frees the constructor-owned wide text buffer and clears `g_pSimpleHelpPane`; scalar deleting wrapper remains separate ABI glue and should keep blank formal C++.

### Formal Child C++: `SimpleHelpPane::OnPaintFrame`

Intended child: `by-memory/0x004c7310-0x004c743e.SimpleHelpPaneOnPaintFrame.md`.

```cpp
void SimpleHelpPane::OnPaintFrame()
{
    RectBounds bounds;
    GetBounds(&bounds);

    DrawHelpPaneFrame(bounds);

    const int margin = 5;
    const int lineHeight = GetTextLineHeight();
    int drawY = bounds.top + margin;

    const wchar_t *lineStart = m_textBuffer;
    for (const wchar_t *scan = m_textBuffer; ; ++scan)
    {
        const bool lineBreak =
            (*scan == L'\0') || (*scan == L'\r') ||
            (*scan == L'\n') || (*scan == L'\t');

        if (!lineBreak)
            continue;

        DrawTextRun(bounds.left + margin, drawY, lineStart, scan - lineStart);

        if (*scan == L'\0')
            break;

        drawY += lineHeight;
        if (*scan == L'\r' && scan[1] == L'\n')
            ++scan;
        lineStart = scan + 1;
    }
}
```

Evidence/prose to preserve on the child page: paint copies the pane rectangle, uses the shared GrafPort/frame/background/text helpers, advances by the text helper line height, and treats carriage return, line feed, and tab as line delimiters over the copied `m_textBuffer`.

### Formal Child C++: `SimpleHelpPane::OnMouseDown`

Intended child: `by-memory/0x004c7440-0x004c7450.SimpleHelpPaneOnMouseDown.md`.

```cpp
bool SimpleHelpPane::OnMouseDown(const PaneEvent &event)
{
    Close();
    return false;
}
```

Evidence/prose to preserve on the child page: decompile calls the pane close/dismiss helper on the adjusted object and returns `0`; the `event` parameter is unused in this body.

### Formal Child C++: `SimpleHelpPane::OnTimerEvent`

Intended child: `by-memory/0x004c7450-0x004c7491.SimpleHelpPaneOnTimerEvent.md`.

```cpp
bool SimpleHelpPane::OnTimerEvent(const PaneEvent &event)
{
    enum
    {
        kPaneEventTimerTick = 0,
        kPaneEventMouseAction = 1,
        kPaneEventDismiss = 4
    };

    if (event.type == kPaneEventTimerTick)
    {
        CancelTimer();
        return false;
    }

    if (event.type == kPaneEventMouseAction || event.type == kPaneEventDismiss)
    {
        CancelTimer();
        return true;
    }

    return false;
}
```

Evidence/prose to preserve on the child page: event type byte is read at `event+4`; event types `0`, `1`, and `4` all cancel/remove the timer through the shared wrapper, but only `1` and `4` return handled.

### Formal Child C++: `SimpleHelpPane::OnKeyPress`

Intended child: `by-memory/0x004c74a0-0x004c74b0.SimpleHelpPaneOnKeyPress.md`.

```cpp
bool SimpleHelpPane::OnKeyPress(const PaneEvent &event)
{
    Close();
    return false;
}
```

Evidence/prose to preserve on the child page: decompile calls the pane close/dismiss helper on the adjusted object and returns `0`; the `event` parameter is unused in this body.

### Formal Child C++: `SimpleHelpPane2` Constructor

Intended child: `by-memory/0x004c74b0-0x004c75d5.SimpleHelpPane2Constructor.md`.

```cpp
SimpleHelpPane2::SimpleHelpPane2(const wchar_t *text,
                                 Pane *owner,
                                 int x,
                                 int y,
                                 const RectBounds *anchorRect,
                                 int timeoutMs,
                                 int horizontalAlign,
                                 int verticalAlign,
                                 const HelpPaneStyle *style)
    : HelpPane(text, owner, x, y, horizontalAlign, verticalAlign, style)
{
    g_pSimpleHelpPane2 = this;

    if (anchorRect != 0)
    {
        m_anchorRect = *anchorRect;

        RectBounds paneBounds;
        GetBounds(&paneBounds);

        Point ownerOffset;
        if (owner != 0)
            owner->GetScreenOffset(&ownerOffset);
        else
        {
            ownerOffset.x = 0;
            ownerOffset.y = 0;
        }

        m_anchorRect.Offset(ownerOffset.x - paneBounds.left,
                            ownerOffset.y - paneBounds.top);
    }
    else
    {
        m_anchorRect.Clear();
    }

    SetTimer(timeoutMs);
}
```

Evidence/prose to preserve on the child page: no direct code xrefs to `0x004c74b0` were found, but this is not no-code proof because factory adjacency, singleton publish/fallback at `0x004c751b/0x004c7522`, three vtable writes, `HelpPane::HelpPane` base construction, `m_anchorRect` copy/clear at `+0x224`, and timer scheduling all support an exact source-authored constructor. Preserve the no-direct-xref caveat as a confidence cap, not as a blank-C++ reason.

### Formal Child C++: `SimpleHelpPane2` Destructor

Intended child: `by-memory/0x004c75e0-0x004c7609.SimpleHelpPane2Destructor.md`.

```cpp
SimpleHelpPane2::~SimpleHelpPane2()
{
    g_pSimpleHelpPane2 = 0;
}
```

Evidence/prose to preserve on the child page: ordinary destructor rewrites the three `SimpleHelpPane2` vtable views, clears `g_pSimpleHelpPane2` at `0x004c75fa`, and then falls through to base `HelpPane` teardown. The vtable rewrites/base destructor call are compiler-emitted destructor mechanics; the source-shaped body is the singleton clear.

### Formal Child C++: `SimpleHelpPane2::OnAccept`

Intended child: `by-memory/0x004c7610-0x004c7620.SimpleHelpPane2OnAccept.md`.

```cpp
bool SimpleHelpPane2::OnAccept(const PaneEvent &event)
{
    Close();
    return true;
}
```

Evidence/prose to preserve on the child page: vtable/data ref at `0x0061acec`; decompile calls the close/dismiss helper on the adjusted object and returns `1`; the `event` parameter is unused in this body.

### Formal Child C++: `SimpleHelpPane2::HandleEvent`

Intended child: `by-memory/0x004c7620-0x004c7668.SimpleHelpPane2HandleEvent.md`.

```cpp
bool SimpleHelpPane2::HandleEvent(const PaneEvent &event)
{
    enum
    {
        kPaneEventCursorMove = 0,
        kPaneEventMouseAction = 1,
        kPaneEventDismiss = 4
    };

    if (event.type == kPaneEventMouseAction || event.type == kPaneEventDismiss)
    {
        CancelTimer();
        return false;
    }

    if (event.type == kPaneEventCursorMove &&
        !PointInRect(event.y, event.x, &m_anchorRect))
    {
        CancelTimer();
    }

    return false;
}
```

Evidence/prose to preserve on the child page: vtable/data ref at `0x0061acbc`; decompile reads the event type byte at `event+4`, cancels on type `1`/`4`, and for type `0` cancels only when the event point at `event+8/event+12` is outside `m_anchorRect` using the shared rectangle containment helper. Keep the coordinate-order note because the accepted helper page also uses `PointInRect(cursor.y, cursor.x, ...)`.

### Formal Child C++: `SimpleHelpPane2::OnCancel`

Intended child: `by-memory/0x004c7670-0x004c7680.SimpleHelpPane2OnCancel.md`.

```cpp
bool SimpleHelpPane2::OnCancel(const PaneEvent &event)
{
    Close();
    return false;
}
```

Evidence/prose to preserve on the child page: vtable/data ref at `0x0061acc0`; decompile calls the close/dismiss helper on the adjusted object and returns `0`; the `event` parameter is unused in this body.

## Rejected Alternatives

- Keep UID `00016S` as `RECONSTRUCTABLE:TRUE` with blank C++: rejected because it preserves the not-covered queue row and does not address the structural blocker.
- Emit all eleven methods from UID `00016S`: rejected because it is a broad aggregate across two class owners plus padding, unlike the accepted HelpPaneCore/ItemHelpPaneCore split pattern.
- Lower score because `SimpleHelpPane2::SimpleHelpPane2` has no direct xref: rejected because vtable/singleton/factory/destructor evidence closes class ownership and source route; the xref gap should be documented on the exact child page as a confidence cap.
- Merge the successor factory into UID `00016S`: rejected because `lookup_funcs` proves `0x004c7680` is the successor function start and [UID:00016T] already owns that body.
- Move `SimpleHelpPane2` methods to MiniMap: rejected because MiniMap is a consumer of the factory, not owner of this class method cluster.

## Recommended Support Doc Updates

If accepted, update support docs at report-level detail:

- `by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md`: convert to non-emitting split index, update metadata, replace the current "leave C++ blank because blockers remain" wording with this split-first rationale, and add the exact child range table.
- `by-file/HelpPanes.md`: update the `SimpleHelpPane` and `SimpleHelpPane2` rows to reference the new exact child pages under [UID:00016S], similar to the `HelpPaneCore` and `ItemHelpPaneCore` rows.
- `by-class/SimpleHelpPane.md`: add exact child page cross-references and current-session evidence for constructor xrefs, copied text field `+0xf8`, timer behavior, and close handlers. Consider raising from `85/86` to `86/88` if the implementation preserves the evidence.
- `by-class/SimpleHelpPane2.md`: add exact child page cross-references and current-session evidence for constructor no-direct-xref caveat, singleton lifecycle, `m_anchorRect` at `+0x224`, and event/vtable refs. Consider raising from `86/86` to `88/88` if the implementation preserves the evidence.
- `by-memory/0x0069ae00-0x0069ae04.g_pSimpleHelpPane.md` and `by-memory/0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2.md`: no metadata change required; optionally add one sentence that UID `00016S` is being split into exact child method pages while singleton evidence remains unchanged.
- Generated/tracker state: do not edit generated files manually. Run validators so `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/-ag-memory-coverage.md`, and generated `HelpPanes.cpp` refresh from source docs.

## Expected Validators After Implementation

Run scoped validators from `source-3/project-documentation` on every changed or newly created by-* file, for example:

> Executable block R001 was removed from this report and preserved verbatim in [00016S-SimpleHelpPanes-source-quality-removed.md](00016S-SimpleHelpPanes-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Use `--wait-generated` when verifying generated `HelpPanes.cpp` or generated research/coverage reports after C++ or reconstructable/emitter metadata changes.

## Implementation Tracking Checklist

Checked by B007 during the 2026-06-27 implementation callback.

- [x] Update [UID:00016S] `by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md` metadata to `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000JU`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank formal C++.
- [x] Rewrite [UID:00016S] status/reconstruction notes as a reviewed non-emitting split index, not a reconstructable blank-code aggregate.
- [x] Add the exact child range table for all eleven method bodies and internal padding listed in this report.
- [x] Create exact child page `by-memory/0x004c6f90-0x004c7287.SimpleHelpPaneConstructor.md` with owner/emitter `0000D6`, score `86/89`, current-session constructor evidence, inferred-name prose, and the formal `SimpleHelpPane` constructor C++ block from this report.
- [x] Create exact child page `by-memory/0x004c7290-0x004c7307.SimpleHelpPaneDestructor.md` with owner/emitter `0000D6`, score `86/90`, copied-text/free/singleton-clear evidence, scalar-wrapper separation prose, and the formal `SimpleHelpPane` destructor C++ block from this report.
- [x] Create exact child page `by-memory/0x004c7310-0x004c743e.SimpleHelpPaneOnPaintFrame.md` with owner/emitter `0000D6`, score `86/88`, GrafPort/frame/text-walk evidence, inferred helper-name prose, and the formal `SimpleHelpPane::OnPaintFrame` C++ block from this report.
- [x] Create exact child page `by-memory/0x004c7440-0x004c7450.SimpleHelpPaneOnMouseDown.md` with owner/emitter `0000D6`, score `85/90`, close-handler evidence, and the formal `SimpleHelpPane::OnMouseDown` C++ block from this report.
- [x] Create exact child page `by-memory/0x004c7450-0x004c7491.SimpleHelpPaneOnTimerEvent.md` with owner/emitter `0000D6`, score `86/90`, event-type/timer-cancel evidence, local event-name inference prose, and the formal `SimpleHelpPane::OnTimerEvent` C++ block from this report.
- [x] Create exact child page `by-memory/0x004c74a0-0x004c74b0.SimpleHelpPaneOnKeyPress.md` with owner/emitter `0000D6`, score `85/90`, close-handler evidence, and the formal `SimpleHelpPane::OnKeyPress` C++ block from this report.
- [x] Create exact child page `by-memory/0x004c74b0-0x004c75d5.SimpleHelpPane2Constructor.md` with owner/emitter `0000D7`, score `87/90`, `m_anchorRect` evidence, singleton publish/fallback evidence, no-direct-xref confidence caveat, inferred helper/member-name prose, and the formal `SimpleHelpPane2` constructor C++ block from this report.
- [x] Create exact child page `by-memory/0x004c75e0-0x004c7609.SimpleHelpPane2Destructor.md` with owner/emitter `0000D7`, score `86/90`, singleton clear evidence, destructor-wrapper support references, vtable/base-teardown prose, and the formal `SimpleHelpPane2` destructor C++ block from this report.
- [x] Create exact child page `by-memory/0x004c7610-0x004c7620.SimpleHelpPane2OnAccept.md` with owner/emitter `0000D7`, score `85/90`, vtable/close-handler evidence, and the formal `SimpleHelpPane2::OnAccept` C++ block from this report.
- [x] Create exact child page `by-memory/0x004c7620-0x004c7668.SimpleHelpPane2HandleEvent.md` with owner/emitter `0000D7`, score `86/90`, event-type and anchor-rectangle containment evidence, coordinate-order prose, and the formal `SimpleHelpPane2::HandleEvent` C++ block from this report.
- [x] Create exact child page `by-memory/0x004c7670-0x004c7680.SimpleHelpPane2OnCancel.md` with owner/emitter `0000D7`, score `85/90`, vtable/close-handler evidence, and the formal `SimpleHelpPane2::OnCancel` C++ block from this report.
- [x] Add or verify ignored padding rows for `0x004c7287-0x004c7290`, `0x004c7307-0x004c7310`, `0x004c743e-0x004c7440`, `0x004c7491-0x004c74a0`, `0x004c75d5-0x004c75e0`, `0x004c7609-0x004c7610`, and `0x004c7668-0x004c7670`.
- [x] Update `by-file/HelpPanes.md` so the `SimpleHelpPane` and `SimpleHelpPane2` rows reference the exact child pages rather than treating [UID:00016S] as the source-bearing aggregate.
- [x] Update `by-class/SimpleHelpPane.md` with exact child cross-references and current-session evidence; consider `86/88` if the added evidence is fully incorporated.
- [x] Update `by-class/SimpleHelpPane2.md` with exact child cross-references, `m_anchorRect` evidence, event/vtable refs, and no-direct-xref caveat; consider `88/88` if the added evidence is fully incorporated.
- [x] Do not edit generated reports, project-level generated files, or any `-coverage-report.md` file manually.
- [x] Run scoped validators for every changed/new by-* file and report command ids/timestamps.
- [x] After validator refresh, verify generated tracker/coverage/C++ state no longer treats [UID:00016S] as a reconstructable blank-code emitter.

Implementation proof:

- Metadata/TMP proof: `rg -n "\[TMP:|^\*\*\* COMPLETION:|^\*\*\* CONFIDENCE:|^\*\*\* CANONICAL_OWNER:|^\*\*\* RECONSTRUCTABLE:|^\*\*\* EMITTER_UIDS:"` over the parent, support docs, and eleven child pages found no TMP refs and confirmed [UID:00016S] as `88/90`, owner `0000JU`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`; [UID:00048E]-[UID:00048J] as owner/emitter `0000D6`; [UID:00048K]-[UID:00048O] as owner/emitter `0000D7`; `SimpleHelpPane` as `86/88`; and `SimpleHelpPane2` as `88/88`.
- Child UID proof: validator inserted UIDs [UID:00048E][0x004c6f90-0x004c7287.SimpleHelpPaneConstructor](by-memory/0x004c6f90-0x004c7287.SimpleHelpPaneConstructor.md), [UID:00048F][0x004c7290-0x004c7307.SimpleHelpPaneDestructor](by-memory/0x004c7290-0x004c7307.SimpleHelpPaneDestructor.md), [UID:00048G][0x004c7310-0x004c743e.SimpleHelpPaneOnPaintFrame](by-memory/0x004c7310-0x004c743e.SimpleHelpPaneOnPaintFrame.md), [UID:00048H][0x004c7440-0x004c7450.SimpleHelpPaneOnMouseDown](by-memory/0x004c7440-0x004c7450.SimpleHelpPaneOnMouseDown.md), [UID:00048I][0x004c7450-0x004c7491.SimpleHelpPaneOnTimerEvent](by-memory/0x004c7450-0x004c7491.SimpleHelpPaneOnTimerEvent.md), [UID:00048J][0x004c74a0-0x004c74b0.SimpleHelpPaneOnKeyPress](by-memory/0x004c74a0-0x004c74b0.SimpleHelpPaneOnKeyPress.md), [UID:00048K][0x004c74b0-0x004c75d5.SimpleHelpPane2Constructor](by-memory/0x004c74b0-0x004c75d5.SimpleHelpPane2Constructor.md), [UID:00048L][0x004c75e0-0x004c7609.SimpleHelpPane2Destructor](by-memory/0x004c75e0-0x004c7609.SimpleHelpPane2Destructor.md), [UID:00048M][0x004c7610-0x004c7620.SimpleHelpPane2OnAccept](by-memory/0x004c7610-0x004c7620.SimpleHelpPane2OnAccept.md), [UID:00048N][0x004c7620-0x004c7668.SimpleHelpPane2HandleEvent](by-memory/0x004c7620-0x004c7668.SimpleHelpPane2HandleEvent.md), and [UID:00048O][0x004c7670-0x004c7680.SimpleHelpPane2OnCancel](by-memory/0x004c7670-0x004c7680.SimpleHelpPane2OnCancel.md).
- Validator proof: split/index batch ran from `source-3/project-documentation` over the parent, all eleven new children, and [UID:0000VN][-ignored](by-memory/-ignored.md) with `python .\tools\validator.py --mode file --file <file> --apply --queue-timeout 240 --wait-generated`; the batch exited `0`, with visible command evidence including `000000004365` at `2026-06-27T13:20:08-04:00` for the first child and final generated refresh `000000004384` at `2026-06-27T13:22:17-04:00`. Support-doc batch ran the same validator command for [UID:0000JU][HelpPanes](by-file/HelpPanes.md), [UID:0000D6][SimpleHelpPane](by-class/SimpleHelpPane.md), and [UID:0000D7][SimpleHelpPane2](by-class/SimpleHelpPane2.md); the batch exited `0`, with [UID:0000JU] command `000000004392` at `2026-06-27T13:25:39-04:00`, final support/generated refresh command `000000004395` at `2026-06-27T13:26:01-04:00`, and generated `auto-generated/NexusTK/ui/controls/HelpPanes.cpp` stamped `validator-command-id: 000000004395`.
- Generated proof: `auto-generated/-ag-research-tracker.md` lists [UID:00016S] as `88/90`, `false`, generated-child count `0`; `auto-generated/-ag-coverage-report-by-memory.md` lists [UID:00016S] as `emits_code:false` / `not_reconstructable`; the same coverage report lists [UID:00048E]-[UID:00048O] as `emits_code:true` / `reconstructable`; `auto-generated/NexusTK/ui/controls/HelpPanes.cpp` contains the formal child bodies for `SimpleHelpPane::SimpleHelpPane`, `~SimpleHelpPane`, `OnPaintFrame`, `OnMouseDown`, `OnTimerEvent`, `OnKeyPress`, `SimpleHelpPane2::SimpleHelpPane2`, `~SimpleHelpPane2`, `OnAccept`, `HandleEvent`, and `OnCancel`.
- Lease proof: B007 leased only files immediately before each edit batch. The split leases on [UID:00016S] and [UID:0000VN] had expired by release time and reported `Rejected[No active lease]`; support-doc leases for [UID:0000JU], [UID:0000D6], and [UID:0000D7] released with `Success`. Final `tools/leaser/lease.json` check found no `B007` active lease.

## Final Report Status

FINISHED_REPORT

No by-* docs, generated files, coverage reports, validator state, IDA DB, or leases were edited during this report-only pass.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/00016S-SimpleHelpPanes-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/00016S-SimpleHelpPanes-source-quality.md","timestamp":"2026-06-27T13:36:51","uid":"00016S"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00016S-SimpleHelpPanes-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/00016S-SimpleHelpPanes-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00016S"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
