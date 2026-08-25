** TARGET-REPORT-UID:0000EO **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000EO TextEditPane Class Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0000EO] `TextEditPane` reconstructable and owned/emitted through [UID:0000ON] `TextEditPane.cpp`; update the class documentation from `88/85` to `89/88`.
- Final disposition: declaration-level class C++ is now appropriate, but method bodies should remain on exact child pages. The class page should emit a header-style class skeleton with `[[CHILDREN]]`, stable member-field comments, and source-facing method names. Constructor argument names remain partly inferred, so the constructor declaration must be marked provisional in prose and validated by the constructor child before any method-body C++ is accepted.
- Required action: implement the target/support doc updates listed below after supervisor review; do not edit `by-memory/-coverage-report.md` directly.
- Confidence: high for owner/source route, method families, exact active-editor and clipboard globals, support-object boundary policy, and generated-name rejection; medium-high for final names of `+0x138/+0x13c/+0x140`, callback-state structures, and some constructor argument names.

## Target

- Target UID: [UID:0000EO]
- Target path: `source-3/project-documentation/by-class/TextEditPane.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B005/research/0000EO-TextEditPane-class-source-quality.md`
- Current metadata: `COMPLETION:88`, `CONFIDENCE:85`, `CANONICAL_OWNER:0000ON`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000ON`, blank formal C++.
- Source route: [UID:0000ON] `NexusTK/ui/controls/TextEditPane.cpp`.
- Current active assignment type: report-only B-agent source-quality pass. No by-* docs or coverage reports were edited in this pass.

## Evidence Checked

- Required instructions: `tools/leaser/Agents/Agent-B005/goal.md`, `tools/leaser/Agents/Supervisor.md`, `.codex/AGENTS.md`, `by-structure.md`, `inference_research.md`, and `by-project-structure/proposed-source-tree.md`.
- Target/support docs: `by-class/TextEditPane.md`, `by-file/TextEditPane.md`, `by-class/TextEditControlPane.md`, `by-file/TextEditControlPane.md`, `by-class/TextEditObject.md`, `by-class/TextEditScrap.md`, `by-class/EPFTextEditObject.md`, `by-global/g_pActiveTextEditPane.md`, and the exact TextEditPane by-memory children listed below.
- Current local PE: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, image base `0x00400000`; `.text` `0x00401000-0x0060c4ac`, `.rdata` `0x0060d000-0x0066c0be`, `.data` `0x0066d000-0x0069ce24`.
- Current IDA MCP availability: attempted `tools/list` at `http://127.0.0.1:13337/mcp`; current session returned `Unable to connect to the remote server`. Current-session facts below therefore distinguish local PE scans from prior live-IDA facts already written in by-* docs.
- Current local PE reference scan matched the existing IDA-backed documentation on the main route anchors:

| Target | Local PE rel32 refs | Absolute-VA pointer refs | RVA pointer refs | Meaning |
| --- | ---: | ---: | ---: | --- |
| `0x0058dce0` | 26 | 0 | 0 | Constructor ordinary caller fan-in; matches constructor doc. |
| `0x0058e140` | 4 | 0 | 0 | Destructor/scalar-wrapper/EH refs; matches destructor doc. |
| `0x0058e380` | 7 | 0 | 0 | `CopyWideText` callers; includes `TextEditControlPane` wrapper. |
| `0x0058e490` | 1 | 0 | 0 | `TextEditControlPane` raw serializer forwarder at `0x00498c4a`. |
| `0x00590810` | 0 | 9 | 0 | Virtual/vtable/data route for `OnDraw`, no ordinary caller. |
| `0x005909f0` | 0 | 7 | 0 | Virtual/vtable/data route for `OnKeyEvent`, no ordinary caller. |
| `0x00590de0` | 0 | 1 | 0 | Virtual route for `OnMouseEvent`, no ordinary caller. |
| `0x00591740` | 0 | 0 | 1 | One RVA-like metadata/table ref; no ordinary direct caller. |
| `0x00593c20` | 0 | 4 | 0 | Address-taken `TextRunMeasureCallback`. |
| `0x00593cf0` | 0 | 0 | 0 | Raw no-function measure variant has no direct start refs. |
| `0x00593db0` | 0 | 2 | 0 | Address-taken `DrawTextRunCallback`. |
| `0x00593f00` | 0 | 0 | 0 | Raw no-function draw variant has no direct start refs. |
| `0x00594040` | 2 | 0 | 0 | Input/navigation helper ordinary rel32 refs. |
| `0x00594e20` | 0 | 0 | 0 | Raw pre-support helper has no direct start refs. |
| `0x0069bdfc` | 0 | 6 | 0 | Styled Unicode clipboard format global xrefs. |
| `0x0069be00` | 0 | 8 | 0 | Active TextEditPane pointer xrefs. |
| `0x0069be04` | 0 | 8 | 0 | Mouse-selection scratch word xrefs. |

## Executive Recommendation

Keep the target as the direct class page for `TextEditPane`, with [UID:0000ON] as both canonical file owner and code emitter. `TextEditPane` is the core rich/styled text editor pane, not the `ControlPane` wrapper. It inherits/embeds `ScrollablePane` behavior, owns text storage, line and format/style tables, caret/selection state, IME focus routing, clipboard behavior, text-run measurement/drawing callbacks, and local support objects (`TextEditObject`, `TextEditScrap`, `EPFTextEditObject`) that are tightly coupled to editor state.

The class documentation should no longer stop at "field/helper names unresolved." It can defensibly name the main fields and helper roles now, while clearly marking table names and callback layouts as inferred where original source spelling is not recovered. The page should receive declaration-only first-draft C++ with `[[CHILDREN]]`; full method bodies must remain blank on the class page and should be emitted later from exact child by-memory pages when each child reaches source-ready signatures and branch behavior.

