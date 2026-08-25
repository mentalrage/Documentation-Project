** TARGET-REPORT-UID:0001IG **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B003-goal2-soundstatuspane-source-quality-0001IG-20260617

## Scope And Inputs

Assignment target: [UID:0001IG] `by-memory/0x0057bf70-0x0057c2cf.SoundStatusPane.md`, current score `82/88`, owner/emitter [UID:0000DJ] `SoundStatusPane`.

This was handled as report-only B-agent work. I did not edit by-* docs, generated reports, source files, generated source, the IDA database, or `by-memory/-coverage-report.md`.

Primary and support docs checked:

- [UID:0001IG] `by-memory/0x0057bf70-0x0057c2cf.SoundStatusPane.md`
- [UID:0000DJ] `by-class/SoundStatusPane.md`
- [UID:0000NX] `by-file/SoundStatusPane.md`
- [UID:0000SB] `by-global/g_pSoundStatusPane.md`
- [UID:0002WA] `by-memory/0x0069b4d4-0x0069b4d8.g_pSoundStatusPane.md`
- [UID:0000NV]/[UID:0000DG] `SoundManager`
- [UID:0000RM]/[UID:0000LD] `g_pMidiPlayer` / `MidiPlayer`
- [UID:0001Q8] `client_audio`
- relevant screen-dimension, config, Pane/EventDispatcher, vtable/read-only data, main UI init, and neighboring SoundPathVector/SpellInventory docs.

Existing B-report search:

- `rg` over B-agent research and validation logs found no prior dedicated source-quality report for [UID:0001IG]. Existing hits were validation/autogen logs plus an unrelated B001 rdata/source-routing note. I treated existing docs as evidence to revalidate, not authority.

## Recommendation Summary

- Raise [UID:0001IG] from `82/88` to `88/91`.
- Keep `RECONSTRUCTABLE: TRUE`.
- Keep canonical owner and emitter as [UID:0000DJ] `SoundStatusPane`.
- Keep source placement under `NexusTK/ui/panels/SoundStatusPane.cpp`.
- Do not split this target. The constructor, cleanup body, hotkey handler, caption paint/refresh method, singleton-clear helper, adjustor thunks, and scalar deleting destructor are a coherent SoundStatusPane method island. The small helper/thunk subranges are compiler support for this class, not independent source-owned features.
- Do not populate the formal `RECONSTRUCTION_CPP` block yet. The target clears the score gate after this audit, but the formal code block should remain blank because exact shared Pane/EventHandler virtual names, event field type names, MIDI helper names, and compiler-artifact handling are not source-final enough for a safe accepted C++ body.

Before/after recommendations:

| UID | Current | Recommended | Notes |
| --- | --- | --- | --- |
| 0001IG | `82/88` | `88/91` | Open source-shape questions are resolved or bounded; formal C++ held. |
| 0000DJ | `86/86` | `88/89` | Class open questions should be replaced with resolved source-quality notes. |
| 0000NX | `86/86` | `88/88` | File/source placement stands; generated-output caveats should be refreshed. |
| 0000SB | `86/90` | no score change required | Replace stale initialization wording; exact child already proves zero-filled storage. |
| 0002WA | `88/93` | no doc-score change required | Coverage row is stale and should be synchronized. |

## Target Source Shape

Validated range map:

- `0x0057bf70-0x0057c04d`: `SoundStatusPane::SoundStatusPane()`.
- `0x0057c050-0x0057c079`: non-deleting cleanup/destructor body for `SoundStatusPane`.
- `0x0057c080-0x0057c15b`: key-event/hotkey handler for sound and MIDI/music toggles.
- `0x0057c160-0x0057c23e`: caption paint/refresh method that formats and draws `Music On/Off` plus `Sound On/Off`.
- `0x0057c240-0x0057c24b`: compiler cleanup helper that clears `g_pSoundStatusPane`, referenced by the constructor EH/unwind path.
- `0x0057c24b-0x0057c256`: adjustor thunk subtracting `0xa0` and tail-jumping to the scalar deleting destructor.
- `0x0057c256-0x0057c261`: adjustor thunk subtracting `0xa4` and tail-jumping to the scalar deleting destructor.
- `0x0057c270-0x0057c2cf`: scalar deleting destructor.

