** TARGET-REPORT-UID:0000Z5 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B002 Research Report: 0000Z5 BrowserPaneAndDialog Source Quality

Assignment: `B002-goal2-browser-pane-and-dialog-source-quality-0000Z5-20260619`  
Target: [UID:0000Z5] `by-memory/0x0046a860-0x0046ad0a.BrowserPaneAndDialog.md`  
Current target score: `COMPLETION:85`, `CONFIDENCE:87`, average `86.0`  
Current target status: `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000HV`, `EMITTER_UIDS:0000HV`, blank C++  
Report path: `tools/leaser/Agents/Agent-B002/research/0000Z5-BrowserPaneAndDialog-source-quality.md`  
Report-only pass: no `by-*` documentation and no `by-memory/-coverage-report.md` edits were made.

## Bottom Line

Do not add aggregate C++ to [UID:0000Z5] as-is.

The range is source-reconstructable in the broad sense, but it is not a single source-owned body. It interleaves BrowserPane-owned methods, BrowserDialog-owned methods, compiler/vtable cleanup material, and padding. The best implementation path is to split the range into exact child pages owned directly by `BrowserPane` and `BrowserDialog`, then convert [UID:0000Z5] into a non-emitting split/index container. If the implementation callback is not allowed to create child docs yet, keep [UID:0000Z5] as the Browser file-root aggregate with blank C++ and update only its prose/coverage row to reflect the source-quality reanalysis.

Most source-ready pieces are `BrowserDialog::NavigateToUrl`, `BrowserPane::OnCommand`, and likely `BrowserPane::OnKeyEvent`. The raw BrowserPane constructor-shaped body at `0x0046a860` must remain a gate until its exact endpoint and source signature are byte-confirmed.

## Mandatory Coverage Row Text

The exact current supervisor-owned row in `by-memory/-coverage-report.md` is:

```markdown
    - [UID:0000Z5][0x0046a860-0x0046ad0a.BrowserPaneAndDialog](by-memory/0x0046a860-0x0046ad0a.BrowserPaneAndDialog.md) 0x0046a860-0x0046ad0a | class aggregate | BrowserPaneAndDialog : reconstructable : 80% : strong : Browser/BrowserPane aggregate with Browser file parent attachment (`AUTOGEN_PARENT_UID:0000HV`), BrowserPane raw-constructor/no-ref caveat, BrowserDialog constructor/singleton/vtable evidence, adjacent BrowserDialogPaneVirtuals boundary, and blank C++ pending raw-constructor/source-split resolution.
```

If no split is implemented in the immediate callback, replace that row with this exact text:

```markdown
    - [UID:0000Z5][0x0046a860-0x0046ad0a.BrowserPaneAndDialog](by-memory/0x0046a860-0x0046ad0a.BrowserPaneAndDialog.md) 0x0046a860-0x0046ad0a | mixed BrowserPane/BrowserDialog source cluster | BrowserPaneAndDialog : reconstructable : 85% : strong : B002 2026-06-19 source-quality reanalysis keeps the Browser source-root route but treats the range as an overbroad mixed class cluster pending exact child split; it contains the raw no-function/no-xref BrowserPane constructor-shaped body at 0x0046a860 (Wave3 source-map end 0x0046a89a, byte-confirm before split), BrowserPane vtable-reset/base-cleanup wrapper 0x0046a8a0-0x0046a8bf, BrowserDialog::NavigateToUrl 0x0046a8c0-0x0046a8d7, BrowserPane::OnKeyEvent 0x0046a8e0-0x0046a901, BrowserPane::OnCommand 0x0046a910-0x0046aa34 with verified BCdp/BCfl/BCto/0x572 alert dispatch through shared AlertPane/DialogPane helpers, and BrowserDialog constructor 0x0046aa40-0x0046ad0a with g_pBrowserDialog singleton setup and BrowserControlPane child construction; formal aggregate C++ remains blank because source-bearing children should be split to BrowserPane/BrowserDialog direct owners and the raw constructor boundary/signature is still disputed.
```

If a split implementation is approved and exact child docs are created, use this exact replacement row for the parent aggregate after the child rows exist:

```markdown
    - [UID:0000Z5][0x0046a860-0x0046ad0a.BrowserPaneAndDialog](by-memory/0x0046a860-0x0046ad0a.BrowserPaneAndDialog.md) 0x0046a860-0x0046ad0a | reviewed split index | BrowserPaneAndDialog : ignored/non-emitting : 88% : strong : B002 2026-06-19 source-quality split-index container after exact BrowserPane and BrowserDialog child ownership; direct source-bearing children own the raw BrowserPane constructor-shaped body, BrowserPane cleanup/OnKeyEvent/OnCommand methods, BrowserDialog::NavigateToUrl, and BrowserDialog constructor, while this parent remains only the audit boundary tying the Browser source-root cluster together; aggregate C++ is intentionally blank to avoid duplicate mixed-class emission and to preserve the raw constructor boundary/signature caveat.
```

Child row text cannot be fully exact until the documentation allocator assigns UIDs. The implementation checklist below gives the required child inventory and range decisions.

## Current Session Evidence Limits

Current-session IDA MCP verification was attempted against `http://127.0.0.1:13337/mcp` and failed because the local MCP server was not reachable. A local search under `E:\NTK\GhidraBridge` did not locate `NexusTK.exe` or `NexusTK.exe.i64`, so I could not independently disassemble or byte-confirm the target range in this session.

This report therefore treats existing by-memory/by-class documentation, prior live-IDA research reports, generated source maps, and generated C++ as evidence with different weights. Direct prior IDA facts in the target and class docs outrank generated source drafts. Generated source-map facts are used as leads, not as final authority, especially for `0x0046a860`.

## Heuristic / Inference Reanalysis And Validation

### Aggregate Identity

Evidence checked:

- [UID:0000Z5] covers `0x0046a860-0x0046ad0a`.
- The target currently calls the range a `BrowserPaneAndDialog` class aggregate and attaches it to file owner [UID:0000HV] Browser.
- The covered methods belong to at least two semantic classes: [UID:000019] `BrowserPane` and [UID:000017] `BrowserDialog`.
- The adjacent [UID:00020X] range begins at `0x0046ad10` and is already treated as BrowserDialog virtual/destructor/draw/input material, with `0x0046ad0a-0x0046ad10` covered as padding.

Best inference:

- [UID:0000Z5] is a useful audit range but not a clean source-emitting unit.
- Current `CANONICAL_OWNER:0000HV` is acceptable only as a temporary Browser source-root attachment.
- Direct source ownership should be split to class owners:
  - `BrowserPane` for `0x0046a860`, `0x0046a8a0`, `0x0046a8e0`, `0x0046a910`.
  - `BrowserDialog` for `0x0046a8c0`, `0x0046aa40`.

Rejected alternatives:

- Treating [UID:0000Z5] as a single Browser.cpp source body is too broad; it would force unrelated class methods into one emitter marker and hide direct ownership.
- Assigning the whole range to `BrowserPane` is wrong because the `BrowserDialog` constructor and `NavigateToUrl` are inside the range.
- Assigning the whole range to `BrowserDialog` is wrong because several earlier methods are BrowserPane-owned and include the raw BrowserPane constructor-shaped body.

Validation impact:

- The page can stay reconstructable only as a temporary aggregate.
- After exact children exist, the parent should become `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, blank C++, and remain as a reviewed split/index.

### Raw BrowserPane Constructor-Shaped Body At 0x0046a860

Evidence checked:

- Target docs say live IDA found no function containing `0x0046a860`.
- Target docs say previous modeled function is `0x0046a630-0x0046a6ea`; next modeled function is `0x0046a8a0-0x0046a8bf`.
- Target docs report no refs and no pointer hits to `0x0046a860`.
- Target docs describe a raw body that calls the `DialogPane` base constructor with `word_60DB20`, installs BrowserPane vtables `0x006132ec`, `0x00613360`, `0x00613390`, and returns with `retn 8`.
- The target prose currently lists the body as `0x0046a860-0x0046a898`.
- Generated source-map metadata lists `0x0046a860-0x0046a89a` and tags it `boundary_ida_disputed`.

Best inference:

- This is very likely a BrowserPane constructor body, but it is not a clean function-map anchor.
- The `retn 8` strongly implies a two-argument source or ABI-level constructor entry, not the no-argument generated draft currently present in `simroot_v2/browser/Browser.cpp`.
- The best current endpoint inference is `0x0046a89a` if that is the address after the `retn 8`; byte confirmation is required before writing exact split rows.

Rejected alternatives:

- Emitting `BrowserPane::BrowserPane()` with no parameters is not source-quality. It conflicts with `retn 8` and with the target evidence that the raw entry forwards arguments into the base constructor.
- Treating `0x0046a860` as a final clean source-map function is not supported because IDA did not model it and no code/data refs were found.
- Dropping the body as pure padding is not supported because it calls the base constructor, installs class vtables, and returns like a real function body.

Validation impact:

- This body should get a child page only after byte-confirming the exact half-open range, likely `0x0046a860-0x0046a89a`.
- Formal C++ should remain blank for that child unless the implementation pass can prove constructor signature and call route.

### BrowserPane Cleanup Wrapper At 0x0046a8a0

Evidence checked:

- Target covers `0x0046a8a0-0x0046a8bf` as a BrowserPane vtable reset/base cleanup wrapper.
- [UID:000019] `BrowserPane` docs say `sub_46A8A0` restores the same three BrowserPane vtables and calls base cleanup.
- Target docs report three refs to `0x0046a8a0`.
- [UID:00033C] separately covers a BrowserPane scalar deleting destructor at `0x00470690-0x004706e5` and keeps C++ blank because compiler wrapper emission is not source-authored.

Best inference:

- `0x0046a8a0` is BrowserPane-owned cleanup/destructor-family code, probably the non-deleting destructor body or an exception/unwind cleanup body.
- It should be split under `BrowserPane`, but C++ should remain blank until the three refs are classified.

Rejected alternatives:

- Emitting it as a normal source destructor now risks duplicating or contradicting the scalar-deleting destructor coverage.
- Treating it as BrowserDialog-owned is inconsistent with the restored BrowserPane vtables.

Validation impact:

- Source docs should call it `BrowserPane` cleanup/destructor-family, not a general Browser helper.
- Formal C++ is not ready until call/ref context is resolved.

### BrowserDialog::NavigateToUrl At 0x0046a8c0

Evidence checked:

- Target covers `0x0046a8c0-0x0046a8d6`; [UID:000017] covers it as `0x0046a8c0-0x0046a8d7`.
- [UID:000017] reports one caller at `0x00513e7f`.
- [UID:000017] says it calls embedded BrowserControlPane navigation helper at `0x0046bd30`.
- [UID:000015] `BrowserControlPane` documents `NavigateBrowser` at `0x0046bd30` and places the BrowserControlPane child in `BrowserDialog` at `+0x26c`.

Best inference:

- The half-open function range should be `0x0046a8c0-0x0046a8d7`, with padding `0x0046a8d7-0x0046a8e0`.
- The source owner is `BrowserDialog`.
- This is source-ready once emitted through a `BrowserDialog` child page, provided the local parameter type follows accepted browser URL type naming.

Rejected alternatives:

- Keeping this method only inside [UID:0000Z5] hides a clear class method.
- Routing it to `BrowserControlPane` is wrong; BrowserControlPane is the callee/subobject, not the method owner.

Validation impact:

- This is the safest child for first formal C++ emission.

### BrowserPane::OnKeyEvent At 0x0046a8e0

Evidence checked:

- Target covers `0x0046a8e0-0x0046a900`; [UID:000019] describes `sub_46A8E0`.
- [UID:000019] says it consumes a key event when `a2[4] == 8` and `a2[8] == 0x90`; otherwise delegates to `sub_49E6E0(this, a2)`.
- Vtable refs exist at BrowserPane vtable locations `0x00613368`, `0x00613418`, `0x00613708`.
- [UID:0000IT] DialogPane docs confirm derived classes use DialogPane virtual/helper patterns and handler views around `+0xa0/+0xa4`.

Best inference:

- This is a BrowserPane virtual input handler.
- The high-level behavior is ready: consume a specific Back/modifier combination and delegate to DialogPane/base handling otherwise.
- Exact type and field names are not fully ready because the event structure still appears in generated form as indexed fields.

Rejected alternatives:

- Calling this a BrowserDialog method is inconsistent with BrowserPane vtable refs.
- Emitting raw array-field C++ in final source is not source-quality unless no accepted event type exists.

Validation impact:

- A child page should be created under `BrowserPane`.
- Formal C++ can be populated only if the implementation pass accepts a project-wide key-event type/field naming scheme; otherwise leave blank with precise pseudocode/prose.

### BrowserPane::OnCommand At 0x0046a910

Evidence checked:

- Target covers `0x0046a910-0x0046aa33`; [UID:000019] describes `sub_46A910`.
- Vtable slot refs place it at BrowserPane virtual tables `0x00613348`, `0x006133f8`, `0x00613638`, `0x006136e8`.
- [UID:000019] says handled command ids are `1111712880`, `1111713388`, `1111716975`, and `1394`.
- `int_convert.py` verification:
  - `1111712880` = `0x42436470`, big-endian FourCC `BCdp`.
  - `1111713388` = `0x4243666c`, big-endian FourCC `BCfl`.
  - `1111716975` = `0x4243746f`, big-endian FourCC `BCto`.
  - `1394` = `0x572`.
  - `624` = `0x270`, matching the AlertPane allocation size used by the function.
- [UID:0001OD] owns Browser alert strings:
  - `kBrowserDisposeAlertText`
  - `kBrowserNavigationFailedAlertText`
  - `kBrowserNavigationTimeoutAlertText`
  - `kBrowserWebBoardRequestTimeoutAlertText`
- [UID:0001OC] owns the shared `OK` button string at `0x00613a18`.
- [UID:00000B] `AlertPane` documents the constructor signature:
  - `AlertPane(const wchar_t *messageText, Pane *layoutReference, const wchar_t *primaryButtonText, const wchar_t *secondaryButtonText);`
- [UID:00012S] identifies `0x0049df20` as shared `DialogPaneActivatePendingControl`, not a Browser-private helper.

Best inference:

- This is BrowserPane-owned command dispatch for browser navigation/error commands.
- The generated idea that this constructs an alert and activates it is correct, but generated helper/global names are not source-quality.
- The source-quality implementation should use the browser alert constants, shared dialog OK string, `new AlertPane(...)`, and inherited/shared DialogPane activation.

Rejected alternatives:

- Treating `sub_49DF20(this)` as a BrowserPane-specific `ActivateItem()` is weaker than the exact DialogPane helper docs.
- Emitting `g_pDefaultAlertParams` or synthetic alert parameters is wrong; the supported constructor signature takes message/layout/buttons directly.
- Leaving the command ids as decimal values hides meaningful FourCC evidence.

Validation impact:

- This child is source-ready after split if local naming accepts command constants such as `kBrowserCommandDispose`, `kBrowserCommandNavigationFailed`, `kBrowserCommandNavigationTimeout`, and `kBrowserCommandWebBoardRequestTimeout`.

### BrowserDialog Constructor At 0x0046aa40

Evidence checked:

- Target covers `0x0046aa40-0x0046ad0a`.
- [UID:000017] reports constructor callers at `0x00513ebe` and `0x005a7079`.
- [UID:000017] says it first installs BrowserPane vtables `0x006132ec`, `0x00613360`, `0x00613390`, then BrowserDialog vtables `0x0061339c`, `0x00613410`, `0x00613440`.
- [UID:000017] says it writes `dword_67AB98` at `0x0046aab7` and `0x0046aabe`.
- [UID:0002WI] covers `0x0067ab98-0x0067ab9c.g_pBrowserDialog.md`, with initialization `0xffffffff`, constructor writes, destructor/cleanup clears, and reads from map/user pane callers.
- [UID:000017] says the constructor calls child-rect helper at `0x0046ab1d` and `0x0046ab5f`, then constructs `BrowserControlPane` at `0x0046ab86`.
- [UID:000015] says `m_browserControlPane` is at `+0x26c` and BrowserControlPane stores child HWND/COM host fields at `+0x11c` and `+0x120`.

Best inference:

- This is clearly `BrowserDialog::BrowserDialog`.
- It should be split under `BrowserDialog` and should probably remain in the Browser source-root file until the Browser source-tree split decision is resolved.
- It is reconstructable but not yet final C++ ready because the constructor is where most unresolved BrowserDialog field, layout, title/control, singleton, and child-rect helper names meet.

Rejected alternatives:

- Putting this constructor into the parent aggregate as formal C++ would make the aggregate emit only one of several class methods and would leave mixed-class material duplicated or orphaned.
- Creating an independent source file for BrowserDialog now is premature. Current project tree still routes Browser code to `NexusTK/browser/Browser.cpp`, and Browser split is an open project-level question.

Validation impact:

- Child docs should capture constructor facts now.
- Formal C++ should wait until field/helper names are normalized enough to avoid generated-looking source.

### Global, Field, Helper, And Type Meanings

Best-inferred meanings:

- `dword_67AB98` is `g_pBrowserDialog` or equivalent Browser module singleton/current dialog pointer. [UID:0002WI] already covers the exact storage slot.
- BrowserDialog `+0x26c` is the embedded/owned `BrowserControlPane` child field according to [UID:000015].
- BrowserControlPane `+0x11c` is a child/browser HWND field; `+0x120` is browser COM host/control pointer material.
- `word_60DB20` is an unresolved DialogPane constructor default/string/resource operand used by the raw BrowserPane constructor. Do not rename it beyond a cautious placeholder until callers/bytes are confirmed.
- `0x0046bd30` is BrowserControlPane navigation helper, source-facing `BrowserControlPane::NavigateBrowser` or accepted local equivalent.
- `0x0049df20` is shared DialogPane activation helper, source-facing inherited `DialogPane::ActivatePendingControl` or equivalent. It is not BrowserPane-owned.
- `0x0049feb0` is AlertPane construction with the supported [UID:00000B] signature.
- `0x00613a18` is the shared dialog OK string, not Browser-owned.
- `0x00613a20-0x00613ab0` are Browser alert constants and should be referenced by name in BrowserPane command C++.

Unresolved or provisional:

- Exact BrowserPane raw constructor parameters and their source names.
- Exact event type and field names for `OnKeyEvent`.
- Exact BrowserDialog constructor parameter list.
- Exact title/control/layout helper names used in `0x0046aa40-0x0046ad0a`.
- Whether BrowserDialog eventually deserves a separate `BrowserDialog.cpp` or stays in monolithic `Browser.cpp`.

### Caller / Reachability Analysis

Known reachability:

- No refs or pointer hits to raw `0x0046a860` in prior live IDA evidence.
- Three refs to `0x0046a8a0`.
- One code ref to `BrowserDialog::NavigateToUrl` at `0x00513e7f`.
- BrowserPane `OnKeyEvent` and `OnCommand` are reached by BrowserPane vtable slots.
- BrowserDialog constructor callers are `0x00513ebe` and `0x005a7079`.
- `g_pBrowserDialog` reads/writes connect BrowserDialog construction/destruction to MapPane/UserPane browser-entry logic.

Inference:

- BrowserPane command and input methods are virtual dispatch reachable.
- BrowserDialog constructor and navigation are direct-call reachable.
- Raw constructor reachability is still the weak point and should prevent formal aggregate C++.

### Owner / Source Placement

Recommended source ownership:

- Parent [UID:0000Z5] before split: temporary `Browser` source-root owner [UID:0000HV], blank C++.
- Parent [UID:0000Z5] after split: no direct source owner, non-emitting split/index.
- `0x0046a860` constructor-shaped body: [UID:000019] `BrowserPane`.
- `0x0046a8a0` cleanup wrapper: [UID:000019] `BrowserPane`.
- `0x0046a8c0` `NavigateToUrl`: [UID:000017] `BrowserDialog`.
- `0x0046a8e0` `OnKeyEvent`: [UID:000019] `BrowserPane`.
- `0x0046a910` `OnCommand`: [UID:000019] `BrowserPane`.
- `0x0046aa40` constructor: [UID:000017] `BrowserDialog`.

Recommended physical source placement for now:

- Keep child emitters routed through the Browser source-root until the broader Browser source-file split is decided.
- If class-specific source files are later approved, `BrowserDialog` methods can move to `NexusTK/browser/BrowserDialog.cpp` and `BrowserPane` methods to `NexusTK/browser/BrowserPane.cpp`, but that is a project-level source-tree decision, not required for this target.

### Open Questions Rechecked

Closed or best-inferred:

- `OnCommand` alert dispatch meaning is now stronger: it is Browser command FourCC/error dispatch through `AlertPane`, with `OK` from shared dialog constants and activation through DialogPane.
- `NavigateToUrl` direct owner is `BrowserDialog`; callee is `BrowserControlPane`.
- `g_pBrowserDialog` meaning is sufficiently proven by [UID:0002WI], constructor writes, cleanup clears, and MapPane/UserPane reads.
- Aggregate C++ should stay blank.

Still open:

- Raw constructor endpoint: target prose says `0x0046a860-0x0046a898`; generated source-map says `0x0046a860-0x0046a89a`. The implementation pass must byte-confirm the exact half-open range.
- Raw constructor source signature and parameter names.
- Whether `0x0046a8a0` is a non-deleting destructor body or exception cleanup wrapper.
- Accepted event type/field names for `OnKeyEvent`.
- Accepted BrowserDialog constructor field/helper names.
- Final Browser physical source split.

### C++ Readiness Gate

Current target average is `(85 + 87) / 2 = 86.0`, which passes the numeric gate, and `auto-generated/-ag-memory-coverage.md` routes [UID:0000Z5] to `auto-generated/NexusTK/browser/Browser.cpp`.

Despite passing the numeric gate and having a nonblank emitter route, [UID:0000Z5] should not receive formal aggregate C++. The blocker is source shape, not score. A mixed aggregate would either emit multiple unrelated class methods through one parent marker or duplicate methods that should belong to class children.

Child-level readiness:

- `BrowserDialog::NavigateToUrl`: ready for first formal C++ after child split.
- `BrowserPane::OnCommand`: ready for first formal C++ after child split if command constant names are accepted.
- `BrowserPane::OnKeyEvent`: near-ready; needs accepted event type/field names.
- `BrowserDialog::BrowserDialog`: reconstructable but not yet polished enough for formal C++.
- BrowserPane raw constructor: reconstructable as a body, but not formal C++ ready because of boundary/signature/no-ref issues.
- BrowserPane cleanup wrapper: not formal C++ ready until destructor/cleanup classification is resolved.

## Proposed Child Inventory And Range Decisions

All ranges are half-open. Entries marked byte-confirm must be checked against IDA/local bytes before documentation implementation.

| Proposed child | Best range | Owner | Reconstructable | C++ readiness | Notes |
|---|---:|---|---|---|---|
| BrowserPane raw constructor-shaped body | `0x0046a860-0x0046a89a` byte-confirm | `000019` BrowserPane | TRUE | blank | Existing target prose says end `0x0046a898`; generated source-map says `0x0046a89a` and `boundary_ida_disputed`. Must include `retn 8` endpoint if confirmed. |
| Padding after raw constructor | `0x0046a89a-0x0046a8a0` byte-confirm | ignored | FALSE | blank | If byte-confirmed, add/adjust ignored padding. If old `0x0046a898` end is proven instead, use `0x0046a898-0x0046a8a0`. |
| BrowserPane cleanup/destructor-family wrapper | `0x0046a8a0-0x0046a8bf` | `000019` BrowserPane | TRUE | blank | Restores BrowserPane vtables and calls base cleanup; classify refs before destructor C++. |
| Padding after cleanup wrapper | `0x0046a8bf-0x0046a8c0` | ignored | FALSE | blank | One-byte alignment/padding if endpoint is exact. |
| BrowserDialog::NavigateToUrl | `0x0046a8c0-0x0046a8d7` | `000017` BrowserDialog | TRUE | ready | Thin wrapper to BrowserControlPane navigation helper. |
| Padding after NavigateToUrl | `0x0046a8d7-0x0046a8e0` | ignored | FALSE | blank | Aligns next virtual handler. |
| BrowserPane::OnKeyEvent | `0x0046a8e0-0x0046a901` | `000019` BrowserPane | TRUE | near-ready | Consumes specific Back/modifier event; delegates to DialogPane/base. Needs event type naming. |
| Padding after OnKeyEvent | `0x0046a901-0x0046a910` | ignored | FALSE | blank | Aligns command handler. |
| BrowserPane::OnCommand | `0x0046a910-0x0046aa34` | `000019` BrowserPane | TRUE | ready after constants | FourCC/error command dispatch to AlertPane plus DialogPane activation. |
| Padding after OnCommand | `0x0046aa34-0x0046aa40` | ignored | FALSE | blank | Aligns BrowserDialog constructor. |
| BrowserDialog::BrowserDialog | `0x0046aa40-0x0046ad0a` | `000017` BrowserDialog | TRUE | blank for now | Proven constructor, but field/helper/source parameter names are not final enough. |
| Padding after constructor | `0x0046ad0a-0x0046ad10` | ignored | FALSE | blank | Already covered in coverage report before [UID:00020X]. |

If implementation avoids child docs, update [UID:0000Z5] prose to contain the child inventory above and keep the parent reconstructable but blank. If implementation creates child docs, convert [UID:0000Z5] to a non-emitting split/index.

## First-Draft C++ Guidance For Future Implementation

This section is guidance only. No C++ was edited in this report pass.

### BrowserDialog::NavigateToUrl

This is the best first formal C++ candidate after a child split. Use accepted project pointer/string typedefs if they differ from this draft.

```cpp
void BrowserDialog::NavigateToUrl(const wchar_t *url)
{
    m_browserControlPane.NavigateBrowser(url, NULL);
}
```

If the child is held by pointer rather than embedded object in the accepted class layout, adjust the call form, but keep ownership on `BrowserDialog` and callee semantics on `BrowserControlPane`.

### BrowserPane::OnCommand

This is also suitable for formal C++ after split, provided constants are added or accepted. The important source-quality points are named FourCC command ids, Browser-owned alert text constants, shared OK button text, and DialogPane activation.

```cpp
bool BrowserPane::OnCommand(int commandId)
{
    const wchar_t *messageText = NULL;

    switch (commandId) {
    case kBrowserCommandDispose:                 // 0x42436470, "BCdp"
        messageText = kBrowserDisposeAlertText;
        break;
    case kBrowserCommandNavigationFailed:        // 0x4243666c, "BCfl"
        messageText = kBrowserNavigationFailedAlertText;
        break;
    case kBrowserCommandNavigationTimeout:       // 0x4243746f, "BCto"
        messageText = kBrowserNavigationTimeoutAlertText;
        break;
    case kBrowserCommandWebBoardRequestTimeout:  // 0x00000572
        messageText = kBrowserWebBoardRequestTimeoutAlertText;
        break;
    default:
        return true;
    }

    new AlertPane(messageText, this, kDialogOkButtonString, NULL);
    ActivatePendingControl();
    return true;
}
```

Implementation should adapt the return type to the confirmed virtual signature. If existing Browser/DialogPane conventions return `int` rather than `bool`, preserve the project convention.

### BrowserPane::OnKeyEvent

Near-ready but gated by event field names. A source-quality implementation should avoid raw `a2[4]`/`a2[8]` indexing if the project has an accepted key-event type.

```cpp
bool BrowserPane::OnKeyEvent(KeyEvent *event)
{
    if (event != NULL && event->keyCode == VK_BACK && event->modifierFlags == 0x90)
        return true;

    return DialogPane::OnKeyEvent(event);
}
```

The field names above are descriptive placeholders. Do not emit this exact code until the accepted input-event layout is known.

### BrowserPane Constructor-Shaped Body

Do not emit the generated no-argument constructor. The raw body returns with `retn 8`, has no refs, and forwards two stack arguments into `DialogPane` construction with `word_60DB20`. At most, a future source draft should look like a two-argument BrowserPane constructor after confirming argument meaning:

```cpp
BrowserPane::BrowserPane(int controlId, int mode)
    : DialogPane(/* unresolved word_60DB20 operand */, controlId, mode)
{
}
```

The names `controlId` and `mode` are placeholders. This should stay out of formal C++ until byte and caller evidence exist.

### BrowserDialog Constructor

Do not emit formal C++ yet. A future implementation should first normalize:

- The constructor parameter list.
- `g_pBrowserDialog` storage and ownership rules.
- BrowserDialog field names around the embedded BrowserControlPane.
- Title/control construction helper names.
- Child rectangle helper signatures.
- EPF/default layout globals and their source names.

## Support Documentation Effects

Recommended support changes for a future implementation callback:

- [UID:000019] `by-class/BrowserPane.md`
  - Add the exact child split inventory for raw constructor, cleanup wrapper, `OnKeyEvent`, and `OnCommand`.
  - Note that `0x0046a860` is constructor-shaped but still no-function/no-ref and probably `0x0046a860-0x0046a89a` if byte-confirmed.
  - Replace any Browser-private interpretation of `0x0049df20` with shared DialogPane activation helper semantics.
  - Use Browser alert constants and shared OK string for `OnCommand`.
- [UID:000017] `by-class/BrowserDialog.md`
  - Add the exact child split inventory for `NavigateToUrl` and the constructor.
  - Keep `g_pBrowserDialog` linked to [UID:0002WI].
  - State that constructor C++ is blocked on field/helper/source split cleanup, not on ownership confidence.
- [UID:0000HV] `by-file/Browser.md`
  - Mark [UID:0000Z5] as an overbroad split candidate.
  - Keep current physical route to `NexusTK/browser/Browser.cpp` unless/until BrowserPane/BrowserDialog file split is approved.
- [UID:0002WI] `by-memory/0x0067ab98-0x0067ab9c.g_pBrowserDialog.md`
  - No immediate metadata change required.
  - Future cleanup may introduce a dedicated `by-global/g_pBrowserDialog.md` if the project chooses to promote this global from memory slot to named global.
- [UID:0001OD] Browser alert strings and [UID:0001OC] dialog OK string
  - No ownership change required.
  - Ensure future `OnCommand` C++ references these constants rather than recreating literals.
- [UID:00012S] DialogControlPaneHelpers
  - No ownership change required.
  - Use it as support evidence for `ActivatePendingControl` naming.

## Target Implementation Checklist

For a future implementation callback, perform these steps in order:

1. Re-open IDA MCP or local bytes and byte-confirm `0x0046a860` through the `retn 8`; decide whether the half-open raw constructor range is `0x0046a860-0x0046a89a` or the older documented `0x0046a860-0x0046a898`.
2. Byte-confirm the exact endpoints for `0x0046a8a0`, `0x0046a8c0`, `0x0046a8e0`, `0x0046a910`, and `0x0046aa40`.
3. If split is approved, create exact child by-memory pages for the source-bearing ranges in the child inventory table.
4. Add ignored padding rows/docs for alignment gaps that are not already covered, especially the raw-constructor-to-cleanup gap and the gaps between short methods.
5. Convert [UID:0000Z5] into a reviewed non-emitting split/index container after children exist:
   - `RECONSTRUCTABLE:FALSE`
   - `CANONICAL_OWNER:NONE`
   - blank `EMITTER_UIDS`
   - blank C++
   - explanatory prose pointing to child docs
6. If split is not approved, leave [UID:0000Z5] as `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000HV`, `EMITTER_UIDS:0000HV`, but keep C++ blank and update prose with this report's child inventory.
7. Update [UID:000019] `BrowserPane` support docs with command constants, alert construction, DialogPane activation helper, and raw constructor caveats.
8. Update [UID:000017] `BrowserDialog` support docs with `NavigateToUrl`, constructor, `g_pBrowserDialog`, and BrowserControlPane child facts.
9. Update [UID:0000HV] `Browser` file docs to say this range is not a final source-emitting unit.
10. Update the supervisor-owned coverage row using the exact no-split row or exact post-split parent row above.
11. After child UIDs are allocated, add child coverage rows immediately around the current [UID:0000Z5] coverage location, preserving sorted address order.
12. Run the documentation validator and project completion stats generator required by the supervisor workflow.

## Support Implementation Checklist

Do not implement C++ in [UID:0000Z5]. Instead, if C++ emission is approved after split:

- Emit `BrowserDialog::NavigateToUrl` through the `BrowserDialog` child route.
- Emit `BrowserPane::OnCommand` through the `BrowserPane` child route only after accepted command constant names are present.
- Consider `BrowserPane::OnKeyEvent` only after accepted key event type/field names are available.
- Keep BrowserPane raw constructor C++ blank until its exact range and two-argument signature are proven.
- Keep BrowserPane cleanup wrapper C++ blank until the three refs classify it as source destructor body rather than compiler cleanup.
- Keep BrowserDialog constructor C++ blank until constructor parameter, field, layout, and helper names are source-quality.
- Keep [UID:0000Z5] aggregate C++ blank permanently after split.

## Generated Output Review

Generated files were useful as leads, not as final source authority.

Observed generated state:

- `auto-generated/-ag-memory-coverage.md` routes [UID:0000Z5] to `auto-generated/NexusTK/browser/Browser.cpp`.
- `auto-generated/NexusTK/browser/Browser.cpp` contains only an empty emitter marker for [UID:0000Z5]:
  - `// UID:0000Z5 | by-memory\0x0046a860-0x0046ad0a.BrowserPaneAndDialog.md | Completion:85 | Confidence:87 | Empty Emitter Marker`