## Heuristic / Inference Reanalysis

### Owner And Source Placement

Best owner: [UID:0000ON] `TextEditPane.cpp`, with the class page [UID:0000EO] as the narrow class owner for class methods and vtable data.

Evidence for:
- `TextEditPane` constructor/destructor/copy/draw/key/mouse/invalidation children are exact TextEditPane method bodies with direct class state, vtables, and `ScrollablePane` base behavior.
- [UID:0000ON] already owns the tightly adjacent text-run callbacks, TextEdit support objects, styled clipboard string, wildcard string, active-editor global, styled-clipboard-format global, and mouse-selection scratch word.
- TextEditPane constructor writes the primary and two secondary vtable pointers at `+0x000/+0x0a0/+0x0a4` from [UID:0003DV] `0x0062df94-0x0062e048`.
- Constructor/destructor both read/write [UID:0000Q7] `g_pActiveTextEditPane` at `0x0069be00`.
- `TextEditControlPane` owns an embedded `TextEditPane*` at `+0x10c` and forwards into the editor, but wrapper fan-in and control type `5` make it a separate adapter source, not the editor implementation owner.

Rejected owner alternatives:
- `TextEditControlPane`: rejected because it is the reusable `ControlPane` adapter and only owns wrapper fields, embedded-editor allocation/deletion, and forwarding stubs.
- `TextBoxPane`: rejected because it is a derived TextEditPane-like control with its own constructor/vtable island embedded inside the old support-object range; it does not own the base editor implementation.
- `TextFilter`: rejected because it starts at `0x00595760`, has singleton/sanitizer behavior, and is now a neighboring file.
- `CopyWindow`: rejected because it reads/clears the active editor global and calls `SelectAll`, but that is consumer behavior.
- `Encoder`/`BinaryCodec`: rejected for serialization ownership; `EncodeTextEditState` constructs and consumes a stack `Encoder`, while text-edit table offsets define the serialized payload.
- `GrafPort`/`SurfaceRenderCallbackTable`: rejected as dependencies for drawing; TextEditPane consumes draw-state and pixel helpers but does not own those render primitives.
- `ScrollBar`/`ScrollVolumePane`/`ScrollNewGroupPane`: rejected for stale generated scrollbar helper pollution. The broad scrollbar corridor is mixed/non-emitting, and several generated TextEditPane names in that area are now proven ScrollVolume or ScrollNewGroup behavior.
- FittingRoom / RankingEvent generated helpers: rejected for the `0x00593b20`, `0x00593d00`, and `0x00593f00` neighborhood. Those labels cut through or neighbor TextEditPane callback/raw bodies.

### Field And Type Name Recommendations

The class page should replace the older "line-break or format/color table" wording with a stronger field map. These names are best source-facing recommendations, not symbol-proven original spellings:

| Offset | Recommended name | Confidence | Evidence / caveat |
| --- | --- | --- | --- |
| `+0x134` | `m_textStorage` | high | Constructor allocates `List(2, 128)`; `CopyWideText` reads this slot, clamps to storage `+0x0c`, obtains text through virtual `+0x10`, copies UTF-16, and terminates output; serialization writes this payload first as raw text bytes. |
| `+0x138` | `m_lineTable` or `m_lineBreakTable` | medium-high | Constructor allocates `List(16, 16)`; formatting/wrap helpers around `0x00592f10/0x00592f30/0x00592fb0` manipulate line insert/delete/split state; serialization serializes this as a 16-byte-record table. |
| `+0x13c` | `m_styleRuns` or `m_formatRuns` | medium-high | Formatting range uses this with `+0x140` for style/run insert/search/update; serialization serializes this as a 16-byte-record table. Exact original "style" versus "format" spelling remains inferred. |
| `+0x140` | `m_formatRecords` | medium-high | Constructor allocates `List(4, 16)`; formatting helpers use it as the compact format/style-record table; serialization serializes `count * 4`. |
| `+0x144` | `m_selectionStart` | high | Draw/key/mouse/invalidation docs repeatedly use it as one selection/caret endpoint. |
| `+0x146` | `m_selectionEnd` | high | Paired selection/caret endpoint with `+0x144`. |
| `+0x148/+0x14a` | `m_savedSelectionStart` / `m_savedSelectionEnd` or mouse expansion anchors | medium | Mouse handler stores/uses these with scratch `word_69BE04` during double/triple-click and drag selection. Exact source names are not safe. |
| `+0x158` | `m_dragSelectionStart` / current hit position | medium | Mouse handler uses this in selection update paths; keep descriptive until child body is source-ready. |
| `+0x159` | editor state byte | medium | Constructor initializes; exact role not fully separated from neighboring flags. |
| `+0x15c` | `m_editorFlags` | high for flags, medium for bit names | Used across constructor, key/mouse/input/raw helpers for active/editable/read-only/selection visibility/autoscroll or blur-hide decisions. Bits should be named only after child pass. |
| `+0x160/+0x164/+0x166` | click timing / last click point state | medium | Mouse handler compares event `+0x18` with `+0x160` and tracks click/drag coordinates around `+0x164/+0x166`. |
| `+0x167` | `m_mouseMode` / `m_dragMode` | high | Existing target already lists mouse/drag mode; mouse handler dispatch confirms. |
| `+0x169` | `m_dirty` / `m_needsRefresh` | medium-high | Key-event docs record dirty/needs-refresh byte after mutations. |
| `+0x16a` | `m_maskedText` / `m_passwordMode` | high | Wildcard `'*'` xrefs and callbacks use this for password-mask display. Prefer "masked text" in class prose because the editor may not be password-specific. |
| `+0x16c` | `m_deleteForwardIndex` | medium | Existing docs identify delete-forward line/index field; input-navigation delete path supports this. |
| `+0x16e` | `m_deleteBackwardIndex` | medium | Existing docs identify delete-backward format/index field; keep descriptive. |
| `+0x170` | `m_inputState` / composition/editability substate | medium | Key-event docs mention active composition or input gating. Exact bit/byte role remains unresolved. |
| `+0x172` | `m_maxLines` or line-limit state | medium | Constructor and wrapper set max lines; exact storage needs child confirmation. |
| `+0x173` | `m_numericCommaMode` / formatting mode byte | medium | Lower renderer and input paths mention formatting mode; exact name remains inferred. |