Range/padding:

- Preceding ignored padding remains `0x0057bf6e-0x0057bf70`.
- Target range remains `0x0057bf70-0x0057c2cf`.
- Trailing ignored padding remains `0x0057c2cf-0x0057c2d0`.
- Successor function starts at `0x0057c2d0` and belongs to the SpellInventoryPane boundary, not SoundStatusPane.

No further split is needed. Splitting the adjustor thunks or constructor-unwind clear helper would improve exactness only cosmetically while adding source-file clutter; all of those subranges are compiler-owned artifacts for the same `SoundStatusPane` source class.

## Evidence Checked

Live IDA/MCP evidence:

- `lookup_funcs` confirmed function starts and sizes at `0x0057bf70`, `0x0057c050`, `0x0057c080`, `0x0057c160`, `0x0057c240`, `0x0057c24b`, `0x0057c256`, `0x0057c270`, and successor `0x0057c2d0`.
- Constructor xrefs are from `InitializeMainUiGraph` at `0x004f8460` and `0x004f89c7`, matching both main UI layout branches.
- `g_pSoundStatusPane` has six live refs: UI teardown read at `0x005048e6`, constructor publish/fallback at `0x0057bfc0` and `0x0057bfc7`, cleanup clear at `0x0057c06a`, constructor-unwind clear at `0x0057c240`, and scalar destructor clear at `0x0057c290`.
- Primary/secondary/tertiary vtable refs at `0x0062cef4`, `0x0062cf40`, and `0x0062cf70` match constructor install, cleanup reinstall, destructor reinstall, and data xrefs for the virtual methods/thunks.
- `0x0057c240` has a code xref from the constructor EH/unwind support region around `0x00608661`; it is not an ordinary source caller.
- The hotkey handler uses event byte/word fields at `+0x04`, `+0x08`, and `+0x10a`.
- The caption refresh method references wide literals `Music On`, `Music Off`, `Sound On`, `Sound Off`, and `%s/%s`.
- Decompilation and disassembly both show the constructor-derived bounds fields at `+0xf8`, `+0xfc`, `+0x100`, and `+0x104`; the hotkey handler later passes that rectangle to a Pane invalidation/repaint vcall.

Doc evidence validated:

- `PaneLayout` and Pane support docs show derived pane fields begin at `+0xf8`, with EventHandler-style secondary views at `+0xa0` and `+0xa4`. This resolves the inherited-base question as a common Pane-derived object, not a `TextButtonExControlPane` subclass.
- SoundManager docs validate `0x0057a3d0` as music/playback state, `0x0057a3e0`/`0x0057a400` as music mute/unmute, and `0x0057a750`/`0x0057a760`/`0x0057a770` as sound-effect state/enable/disable helpers.
- MidiPlayer docs validate `g_pMidiPlayer` ownership outside SoundStatusPane and show the SoundStatusPane method is a consumer of MIDI playback helpers, not their owner.
- The exact singleton child [UID:0002WA] already records current zero-filled bytes and stronger xref evidence than the stale coverage row.

## Heuristic / Inference Reanalysis And Validation

Best defensible source-facing names and signatures:

- Constructor: `SoundStatusPane::SoundStatusPane()`. Evidence: direct `InitializeMainUiGraph` calls, Pane constructor call, vtable installation, screen-relative bounds initialization, and singleton publish.
- Non-deleting cleanup/destructor body at `0x0057c050`: best source role is `SoundStatusPane::~SoundStatusPane()` body or compiler-emitted non-deleting destructor body. It reinstalls vtables, clears the singleton, and tails into Pane cleanup. It has no direct normal xref, so docs should not present it as an independently called source helper.
- Hotkey handler at `0x0057c080`: best source role is the SoundStatusPane key-event handler, with descriptive name `HandleSoundHotkeys` or shared-slot name `OnKeyEvent` once the EventHandler vtable pass standardizes slot names. Signature direction is `bool SoundStatusPane::HandleSoundHotkeys(const UiEvent *event)` or equivalent secondary-view `this` adjusted method. It returns handled/not-handled.
- Caption method at `0x0057c160`: best source role is `RefreshSoundStatusText` / caption paint method. It is vtable-dispatched from the primary Pane view and draws the current `Music On/Off` and `Sound On/Off` caption. Exact shared slot name may be `OnPaint`/`Draw` in a later Pane pass, but the SoundStatusPane-specific role is settled.
- Singleton clear helper at `0x0057c240`: best label is `ClearSoundStatusPaneSingleton`, but it should be documented as compiler cleanup support for constructor failure/unwind, not a public source method.
- `0x0057c24b` and `0x0057c256`: compiler adjustor thunks for secondary views at `+0xa0` and `+0xa4`. Do not model these as handwritten source methods.
- `0x0057c270`: scalar deleting destructor. Do not hand-write it in final source; it is regenerated from the destructor and delete operator path.

Best defensible fields and globals:

- `this + 0xf8`, `+0xfc`, `+0x100`, `+0x104`: SoundStatusPane-owned status/invalidation bounds, best source name `m_statusBounds` or `m_statusRect` with fields left, right, top, bottom. Evidence: constructor computes them from `g_screenWidth - 354`, `left + 114`, `g_screenHeight - 11`, `top + 12`; hotkey handler uses the same rectangle for repaint/invalidation after state changes.
- `g_pConfig + 0x28de48`: sound-effect enabled byte. Evidence: only the sound-effect toggle branch writes it beside `SoundManager::EnableSoundEffects`/`DisableSoundEffects`. Best source name is `soundEffectsEnabled` or `m_soundEffectsEnabled`.
- `event + 0x04`: event type/kind; value `8` is the key-event discriminator in related pane handlers.
- `event + 0x08`: key/character byte before `std::ctype<char>::do_narrow`.
- `event + 0x10a`: keyboard modifier/filter byte. It must remain `modifierFlags` or equivalent. Existing evidence proves bit/value `2` participates in the `M` hotkey, but does not safely prove a final user-facing modifier name such as Ctrl, Alt, or Shift.
- `g_pSoundStatusPane`: exact singleton slot owned by SoundStatusPane; current image bytes are zero-filled, with constructor publish and cleanup/destructor clear refs.

Constructor stack `RectBounds` reanalysis:

- The constructor calls `sub_4B7C50` on a stack local after writing the object fields. Disassembly shows no later read or escaping address for that local in the constructor. The best inference is a dead/local mirror of the same rectangle or a decompiler-visible temporary retained for EH/source shape, not a hidden state transfer. This no longer caps completion. The live state is the four object fields and later repaint use.

Generated/compiler-name reanalysis:

- Generated output that emits only the constructor, hotkey handler, caption refresh, and scalar deleting destructor is incomplete for documentation purposes because it omits the non-deleting cleanup and singleton-clear helper and mishandles adjustor thunks. That is generated-output pollution, not evidence that those ranges are unowned.
- The decompiler/base-name drift toward `TextButtonExControlPane` is rejected. Pane docs and layout offsets prove SoundStatusPane is a Pane-derived class with EventHandler subobject views, while `TextButtonExControlPane` appears because shared Pane cleanup/base code is reused across UI controls.

Rejected alternatives:

- Owner `SoundManager`: rejected because SoundStatusPane only calls SoundManager state/toggle helpers and updates UI; audio state storage and playback implementation remain in SoundManager.
- Owner `MidiPlayer`: rejected because SoundStatusPane only drives MIDI playback helpers through `g_pMidiPlayer`; the MIDI object is documented in its own file/global pages.
- Owner `MusicControlDialog`: rejected because this target is the always-present status pane, initialized from `InitializeMainUiGraph`, with its own singleton and vtables.
- Owner `EventDispatcher` or shared Pane file: rejected because only the event record shape and base vtable slots are shared; the state changes, caption text, singleton, and bounds are SoundStatusPane-specific.
- Splitting compiler thunks/clear helper into exact child pages: rejected for this pass because liveness and ownership are already proven and the helpers are class-local compiler support. A split would not change source placement or C++ readiness.
- Naming `event + 0x10a` as a specific physical modifier key: rejected. Cross-pane evidence proves the byte is a modifier/filter field, but not the exact original enum/bit names.

Remaining blockers and impact:

- Exact EventHandler virtual slot names are not source-final. Impact: blocks formal C++ only; ownership, source placement, and score are not blocked.
- MIDI helper names at `0x005260a0`, `0x005260b0`, and `0x005260d0` are directionally known as playback state/start/stop style helpers but are not source-final in current support docs. Impact: blocks formal C++ exactness only.
- The exact original member name for the status rectangle is not recovered. Impact: docs can use `m_statusBounds`/`m_statusRect` as a high-probability descriptive name; this does not cap completion below 85.
- The constructor stack `RectBounds` local is source-shaped but not live state. Impact: should be documented as a non-authoritative local mirror/dead temporary and should not force a split or lower score.

Score/source-placement/final-C++ impact:

- These validations raise the target above the 85/85 gate because the previous open base, field, helper-liveness, singleton lifecycle, range, and generated-output questions are either solved or explicitly bounded.
- Source placement remains `NexusTK/ui/panels/SoundStatusPane.cpp`; no evidence supports moving this to SoundManager, MidiPlayer, EventDispatcher, or a dialog-specific file.
- Formal C++ remains unsafe despite the higher score because source-quality names and compiler artifact policy still need a shared Pane/EventHandler declaration pass.

## Recommended Target-Doc Changes

For [UID:0001IG], update metadata:

```text
*** COMPLETION:88
*** CONFIDENCE:91
*** CANONICAL_OWNER:0000DJ
*** EMITTER_UIDS:0000DJ
*** RECONSTRUCTABLE:TRUE
```

Keep the formal `RECONSTRUCTION_CPP CODE` block blank.

Replace the target's open-question/caveat language with:

```markdown
## Source-Quality Notes

- The inherited-base question is resolved to the common Pane layout with EventHandler secondary views at `+0xa0` and `+0xa4`; do not model this class as deriving from `TextButtonExControlPane`.
- The derived SoundStatusPane bounds live at `+0xf8/+0xfc/+0x100/+0x104` and should be documented as `m_statusBounds` or `m_statusRect` until the class header naming pass fixes exact member names.
- The constructor stack `RectBounds` construction mirrors the same coordinates but has no proven escaped use; it is not hidden pane state and should not cap completion.
- `0x0057c240` is a constructor-unwind singleton-clear helper. `0x0057c24b` and `0x0057c256` are compiler adjustor thunks. `0x0057c270` is the scalar deleting destructor. These are class-local compiler artifacts, not standalone source helpers.
- The key-event handler uses event kind `+0x04 == 8`, key/character byte `+0x08`, and modifier/filter byte `+0x10a`. Keep `+0x10a` named generically as modifier flags until the shared event enum is recovered.
- The generated output is incomplete for this island because it omits the non-deleting cleanup and constructor-unwind singleton clear helper and does not model the adjustor thunks as compiler artifacts.
- Formal C++ should remain blank until shared Pane/EventHandler virtual slot names, event field names, and MIDI helper names are source-final.
```

Recommended method/body wording:

```markdown
Source-facing shape:

- `SoundStatusPane::SoundStatusPane()` initializes the Pane base, installs the SoundStatusPane primary and EventHandler subobject vtables, publishes `g_pSoundStatusPane`, computes the screen-relative status rectangle, and stores it in the four derived bounds fields.
- `SoundStatusPane::~SoundStatusPane()` / non-deleting cleanup clears `g_pSoundStatusPane` and calls Pane cleanup.
- The key-event handler toggles sound effects for lowercase `m` with modifier value `2`, writes `g_pConfig + 0x28de48`, toggles MIDI/music for uppercase `M` when modifier bit `2` is set, and invalidates the status rectangle.
- The caption refresh/paint method draws `Music On/Off` and `Sound On/Off` using the current `SoundManager` state.
```

## Support Docs To Update

[UID:0000DJ] `by-class/SoundStatusPane.md`:

- Recommended score: `88/89`.
- Replace the existing open questions with:

```markdown
## Source-Quality Notes

- The class is a Pane-derived UI pane with EventHandler secondary views at `+0xa0` and `+0xa4`; `TextButtonExControlPane` is decompiler/base-name pollution from shared Pane cleanup and should not be used as the declared base.
- The vtable slots and adjustor thunks should remain documented as compiler/runtime artifacts. Source should declare the class methods and let the compiler regenerate thunks and scalar deleting destructor support.
- The derived rectangle at `+0xf8/+0xfc/+0x100/+0x104` is the SoundStatusPane status/invalidation bounds. A source-facing name such as `m_statusBounds` or `m_statusRect` is defensible until exact header names are recovered.
- The constructor stack rectangle is not proven live state; object fields and the later repaint/invalidation call are the authoritative state.
- Formal source should wait for the shared Pane/EventHandler virtual naming pass, but class ownership and source placement are no longer open.
```

[UID:0000NX] `by-file/SoundStatusPane.md`:

- Recommended score: `88/88`.
- Keep proposed path/source placement as `NexusTK/ui/panels/SoundStatusPane.cpp`.
- Replace generated-output caveats with:

```markdown
## Generated-Output Caveat

Current generated output is useful only as a partial lead. It emits the constructor, key-event handler, caption refresh/paint method, and scalar deleting destructor, but omits the non-deleting cleanup and constructor-unwind singleton clear helper and does not model secondary adjustor thunks as compiler artifacts. The accepted source shape should be driven by the class docs and [UID:0001IG], not by generated output alone.
```

[UID:0000SB] `by-global/g_pSoundStatusPane.md`:

- No score change required.
- Replace stale initialization wording with:

```markdown
`0x0069b4d4` is the exact four-byte `SoundStatusPane*` singleton slot. Current live IDA bytes are zero-filled; older `ff ff ff ff` wording was stale. The slot is published by the SoundStatusPane constructor, cleared by cleanup/destructor and constructor-unwind support, and read by UI teardown.
```

[UID:0002WA] `by-memory/0x0069b4d4-0x0069b4d8.g_pSoundStatusPane.md`:

- No body-score change required. The body is already stronger than the coverage row; update coverage only.

## Supervisor-Owned Coverage Rows

Do not edit `by-memory/-coverage-report.md` as B003. These are exact replacement rows for supervisor application.

Replace the existing [UID:0001IG] row in the `0x0057bf70` area, between ignored padding `0x0057bf6e-0x0057bf70` and ignored padding `0x0057c2cf-0x0057c2d0`, with:

```markdown
    - [UID:0001IG][0x0057bf70-0x0057c2cf.SoundStatusPane](by-memory/0x0057bf70-0x0057c2cf.SoundStatusPane.md) 0x0057bf70-0x0057c2cf | class method island | SoundStatusPane : reconstructable : 88% : very strong : B003 2026-06-17 source-quality audit validates the exact SoundStatusPane island, constructor callers at 0x004f8460/0x004f89c7, Pane-derived layout with EventHandler subobjects at +0xa0/+0xa4, bounds fields at +0xf8/+0xfc/+0x100/+0x104, vtable slots for caption refresh and key handling, event fields +0x04/+0x08/+0x10a, g_pConfig +0x28de48 sound-effect byte, SoundManager/MidiPlayer consumer roles, g_pSoundStatusPane lifecycle refs, constructor-unwind clear helper, compiler adjustor thunks, padding boundaries, source placement under SoundStatusPane.cpp, and formal C++ held because shared Pane/EventHandler names and compiler-artifact emission are not source-final.
```

