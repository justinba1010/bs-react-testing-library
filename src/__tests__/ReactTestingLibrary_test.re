open Jest;

module Element = {
  [@react.component]
  let make = (~greeting="Greeting") => {
    <div style={ReactDOMRe.Style.make(~color="rebeccapurple", ())}>
      <h1 />
    </div>
  };
};

module FireEventClick = {
  [@react.component]
  let make = (~clickFx) => {
    <div onClick=clickFx />
  }
};

external unsafeAsElement : Dom.node => Dom.element = "%identity";
[@bs.get] external firstChild : Dom.element => Dom.node = "firstChild";
[@bs.get] external innerHTML : Dom.node => string = "innerHTML";

describe("ReactTestingLibrary", () => {
  open ReactTestingLibrary;
  open Expect;

  testAsync("FireEvent", finish => {
    (<FireEventClick clickFx={
      (_) => finish(expect(true) |> toBe(true));
      }
    />)
    |> render
    |> container
    |> FireEvent.click;
    }
    );
  test("render works", () => {
    (<Element />)
      |> render
      |> expect
      |> toMatchSnapshot;
  });
});