### Constructor Signature

Generated source is not authority, but current `simroot_v2/class_TextEditPane.cpp` and several call sites consistently show a source-shaped constructor with an allocated `this` pointer plus twelve explicit arguments:

```cpp
TextEditPane::TextEditPane(
    int maxWidth, int maxHeight,
    int contentWidth, int contentHeight,
    int backgroundColor, int scrollColor,
    char hasHScrollbar, char hasVScrollbar,
    unsigned int styleFlags, unsigned short fontId,
    char isReadOnly, char inputMode);
```

This is a better first-draft signature than the class page's current generic "thirteen parameters after this" wording. The safer implementation wording is:

- "Call sites and generated-source leads consistently show an allocator/`this` pointer plus twelve explicit constructor arguments: outer/max dimensions, content dimensions, two color/style words, horizontal/vertical scrollbar booleans, style flags, font id/default format, read-only byte, and input-mode byte."
- "Exact original parameter names are not proven; preserve the child constructor page as the authority before entering method-body C++."

The current class declaration can use this signature as provisional with a surrounding source-quality note. If the supervisor prefers to avoid provisional constructor declarations in generated class code, the class C++ block should still include the field map and method declarations but omit the constructor line until [UID:0002ZY] is updated.

### Method And Helper Name Recommendations

Source-facing names that should be used or added to the class/file docs:

| Address / item | Recommended source-facing name | Confidence / notes |
| --- | --- | --- |
| `0x0058dce0-0x0058e132` | `TextEditPane::TextEditPane(...)` | high role, medium parameter names. |
| `0x0058e140-0x0058e228` | `TextEditPane::~TextEditPane()` | high. Scalar deleting wrappers/thunks regenerate from class declaration and should not be handwritten. |
| `0x0058e380-0x0058e3d7` | `TextEditPane::CopyWideText(wchar_t *outText, short maxChars) const` or `GetText` wrapper target | high behavior, medium exact spelling. It is ready for child first-draft C++ once text-storage type alias is accepted. |
| `0x0058e490-0x0058e691` | `EncodeTextEditState(TextEditPane *editor, unsigned short *outSize)` or `TextEditPane::EncodeState(unsigned short *outSize)` | high behavior, medium member/free-helper form. Existing file-level ownership is correct because it is exposed through a raw wrapper and uses Encoder. |
| `0x00590810-0x005909e3` | `TextEditPane::OnDraw()` | high. Virtual/vtable route and draw behavior are stable. |
| `0x005909f0-0x00590dc5` | `TextEditPane::OnKeyEvent(Event *event)` | high role, medium exact return/event type. |
| `0x00590de0-0x00591180` | `TextEditPane::OnMouseEvent(Event *event)` | high role, medium exact return/event type. |
| `0x00591740-0x005917c9` | `TextEditPane::InvalidateTextRegion(short start, short end)` | high behavior, medium exact spelling. |
| `0x00593500` | `TextEditPane::IterateTextRuns(...)` | high role, exact signature pending callback-state layout. |
| `0x00593c20` | `TextRunMeasureCallback` / `MeasureTextRunCallback` | high callback role; keep file-local free callback, not class method. |
| `0x00593db0` | `DrawTextRunCallback` | high callback role; keep file-local free callback. |
| `0x00593cf0` | `TextRunMeasureCallbackThiscallRaw` descriptive raw variant | route-negative raw body; no direct start refs; source shape may be an alternate adapter or compiler-emitted duplicate. |
| `0x00593f00` | `DrawTextRunCallbackThiscallRaw` descriptive raw variant | route-negative raw body; no direct start refs; do not call it FittingRoom. |
| `0x00594120` | `DeleteSelection` | high behavior, exact spelling unproven. |
| `0x00594190` | `DeleteForward` / `DeleteNextCharacter` | medium-high behavior; raw no-function helper. |
| `0x005941f0` | `MoveCursor` / `HandleNavigationKey` | medium-high; switch enum names unresolved. |
| `0x00594b50` | `FindWordBoundary` | high behavior from mouse/cursor callers. |
| `0x00594cb0` | `AutoScrollSelectionToPoint` | high behavior from mouse handler callers. |
| `0x00594e20` | raw pre-support draw/callback-state helper | medium; no direct start refs, exact signature unresolved. |

### Globals And File-Local Data

Recommended source-facing names:

- `0x0069bdfc`: `s_styledUnicodeClipboardFormat` or `g_textEditStyledUnicodeClipboardFormat`. The IDA label `format` is too generic. Static image value `0xffffffff`; constructor registers `Nexon.StyledUnicodeText`; key/paste helpers use `IsClipboardFormatAvailable` and `GetClipboardData`.
- `0x0069be00`: `g_pActiveTextEditPane`. Keep this over `g_pCopyWindowTextEditPane` because constructor/destructor own it and CopyWindow is only a consumer.
- `0x0069be04`: `s_mouseSelectionAnchor` or `g_textEditMouseSelectionAnchor`. It is a module-scope scratch word used only by `TextEditPane::OnMouseEvent` for selection expansion.
- `0x0062e138-0x0062e168`: `L"Nexon.StyledUnicodeText"` file-owned string literal.
- `0x0062e168-0x0062e16c`: `L"*"` wildcard/masked-text literal.