- `simroot_v2/browser/Browser.cpp` contains generated source drafts for BrowserPane methods, but the raw constructor draft is not accepted because it uses a no-argument source shape despite the `retn 8` evidence.
- `simroot_v2/browser/Browser.cpp.source_map.json` and `Browser.meta_wave3` list `0x0046a860-0x0046a89a` with a boundary-disputed marker.

Generated assumptions to reject or downgrade:

- `BrowserPane::BrowserPane()` as no-argument formal C++.
- Synthetic globals or params such as generated alert defaults where [UID:00000B] already documents the real AlertPane signature.
- Modernized style choices such as `constexpr`/`nullptr` if they do not match the surrounding reconstructed source style.
- Raw `dword_67AB98` name in final C++; use or preserve the documented `g_pBrowserDialog` meaning once accepted.

## Final Recommendation

[UID:0000Z5] is a high-confidence address cluster but not a clean final source unit. Its current `85/87` score is reasonable for the unsplit aggregate. The score should not be used to force aggregate C++ because the range mixes BrowserPane and BrowserDialog ownership and contains a raw no-function constructor-shaped body.

Best next action is a split implementation pass:

- exact BrowserPane child docs for raw constructor, cleanup, key event, and command dispatch;
- exact BrowserDialog child docs for navigation and construction;
- ignored padding docs/rows for alignment gaps;
- parent [UID:0000Z5] converted to non-emitting split/index.

If no split pass is performed now, leave [UID:0000Z5] reconstructable with Browser source-root ownership and blank C++, and apply only the no-split coverage row text in this report.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0000Z5-BrowserPaneAndDialog-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:23","uid":"0000Z5"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