Replace the existing [UID:0002WA] row in the `.data` globals section with:

```markdown
        - [UID:0002WA][0x0069b4d4-0x0069b4d8.g_pSoundStatusPane](by-memory/0x0069b4d4-0x0069b4d8.g_pSoundStatusPane.md) 0x0069b4d4-0x0069b4d8 | global pointer | g_pSoundStatusPane : reconstructable : 88% : very strong : Exact SoundStatusPane singleton slot assigned to [UID:0000SB][g_pSoundStatusPane](by-global/g_pSoundStatusPane.md); current live IDA bytes are zero-filled, slot size is 0x4/4, constructor publish/fallback refs 0x0057bfc0/0x0057bfc7, cleanup/destructor/clear refs 0x0057c06a/0x0057c240/0x0057c290, UI teardown read 0x005048e6, and the parent global/file route clears the 85/85 gate.
```

No insert/delete rows are required for [UID:0001IG]. No split rows are recommended.

## First-Draft C++ Recommendation

Do not populate the formal `RECONSTRUCTION_CPP` block for [UID:0001IG] in this pass.

Reason:

- The target is an aggregate method island containing source-authored methods plus compiler-generated EH cleanup, adjustor thunks, and scalar deleting destructor support. A formal block would either omit covered bytes or hand-code compiler artifacts that should be regenerated from class declarations.
- The shared Pane/EventHandler virtual slot names are not final enough to choose between descriptive names such as `RefreshSoundStatusText`/`HandleSoundHotkeys` and shared source names such as `OnPaint`/`OnKeyEvent`.
- The event structure field at `+0x10a` is proven as modifier/filter state but not source-final as a specific key modifier enum.
- MIDI helper calls are directionally known as playback state/start/stop style helpers, but their exact source names are still owned by MidiPlayer support docs.

This does not prevent the target from being reconstructable or emitting as an indexed/reviewed SoundStatusPane island; it only prevents safe insertion of accepted C++ into the formal block today.

## Validation Commands For Supervisor

Recommended local checks:

> Executable block R001 was removed from this report and preserved verbatim in [0001IG-soundstatuspane-source-quality-removed.md](0001IG-soundstatuspane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Recommended IDA/MCP checks:

- `lookup_funcs` for `0x0057bf70`, `0x0057c050`, `0x0057c080`, `0x0057c160`, `0x0057c240`, `0x0057c24b`, `0x0057c256`, `0x0057c270`, and `0x0057c2d0`.
- `xrefs_to` for the above function starts plus `0x0069b4d4`, `0x0062cef4`, `0x0062cf40`, and `0x0062cf70`.
- `decompile` `0x0057bf70`, `0x0057c050`, `0x0057c080`, `0x0057c160`, and `0x0057c270`.
- `disasm` around constructor EH/unwind support refs near `0x00608650-0x00608666` to confirm the `0x0057c240` clear helper is constructor cleanup support.

## Changed Files, Leases, And Blockers

Changed file:

- `tools/leaser/Agents/Agent-B003/research/0001IG-soundstatuspane-source-quality.md`

Leases used:

- None. This assignment was report-only and no by-* docs were edited.

Blockers:

- No supervisor-blocking research blocker remains. The only held item is formal C++ population, blocked by shared Pane/EventHandler and MidiPlayer naming finalization plus compiler-artifact emission policy.

Next useful follow-up:

- Run a shared Pane/EventHandler virtual-slot naming pass, then revisit [UID:0001IG] for a formal C++ block if the project accepts source-level destructor/thunk omission policy for aggregate islands.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0001IG-soundstatuspane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"0001IG"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001IG-soundstatuspane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0001IG-soundstatuspane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001IG"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