### Raw Callback / Support-Object Boundaries

Boundary decisions to preserve in target/support docs:

- `0x00593b20-0x00593c1c` is real raw TextEditPane wildcard/password-mask measure helper code, not FittingRoom and not padding.
- `0x00593c1c-0x00593c20` is four `0xcc` bytes before `TextRunMeasureCallback`.
- `0x00593ce5-0x00593cf0` is eleven `0xcc` bytes before raw measure variant `0x00593cf0`.
- `0x00593dad-0x00593db0` is three `0xcc` bytes before `DrawTextRunCallback`.
- `0x00593ef6-0x00593f00` is ten `0xcc` bytes before raw draw variant `0x00593f00`.
- `0x0059403b-0x00594040` is five `0xcc` bytes before the input/navigation helper cluster.
- `0x00594618-0x00594658` is a switch table for the cursor/navigation dispatcher at `0x005941f0`, not padding.
- `0x00594e12-0x00594e20` is alignment; `0x00594e20-0x00594e5f` is real raw TextEditPane helper code; `0x00594e5f-0x00594e60` is one `0xcc` byte before support objects.
- The historical broad `0x00594e60-0x00595760` support-object range must remain a non-reconstructable audit map because it crosses `TextBoxPane` constructor `0x00595390-0x005954b3`. Exact children [UID:0003M7] and [UID:0003M8] carry TextEditPane support-object ownership.

### Generated Name Pollution Cleanup

Record these as explicit rejected alternatives, not passive caveats:

- Reject stale FittingRoom labels around `0x00593b20`, `0x00593d00`, and `0x00593f00`. Current docs and local PE scans show `0x00593cf0`/`0x00593f00` have no direct start refs and sit in the TextEditPane callback region; the stale `0x00593d00-0x00593e6b` slice cuts through real callback bodies.
- Reject `RankingEventListPane`-style generated helper names inside TextEditPane generated output unless the underlying address is independently verified.
- Reject generated TextEditPane ownership for `0x00561420`, `0x00561a40`, `0x00561b00`, and `0x00561bc0`; existing docs route those to [UID:0000CL] `ScrollNewGroupPane`.
- Reject `g_pCopyWindowTextEditPane` as canonical global name; use it only as a historical/generated alias.
- Reject treating `Encoder` writer methods as TextEditPane-owned because the serializer is a caller/consumer of `Encoder`.
- Reject broad support-object emission from [UID:0002XX] because it crosses `TextBoxPane`.

## First-Draft C++ Recommendation

The class page should receive declaration-only C++. This is not a method-body pass and should not paste constructor/destructor/draw/key/mouse bodies into the class page. The declaration should look like late-1990s/mid-2000s C++ and should use `[[CHILDREN]]` to let exact child pages emit methods later.

Recommended formal block for [UID:0000EO], with prose directly above it explaining that constructor parameter names are provisional:

```cpp
class TextEditPane : public ScrollablePane
{
public:
    TextEditPane(int maxWidth,
                 int maxHeight,
                 int contentWidth,
                 int contentHeight,
                 int backgroundColor,
                 int scrollColor,
                 char hasHorizontalScrollbar,
                 char hasVerticalScrollbar,
                 unsigned int styleFlags,
                 unsigned short fontId,
                 char isReadOnly,
                 char inputMode);
    virtual ~TextEditPane();

    int CopyWideText(wchar_t *outText, short maxChars) const;
    unsigned char *EncodeState(unsigned short *outSize) const;

    void SetText(const wchar_t *text, short length, short selectStart, short selectEnd);
    void SetSelectionRange(short start, short end);
    void SelectAll();
    void SetMaxLength(short maxLength);
    void SetMaxLines(short maxLines);
    bool IsEmpty() const;
    void ScrollToTop();

protected:
    virtual void OnDraw();
    virtual int OnKeyEvent(Event *event);
    virtual int OnMouseEvent(Event *event);

    void InvalidateTextRegion(short start, short end);
    void DeleteSelection();
    void FindWordBoundary(short index, short *wordStart, short *wordEnd) const;
    void AutoScrollSelectionToPoint(int x, int y);

private:
    List *m_textStorage;       // +0x134, UTF-16 text storage, 2-byte entries
    List *m_lineTable;         // +0x138, inferred line/wrap table, 16-byte records
    List *m_styleRuns;         // +0x13c, inferred style/format run table, 16-byte records
    List *m_formatRecords;     // +0x140, inferred compact format record table, 4-byte records
    short m_selectionStart;    // +0x144
    short m_selectionEnd;      // +0x146
    unsigned int m_editorFlags;// +0x15c, inferred bitfield
    unsigned char m_mouseMode; // +0x167
    unsigned char m_dirty;     // +0x169
    unsigned char m_maskedText;// +0x16a, wildcard/password-style display
    short m_deleteForwardIndex;// +0x16c
    short m_deleteBackwardIndex;// +0x16e
    unsigned char m_inputState;// +0x170, provisional input/composition state
    short m_maxLines;          // +0x172, provisional limit state
    unsigned char m_formatMode;// +0x173, provisional formatting/input mode

    [[CHILDREN]]
};
```

Readiness rationale:
- Good enough for class-level emission because it records stable inheritance, field families, virtual methods, high-traffic helpers, and a child insertion point.
- Not good enough for final method-body C++ in the class page because exact constructor parameter names/order still depend partly on generated leads, callback-state structs are not final, and large child aggregates remain unsplit.
- If the supervisor considers the constructor declaration too provisional for emitted C++, the fallback is not to leave the page blank silently; insert a target-specific comment-only proof saying declaration C++ is deferred until [UID:0002ZY] resolves constructor arguments, while keeping the report's declaration as the next implementation target.

## Child Memory C++ Readiness

Recommended child policy:

- [UID:0002O9] `TextEditPaneCopyWideText`: first child likely ready for first-draft C++ after accepting `m_textStorage`; behavior is simple and exact.
- [UID:0002ZY] constructor and [UID:0002ZZ] destructor: behavior is strong but constructor signature/table field names should be corrected first. Destructor can get first-draft C++ sooner than constructor once table members are named.
- [UID:00030C] `OnDraw`, [UID:00030F] `OnKeyEvent`, [UID:00030E] `OnMouseEvent`, [UID:00030D] `InvalidateTextRegion`: exact method pages are eligible by score/route but should wait for event type, helper names, and key/mouse bit names. They are not class-page method bodies.
- [UID:0001JP] and [UID:0001JS]: keep formal C++ blank until split into exact helper pages or until a dedicated aggregate policy is accepted. They contain many raw pockets, callback adapters, switch tables, and helper bodies.
- [UID:0001JQ] and [UID:0001JR]: do not emit callback C++ until callback-state struct fields are named. They should stay file-local callbacks under `TextEditPane.cpp`.
- [UID:0003FC] and [UID:0003FD]: keep blank until raw variant/adaptor policy is decided; no direct start refs mean they may be compiler-shaped retained variants or file-local raw adapters.
- [UID:0003M7] and [UID:0003M8]: source-bearing support-object islands, but exact class child pages should emit individual methods, not broad island C++.
- [UID:0002XX]: keep `RECONSTRUCTABLE:FALSE` and blank C++ as an audit map.
- Globals [UID:000301], [UID:000302], [UID:000303]: source-declared/static data can later emit declarations/initializers through `TextEditPane.cpp`; exact names are now strong enough for support-doc text, but the pages currently keep C++ blank because original names are not proven.

## Exact Recommended Target Changes

For `by-class/TextEditPane.md`:

1. Metadata:
   - `COMPLETION:88 -> 89`
   - `CONFIDENCE:85 -> 88`
   - Keep `CANONICAL_OWNER:0000ON`
   - Keep `RECONSTRUCTABLE:TRUE`
   - Keep `EMITTER_UIDS:0000ON`
2. Add the declaration-only C++ block above, or if the supervisor rejects provisional constructor parameters, add a comment-only C++ defer proof and explicitly state that the class is declaration-ready after [UID:0002ZY] constructor signature update.
3. Replace the "field names remain provisional" caveat with the field table from this report. Keep `+0x138/+0x13c/+0x140`, callback state, and several flag-bit names marked inferred.
4. Add source-quality helper-name section with the method/helper recommendations above.
5. Add generated-name pollution cleanup section with explicit rejected alternatives.
6. Add support-object boundary section: exact children [UID:0003M7] and [UID:0003M8] carry source-bearing support-object code; [UID:0002XX] is a non-emitting audit map because of the embedded [UID:0002RV] `TextBoxPane` constructor.
7. Update old code-entry wording if present: active gate is combined-score/emitter; this target should not preserve old `95/95` as the sole reason for blank C++. If C++ is still deferred, it must be due to exact constructor/table/callback source-quality uncertainty, not stale score policy.

## Support-Doc Update Checklist

For `by-file/TextEditPane.md`:

- Recommend score `89/86 -> 90/88` if the implementation adds the same field map, generated-name cleanup, and declaration/source-placement policy at file level.
- Add that `NexusTK/ui/controls/TextEditPane.cpp` should eventually emit:
  - class declaration through [UID:0000EO],
  - exact class method bodies through child by-memory pages,
  - file-local callbacks `TextRunMeasureCallback` and `DrawTextRunCallback`,
  - support classes `TextEditObject`, `TextEditScrap`, and `EPFTextEditObject`,
  - module statics `s_styledUnicodeClipboardFormat`, `g_pActiveTextEditPane`, and `s_mouseSelectionAnchor`,
  - exact string literals for styled clipboard format and wildcard/masked-text display.
- Preserve separation from `TextEditControlPane.cpp`, `TextBoxPane.cpp`, `TextFilter.cpp`, `CopyWindow.cpp`, ScrollVolume/ScrollNewGroup source, `Encoder.cpp`, and `GrafPort.cpp`.

For `by-memory/0x0058dce0-0x0058e132.TextEditPaneConstructor.md`:

- Add the generated-source/callsite signature lead: allocator/`this` plus twelve explicit source arguments. State exact original parameter spellings are still not proven.
- Correct or nuance "thirteen parameters after this" if a later disassembly/stack-cleanup check confirms twelve explicit arguments; current generated call sites strongly favor twelve explicit source args.
- Add `m_textStorage`, `m_lineTable`, `m_styleRuns`, and `m_formatRecords` field names with confidence.

For `by-memory/0x0058e140-0x0058e228.TextEditPaneDestructor.md`:

- Add field names for four list/table releases.
- Add that destructor C++ is closer to readiness than constructor because it is ordinary cleanup once member names are accepted.

For `by-memory/0x0058e380-0x0058e3d7.TextEditPaneCopyWideText.md`:

- Add first-draft C++ recommendation using `m_textStorage`; score can likely remain `86/90` or increase modestly only after code is entered.

For `by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md` and [UID:0000UM] item:

- Use field names `m_textStorage`, `m_lineTable`, `m_styleRuns`, `m_formatRecords`.
- Clarify that the integer marker is written through `Encoder::WriteInt`; `0x6b6f6e67` appears as the source marker value, with byte order governed by Encoder state.

For `by-memory/0x00591d60-0x00593c20.TextEditPaneFormattingRunsAndMeasureAdapters.md` and `by-memory/0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers.md`:

- Preserve file-level owner/emitter [UID:0000ON] because the aggregates include file-local callbacks/raw adapters, not pure class methods.
- Add the field names and source-facing helper-name recommendations from this report.
- Keep final C++ blank until exact child splits/signatures are ready.

For `by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md` and `by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md`:

- Keep file-local callback placement.
- Add callback-state struct naming direction: `TextRunMeasureState` and `TextRunDrawState` are good descriptive names, but not original-proof.

For `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` and `by-memory/0x00593f00-0x0059403b.DrawTextRunCallbackThiscallRaw.md`:

- Preserve route-negative/no-direct-start-ref evidence.
- Do not emit handwritten C++ until raw/adaptor policy is decided.

For support-object docs:

- `by-class/TextEditObject.md`: add source-field names `m_state`, `m_ownerOrType`, `m_payloadA`, `m_payloadB` as descriptive, and preserve `TextEditPane.cpp` placement.
- `by-class/TextEditScrap.md`: keep `m_textLength`, `m_textBuffer`, `m_payloadSize`, `m_payloadBuffer`; this is the most source-ready support class.
- `by-class/EPFTextEditObject.md`: keep `m_frame`/embedded frame storage at `+0x14` descriptive; do not overclaim original type.
- [UID:0002XX] audit map should not appear in coverage as reconstructable.

For global/static support docs:

- `by-global/g_pActiveTextEditPane.md`: recommend first-draft declaration later as `TextEditPane *g_pActiveTextEditPane = 0;`; keep alias rejection.
- `by-memory/0x0069bdfc-0x0069be00.TextEditStyledUnicodeClipboardFormat.md`: recommend `static unsigned int s_styledUnicodeClipboardFormat = 0xffffffff;` as source direction, pending exact name.
- `by-memory/0x0069be04-0x0069be06.TextEditMouseSelectionAnchorScratch.md`: recommend `static short s_mouseSelectionAnchor = -1;` as source direction, pending exact name.

## Coverage Text

Do not edit coverage reports during the report-only pass. Recommended supervisor-owned replacement rows:

### `by-class/-coverage-report.md`

Replace the [UID:0000EO] row with:

```markdown
- [UID:0000EO][TextEditPane](by-class/TextEditPane.md) : reconstructable : 89% : strong : B005 2026-06-19 source-quality pass upgrades the class to declaration-level C++ readiness while preserving owner/emitter [UID:0000ON]; resolves the main field map as `m_textStorage` `+0x134`, inferred `m_lineTable` `+0x138`, inferred `m_styleRuns` `+0x13c`, inferred `m_formatRecords` `+0x140`, selection/caret endpoints `+0x144/+0x146`, editor flags `+0x15c`, mouse mode `+0x167`, dirty byte `+0x169`, masked-text byte `+0x16a`, delete indexes `+0x16c/+0x16e`, and provisional input/line/format state through `+0x173`; records source-facing method/helper names for constructor/destructor/copy/serialization/draw/key/mouse/invalidation, text-run callbacks, word-boundary/autoscroll/navigation helpers, and support objects; rejects stale FittingRoom/RankingEvent/scrollbar/CopyWindow/Encoder owner pollution; distinguishes class-owned methods from file-local callbacks/raw adapters/support objects; confirms active-editor and clipboard-format globals as TextEditPane module state; and recommends declaration-only C++ with `[[CHILDREN]]` while leaving method-body C++ to exact child pages pending callback-state/table-layout/signature finalization.
```

### `by-file/-coverage-report.md`

If the file page is updated, replace the [UID:0000ON] row with:

```markdown
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md) : reconstructable : 90% : strong : B005 2026-06-19 source-quality pass confirms `NexusTK/ui/controls/TextEditPane.cpp` as the implementation module for `TextEditPane`, file-local text-run callbacks, `TextEditObject`/`TextEditScrap`/`EPFTextEditObject`, active-editor and styled-clipboard globals, wildcard/styled clipboard string literals, and exact vtable children; preserves `TextEditControlPane`, `TextBoxPane`, `TextFilter`, `CopyWindow`, Scrollbar/ScrollVolume/ScrollNewGroup, Encoder/BinaryCodec, GrafPort, FittingRoom, and RankingEvent generated labels as dependencies or rejected owners; records field names for text, line, style-run, and format-record tables; and keeps split-before-body-C++ policy for large formatting/input aggregates while allowing declaration-ready class output through [UID:0000EO].
```

### `by-memory/-coverage-report.md`

Supervisor-owned sync rows that are relevant to this class pass and currently stale or incomplete:

```markdown
    - [UID:0001GJ][0x0055d960-0x005654ec.TextEditPaneScrollbarVariants](by-memory/0x0055d960-0x005654ec.TextEditPaneScrollbarVariants.md) 0x0055d960-0x005654ec | mixed aggregate | TextEditPaneScrollbarVariants : ignored : 89% : very strong : Non-emitting mixed scrollbar corridor map; current docs reject stale TextEditPane ownership for ScrollVolumePane and ScrollNewGroup helper bodies, preserve exact child ownership through ScrollPane/ScrollablePane/ScrollVolumePane/feature-scrollbar pages, and treat this range as an audit/index rather than a TextEditPane source unit.
    - [UID:0001JM][0x0058dce0-0x00591300.TextEditPaneCoreBeforeTextBoxPane](by-memory/0x0058dce0-0x00591300.TextEditPaneCoreBeforeTextBoxPane.md) : reconstructable : 86% : very strong : TextEditPane core aggregate before the TextBoxPane island with exact constructor/destructor/copy/serialization/draw/key/mouse/final-invalidation children, raw helper pockets, active-editor global, vtable installs, method-family inventory, and `0x00591740-0x005917c9` final helper endpoint; broad aggregate C++ remains blank because exact child pages should emit methods.
        - [UID:0002O9][0x0058e380-0x0058e3d7.TextEditPaneCopyWideText](by-memory/0x0058e380-0x0058e3d7.TextEditPaneCopyWideText.md) 0x0058e380-0x0058e3d7 | method | TextEditPaneCopyWideText : reconstructable : 86% : very strong : Exact bounded UTF-16 copy helper attached to TextEditPane; current PE/doc evidence confirms seven callers, only setup/copy callees, `m_textStorage` `+0x134`, clamp against storage `+0x0c`, virtual text pointer at vtable `+0x10`, `count * 2` copy, output terminator, and `0x0058e3d7-0x0058e3e0` padding.
    - [UID:0001JN][0x0058e490-0x0058e691.TextEditPaneSerialization](by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md) 0x0058e490-0x0058e691 | function | TextEditPaneSerialization : reconstructable : 86% : very strong : TextEditPane state serializer reached through raw TextEditControlPane forwarder `0x00498c40-0x00498c4f`; reads `m_textStorage`, inferred line/style/format tables at `+0x138/+0x13c/+0x140`, writes raw text payload, delimiter byte, marker `0x6b6f6e67`, and three length-prefixed table payloads through Encoder, then returns exact heap copy and output size.
    - [UID:0001JQ][0x00593c20-0x00593ce4.TextRunMeasureCallback](by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md) : reconstructable : 85% : strong : File-local TextEditPane text-run measurement callback; exact IDA extent, four address-taking refs, no direct callers, GrafPort text-width/trim callees, sibling draw callback, raw-neighbor/padding boundaries, stale FittingRoom rejection, and source placement under `TextEditPane.cpp` are documented; final C++ remains blank pending callback-state field names.
    - [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md) : reconstructable : 86% : strong : File-local TextEditPane draw callback with exact function extent, two address-taking iterator refs at `0x005908e6`/`0x0059168c`, draw-state/clip/style-object/lower-renderer callees, PE pointer scan, raw-neighbor padding, stale FittingRoom rejection, and final C++ blank pending callback-state/style-payload names.
    - [UID:0001JS][0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers](by-memory/0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers.md) 0x00594040-0x00594e60 | method/raw-helper cluster | TextEditPaneInputNavigationWrapAndTextRunHelpers : reconstructable : 86% : strong : TextEditPane character input, delete, cursor/word movement, switch-table dispatch, lower text-run renderer, wrap helpers, `FindWordBoundary`, autoscroll, and raw pre-support helper cluster; B001/B005 evidence confirms switch table `0x00594618-0x00594658`, renderer `0x005946b0`, raw helper `0x00594e20`, exact support-object boundary `0x00594e60`, owner/emitter [UID:0000ON], and final-C++ blockers for cursor/selection fields, wrap-state layout, and raw helper signatures.
        - [UID:0002XX][0x00594e60-0x00595760.TextEditSupportObjects](by-memory/0x00594e60-0x00595760.TextEditSupportObjects.md) 0x00594e60-0x00595760 | mixed audit map | TextEditSupportObjects : ignored : 87% : very strong : Non-reconstructable audit map for the historical support-object range; exact source-bearing children [UID:0003M7] and [UID:0003M8] route to TextEditPane, while embedded [UID:0002RV] `TextBoxPaneConstructor` owns `0x00595390-0x005954b3`, so this broad range must not emit source or carry a single owner.
            - [UID:0003M7][0x00594e60-0x00595389.TextEditSupportObjectsBeforeTextBoxPane](by-memory/0x00594e60-0x00595389.TextEditSupportObjectsBeforeTextBoxPane.md) 0x00594e60-0x00595389 | class-method island | TextEditSupportObjectsBeforeTextBoxPane : reconstructable : 85% : strong : Exact TextEditPane support-object island for `TextEditObject` raw constructor/accessors/no-op hooks and early `TextEditScrap` constructor/clear/set/get/convert helpers before seven `0xcc` bytes and the separate TextBoxPane constructor; owned/emitted by [UID:0000ON] with final C++ blank pending raw-pocket signatures and field names.
            - [UID:0003M8][0x005954c0-0x00595760.TextEditSupportObjectsAfterTextBoxPane](by-memory/0x005954c0-0x00595760.TextEditSupportObjectsAfterTextBoxPane.md) 0x005954c0-0x00595760 | class-method island | TextEditSupportObjectsAfterTextBoxPane : reconstructable : 86% : strong : Exact TextEditPane support-object island after TextBoxPane for `EPFTextEditObject` constructor/virtual helper/destructor plus TextEditObject/TextEditScrap scalar deleting destructors and alignment before TextFilter; owned/emitted by [UID:0000ON] with final C++ blank pending frame/helper type names.
    - [UID:0002AQ][0x0069bdf8-0x0069be08.TerminalAndTextEditGlobals](by-memory/0x0069bdf8-0x0069be08.TerminalAndTextEditGlobals.md) 0x0069bdf8-0x0069be08 | mixed global-data cluster | TerminalAndTextEditGlobals : ignored : 86% : strong : Mixed terminal/text-edit global-data audit map now split into exact children for styled clipboard format, active TextEditPane pointer, mouse-selection anchor scratch, and padding; exact children carry ownership and this broad cluster should not emit one source item.
        - [UID:000301][0x0069bdfc-0x0069be00.TextEditStyledUnicodeClipboardFormat](by-memory/0x0069bdfc-0x0069be00.TextEditStyledUnicodeClipboardFormat.md) 0x0069bdfc-0x0069be00 | global-data | TextEditStyledUnicodeClipboardFormat : reconstructable : 86% : very strong : TextEditPane module static cached Windows clipboard format id for `Nexon.StyledUnicodeText`, initialized from image value `0xffffffff`, registered by the constructor, and consumed by key/paste helpers through `IsClipboardFormatAvailable`/`GetClipboardData`; source name recommended as `s_styledUnicodeClipboardFormat`.
        - [UID:000302][0x0069be00-0x0069be04.g_pActiveTextEditPane](by-memory/0x0069be00-0x0069be04.g_pActiveTextEditPane.md) 0x0069be00-0x0069be04 | global-data | g_pActiveTextEditPane : reconstructable : 86% : strong : Exact active `TextEditPane*` storage owned by [UID:0000Q7], written by TextEditPane constructor/destructor and consumed by CopyWindow/reconnect helpers; generated `g_pCopyWindowTextEditPane` is a narrow alias only.
        - [UID:000303][0x0069be04-0x0069be06.TextEditMouseSelectionAnchorScratch](by-memory/0x0069be04-0x0069be06.TextEditMouseSelectionAnchorScratch.md) 0x0069be04-0x0069be06 | global-data | TextEditMouseSelectionAnchorScratch : reconstructable : 85% : very strong : TextEditPane module static mouse-selection anchor scratch word used only by `OnMouseEvent` selection expansion and drag paths; source name recommended as `s_mouseSelectionAnchor`.
```

## Validator Needs

No validator was run because this was a report-only pass and no by-* docs were edited. Expected implementation validators, from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0000EO-TextEditPane-class-source-quality-removed.md](0000EO-TextEditPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Run additional validators for any callback/raw/support-object/global docs actually touched during implementation.

## IDA Rename / Type / Comment Recommendations

Names to apply in IDA/database or equivalent source map when safe:

- `dword_69BE00` -> `g_pActiveTextEditPane`
- `format` at `0x0069bdfc` -> `s_styledUnicodeClipboardFormat` or `g_textEditStyledUnicodeClipboardFormat`
- `word_69BE04` -> `s_textEditMouseSelectionAnchor`
- `sub_58E380` -> `TextEditPane::CopyWideText`
- `sub_58E490` -> `TextEditPane::EncodeState` or file-local `EncodeTextEditState`
- `sub_590810` -> `TextEditPane::OnDraw`
- `sub_5909F0` -> `TextEditPane::OnKeyEvent`
- `sub_590DE0` -> `TextEditPane::OnMouseEvent`
- `sub_591740` -> `TextEditPane::InvalidateTextRegion`
- `sub_593C20` -> `TextRunMeasureCallback`
- `sub_593DB0` -> `DrawTextRunCallback`
- Comment `0x00593b20`: "Raw TextEditPane wildcard/masked-text measure helper; no IDA function/start refs; not FittingRoom."
- Comment `0x00593cf0`: "Raw TextEditPane measure callback/adaptor variant; no direct start refs."
- Comment `0x00593f00`: "Raw TextEditPane draw callback/adaptor variant; no direct start refs."
- Comment `0x00594e20`: "Raw TextEditPane pre-support helper before TextEditObject; no direct start refs."
- Define provisional struct/class fields on `TextEditPane`: `m_textStorage`, `m_lineTable`, `m_styleRuns`, `m_formatRecords`, `m_selectionStart`, `m_selectionEnd`, `m_editorFlags`, `m_mouseMode`, `m_dirty`, `m_maskedText`, `m_deleteForwardIndex`, `m_deleteBackwardIndex`.

## Open Questions With Attempted Resolution

- Exact original constructor parameter names: best inference is the twelve-argument generated/source-call signature above. Current by-doc text saying "thirteen parameters after this" should be rechecked against stack cleanup; generated call sites strongly indicate "this plus twelve explicit args." This affects constructor child C++, not class ownership.
- `+0x138/+0x13c/+0x140` exact source type names: resolved to high-probability `lineTable`, `styleRuns`, and `formatRecords` from constructor allocation sizes, formatting helpers, and serialization sizes. The exact "style" versus "format" original spelling remains uncertain, so confidence stays below 90+ final-audit levels.
- Callback state structs: not enough evidence without a dedicated callback-body pass. Recommended descriptive names `TextRunMeasureState` and `TextRunDrawState` only.
- Raw variant source policy at `0x00593cf0` and `0x00593f00`: no direct start refs and no modeled functions mean no safe handwritten C++ yet. They are real TextEditPane raw bodies and not FittingRoom; whether they should be separate file-local adapters, compiler-retained variants, or folded into callback helpers remains open.
- Broad aggregate C++: rejected. `0001JP`, `0001JS`, and support-object islands need exact child splits or method-specific pages before body emission.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B005/research/0000EO-TextEditPane-class-source-quality.md`
- Modified: none outside the B005 research folder.
- Coverage edited: none.
- Leases used: none; research report path is inside the assigned B005 folder and does not require a lease.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0000EO-TextEditPane-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:30","uid":"0000EO"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000EO-TextEditPane-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/0000EO-TextEditPane-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000EO"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
