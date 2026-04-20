<!-- If you're running this on a VSCode fork IDE, try to run the Markdown using Ctrl+Shift+V, Cmd+Shift+V or Ctrl+K then V -->

# UML diagrams using Mermaid

### Example of an Entity Relationship Diagram

```mermaid

---
config:
  theme: 'base'
  themeVariables:
    primaryColor: '#80A98C'
    primaryBorderColor: '#004D40'
    lineColor: '#004D40'
    textColor: '#FFFFFF'
---
erDiagram
    Customers ||--|{ Orders : "places"
    Publishers ||--|{ Books : "publishes"
    Orders ||--|{ Order_Items : "has"
    Books ||--|{ Order_Items : "included_in"
    Books ||--|{ Authored : "has"
    Authors ||--|{ Authored : "writes"

    Customers {
        INT customer_id PK
        VARCHAR name
        VARCHAR email
        VARCHAR phone
        VARCHAR address
    }
    
    Publishers {
        INT publisher_id PK
        VARCHAR name
    }
    
    Authors {
        INT author_id PK
        VARCHAR name
    }
    
    Books {
        INT book_id PK
        VARCHAR title
        DECIMAL price
        INT stock
        INT publisher_id FK
    }
    
    Orders {
        INT order_id PK
        DATE date
        DECIMAL total_amount
        INT customer_id FK
    }
    
    Order_Items {
        INT order_id PK, FK
        INT book_id PK, FK
        INT quantity
        DECIMAL unit_price
    }
    
    Authored {
        INT book_id PK, FK
        INT author_id PK, FK
    }
```

### Example of a Flowchart (as a Conceptual Data Model)

```mermaid

flowchart TD
    %% Style definitions to emulate Peter Chen notation
    classDef entity fill:#ffffff,stroke:#000000,stroke-width:2px;
    classDef relationship fill:#ffffff,stroke:#000000,stroke-width:2px,shape:diamond;
    classDef attribute fill:#ffffff,stroke:#000000,stroke-width:1px,shape:ellipse;

    %% Entities (Rectangles)
    A[Student]:::entity
    T[Class]:::entity
    P[Professor]:::entity
    S[Room]:::entity
    D[Subject]:::entity

    %% Relationships (Diamonds)
    R_Mat{Enrolls}:::relationship
    R_TD{Contains / Offered}:::relationship
    R_Min{Teaches}:::relationship
    R_Abr{Hosts}:::relationship
    R_Lec{Coordinates}:::relationship

    %% --- Student Attributes ---
    A_ID([<u>EnrollmentID</u>]):::attribute
    A_Nome([Name]):::attribute
    A_CPF([CPF]):::attribute
    A --- A_ID & A_Nome & A_CPF

    %% --- Professor Attributes ---
    P_ID([<u>ProfessorID</u>]):::attribute
    P_Nome([ProfessorName]):::attribute
    P_Sexo([Gender]):::attribute
    P_Data([BirthDate]):::attribute
    P --- P_ID & P_Nome & P_Sexo & P_Data

    %% --- Room Attributes ---
    S_ID([<u>RoomID</u>]):::attribute
    S_Nome([Name]):::attribute
    S --- S_ID & S_Nome

    %% --- Subject Attributes ---
    D_ID([<u>SubjectID</u>]):::attribute
    D_Nome([SubjectName]):::attribute
    D_CH([Workload]):::attribute
    D_NC([CreditNumber]):::attribute
    D --- D_ID & D_Nome & D_CH & D_NC

    %% --- Class Attributes ---
    T_ID([<u>ClassID</u>]):::attribute
    T_Hor([Schedule]):::attribute
    T_Data([Date]):::attribute
    T --- T_ID & T_Hor & T_Data

    %% --- Relationship Links and Cardinalities ---
    
    %% Student -> Enrollment -> Class (N:M with relationship attributes)
    A ---|"(1,N)"| R_Mat ---|"(0,N)"| T
    R_Mat_Data([Date]):::attribute
    R_Mat_Sit([Status]):::attribute
    R_Mat_Nota([Grade]):::attribute
    R_Mat --- R_Mat_Data & R_Mat_Sit & R_Mat_Nota

    %% Class -> ClassSubject -> Subject (N:M with relationship attribute)
    T ---|"(1,N)"| R_TD ---|"(1,N)"| D
    R_TD_Data([RegistrationDate]):::attribute
    R_TD --- R_TD_Data

    %% Professor -> Class (1:N)
    P ---|"(1,1)"| R_Min ---|"(0,N)"| T
    
    %% Room -> Class (1:N)
    S ---|"(1,1)"| R_Abr ---|"(0,N)"| T
    
    %% Professor -> Subject (1:N)
    P ---|"(1,1)"| R_Lec ---|"(0,N)"| D
```
  
  
### Example of a Component Diagram

```mermaid

---
config:
  theme: 'base'
  themeVariables:
    fontSize: '20px'
    strokeWidth: '10px'
    primaryColor: '#1A4B9F'
    tertiaryColor: '#FFFFFF'
    tertiaryBorderColor: '#1A4B9F'
---

graph TD
    subgraph User Application
        direction TB
        MAIN["Main Application (main.c)"]
    end

    %% Creates an invisible parent subgraph to align children horizontally
    subgraph System Firmware
        direction LR

        subgraph Common Layer
            direction LR
            COMMON["System_Common (.h/.c)"]
        end

        subgraph Device Layer
            direction LR
            DEVICE1["Dev_DataAdjust (.h/.c)"]
        end

        subgraph App Layer
            direction TB
            MANAGER["App_Manager (.h/.c)"]
            COMMUN["App_Communication (.h/.c)"]
            SENSORS["App_Sensors (.h/.c)"]
        end

        subgraph HAL Layer
            direction TB
            DRVH1_A["HAL_HW1_A (.h/.c)"]
            DRVH1_B["HAL_HW1_B (.h/.c)"]
            DRVH2["HAL_HW2 (.h/.c)"]
            DRVH3["HAL_HW3 (.h/.c)"]
            DRVH4["HAL_HW4 (.h/.c)"]
            DRVH5["HAL_HW5 (.h/.c)"]
        end
    end

    subgraph Hardware
        direction TB
        HARDWARE1["HARDWARE1"]
        HARDWARE2["HARDWARE2"]
        HARDWARE3["HARDWARE3"]
        HARDWARE4["HARDWARE4"]
        HARDWARE5["HARDWARE5"]
    end

    MAIN --> MANAGER

    MANAGER --> COMMUN
    MANAGER --> SENSORS

    COMMUN ---> DRVH1_A
    COMMUN ---> DRVH1_B
    COMMUN ---> DRVH2
    COMMUN ---> DRVH3
    COMMUN --> SENSORS
    
    SENSORS ---> DRVH3
    SENSORS ---> DRVH2
    SENSORS ---> DRVH4

    SENSORS --> DEVICE1
    
    DRVH1_A --> HARDWARE1
    DRVH1_B --> HARDWARE1
    DRVH2 --> HARDWARE2
    DRVH3 --> HARDWARE3
    DRVH4 --> HARDWARE4
    DRVH5 --> HARDWARE5
    
    %% Configurações Globais Simplificadas
    classDef default color:white
    linkStyle default stroke-width:3px
    
```
  
  
### Example of a Class Diagram

```mermaid

---
config:
  theme: 'base'
  themeVariables:
    textColor: '#FFFFFF'
    primaryColor: '#1A4B9F'
    primaryBorderColor: '#FFFFFF'
---

classDiagram
    direction TD %% Defines a clear Top-Down direction
    
    class System_Common {
        +App_Status_e
        +App_Peripheral_State_e
        +BoolFlags_t
        +ERROR_LOG()
    }

    class App_Status_e {
        <<enumeration>>
        STATUS_OK_E
        STATUS_FALSE_E
        STATUS_NOT_INITIALIZED_E
        STATUS_INVALID_FUNCTION_E
        STATUS_INVALID_PARAMS_E
        STATUS_GPIO_FAULT_E
        STATUS_WRONG_USAGE_E
        STATUS_TIMEOUT_E
        STATUS_BUS_OFF_E
        STATUS_SYSTEM_FAULT_E
        +Get_AppStatus()
        +ERROR_LOG()
        +LOG()
    }

    class App_Peripheral_State_e {
        <<enumeration>>
        STATE_INIT
        STATE_IDLE
        STATE_RUNNING
        STATE_READING
        STATE_WRITING
        STATE_WAITING
        +Get_AppState()
    }

    class BoolFlags_t {
        <<type>>
        +bools | DigitalInputs_t | EnableMask_t
        +false | BOOL_FALSE
        +true  | BOOL_TRUE
        +SWITCH_FLAG()
        +SET_FLAG()
        +CLEAR_FLAG()
        +GET_FLAG()
    }

    %% Usage: Common "uses" App_Status_e.
    %% The dotted arrow indicates a usage dependency.
    System_Common ..> App_Status_e
    System_Common ..> App_Peripheral_State_e
    System_Common ..> BoolFlags_t

```
  
  
### Examples of a Sequence Diagram  


###### Example 1

```mermaid

---
config:
  theme: 'base'
  themeVariables:
    primaryColor: '#1A4B9F'
    primaryBorderColor: '#1A4B9F'
    actorTextColor: '#FFFFFF'
    signalColor: '#1A4B9F'
    signalTextColor: '#000000'
    noteBkgColor: '#0091D6'
    noteBorderColor: '#0091D6'
    noteTextColor: '#FFFFFF'
---

sequenceDiagram
    participant App as Application
    participant ADC as HAL_ADC
    participant LowLevel as Low Level Driver

    App->>ADC: HAL_ADC_Init(&get_value_func)
    ADC-->>App: Returns STATUS_OK_E

    App->>ADC: HAL_ADC_GetValue(channel, &value_array)
    ADC->>LowLevel: calls get_value_func(channel)
    Note right of LowLevel: Hardware performs conversion
    LowLevel-->>ADC: Returns digital value
    ADC-->>App: Populates value_array and returns STATUS_OK_E
```
  

###### Example 2

```mermaid

---
config:
  theme: 'base'
  themeVariables:
    primaryColor: '#1A4B9F'
    primaryBorderColor: '#1A4B9F'
    actorTextColor: '#FFFFFF'
    signalColor: '#1A4B9F'
    signalTextColor: '#000000'
    noteBkgColor: '#0091D6'
    noteBorderColor: '#0091D6'
    noteTextColor: '#FFFFFF'
---

sequenceDiagram
    participant App as Application
    participant TIM as HAL_TIM
    participant Tick as Hardware_SysTick

    App->>TIM: HAL_TIM_Init()
    TIM-->>App: Returns STATUS_OK_E

    App->>TIM: HAL_TIM_Start(TIMER_1, 1000)
    note right of TIM: Stores initial tick and interval
    TIM-->>App: Returns STATUS_OK_E

    loop Main System Loop
        App->>TIM: HAL_TIM_HasExpired()
        TIM->>Tick: calls get_tick_func()
        alt 
            Tick-->>TIM: 
            TIM-->>App: Returns STATUS_FALSE_E
        else
            note right of App: TIM: 1000ms passed...
            Tick-->>TIM: 
            TIM-->>App: Returns STATUS_OK_E (Expired)
        end
    end
```
  

### Example of a Activities Diagram

###### Example 1

```mermaid

---
config:
  theme: 'base'
  themeVariables:
    fontSize: '12px' 
    textColor: '#FFFFFF'
    lineColor: '#000000'
    primaryColor: '#1A4B9F'
    primaryBorderColor: '#1A4B9F'
    secondaryColor: '#0091D6'
    tertiaryColor: '#FFFFFF'
    tertiaryBorderColor: '#000000'
---

graph TD
    subgraph "Sensing State Machine"
        A["IDLE<br>(Waiting to Start)"]
        B["ENABLING SENSORS<br>HAL_GPIO_WritePin(EN, HIGH)"]
        C["WAITING STABILIZATION<br>HAL_TIM_Start(timer, delay)"]
        D["READING SENSORS<br>HAL_GPIO_ReadPin(dig_in)<br>HAL_ADC_GetValue(adc_ch)"]
        E["PROCESSING DATA<br>(E.g., Calculate average, filter)"]
        F["DISABLING SENSORS<br>HAL_GPIO_WritePin(EN, LOW)"]
        G["DONE<br>(Results Ready)"]
        H["FAULT<br>(Operation Error)"]

        A --"[ Start Measurement ]"--> B
        B --"[ Success ]"--> C
        B --"[ Failure ]"--> H
        C --"[ HAL_TIM_HasExpired ]"--> D
        D --"[ Readings OK ]"--> E
        D --"[ Reading Failure ]"--> H
        E --"[ Processing OK ]"--> F
        F --"[ Disabled Successfully ]"--> G
        G --> A
        H --"[ New Cycle ]"--> A
    end

    style A fill:#00B39C,stroke:#00B39C
    style G fill:#00B39C,stroke:#00B39C
    style H fill:#EF5E31,stroke:#EF5E31
    
    class A,B,C,D,E,F,G,H whiteText
    linkStyle 0,1,2,3,4,5,6,7,8,9 color:white

    classDef whiteText color:white, stroke-width:2px

```
  
###### Example 2

```mermaid

---
config:
  theme: 'base'
  themeVariables:
    fontSize: '14px'
    textColor: '#FFFFFF'
    lineColor: '#000000'
    primaryColor: '#1A4B9F'
    primaryBorderColor: '#1A4B9F'
    secondaryColor: '#0091D6'
    tertiaryColor: '#FFFFFF'
    tertiaryBorderColor: '#000000'
---

graph TD
    %% Nodes
    CALL("App_Manager_FSM")
    START("STATE_INIT<br>(Initialization)")
    CHECK_INIT_SENSORS{"Sensors Init OK?"}
    CHECK_INIT_CAN{"CAN Init OK?"}
    
    IDLE["STATE_IDLE<br>(Waiting for Timer)"]
    CHECK_TIMER{"Timer Trigger?"}
    
    READ_SENSORS["STATE_READING_SENSORS<br>(Requests Sensor Readings)"]
    CHECK_SENSORS_DONE{"Reading Completed?"}
    
    TX_CAN["STATE_TRANSMITTING_CAN<br>(Requests CAN Transmission)"]
    CHECK_TX_DONE{"Transmission Completed?"}
    
    ERROR["STATE_ERROR<br>(Fault Handling)"]

    %% Initialization Flow
    CALL --> START
    START --> CHECK_INIT_SENSORS
    CHECK_INIT_SENSORS -- Yes --> CHECK_INIT_CAN
    CHECK_INIT_SENSORS -- No --> ERROR
    
    CHECK_INIT_CAN -- Yes --> IDLE
    CHECK_INIT_CAN -- No --> ERROR
    
    %% Main Loop
    IDLE --> CHECK_TIMER
    CHECK_TIMER -- No --> IDLE
    CHECK_TIMER -- Yes --> READ_SENSORS
    
    %% Reading Phase
    READ_SENSORS --> CHECK_SENSORS_DONE
    CHECK_SENSORS_DONE -- In Progress --> READ_SENSORS
    CHECK_SENSORS_DONE -- Yes --> TX_CAN
    CHECK_SENSORS_DONE -- Error --> ERROR
    
    %% Transmission Phase
    TX_CAN --> CHECK_TX_DONE
    CHECK_TX_DONE -- In Progress --> TX_CAN
    CHECK_TX_DONE -- Yes --> IDLE
    CHECK_TX_DONE -- Error --> ERROR
    
    %% Recovery
    ERROR -- "Recovery Attempt" --> START

    %% Styles
    style READ_SENSORS fill:#0091D6,stroke:#0091D6
    style TX_CAN fill:#0091D6,stroke:#0091D6
    style ERROR fill:#EF5E31,stroke:#EF5E31
    
    class CALL,START,CHECK_INIT_SENSORS,CHECK_INIT_CAN,IDLE,CHECK_TIMER,READ_SENSORS,CHECK_SENSORS_DONE,TX_CAN,CHECK_TX_DONE,ERROR whiteText
    classDef whiteText color:white
    linkStyle default color:white

```

### Example of a Gantt Chart

```mermaid

---
config:
  theme: 'base'
  themeVariables:
    primaryColor: '#F4A261'
    primaryBorderColor: '#E76F51'
    gridColor: '#E9C46A'
    textColor: '#264653'
---

gantt
    title Project Schedule
    dateFormat  YYYY-MM-DD
    axisFormat  %m/%d
    
    section Planning Phase
    Requirements Gathering :a1, 2026-04-01, 7d
    Architecture Design    :after a1, 5d
    
    section Development Phase
    Backend Implementation :2026-04-10, 10d
    Unit Testing           :2026-04-18, 5d

```

### Example of a Mindmap

```mermaid

---
config:
  theme: 'forest'
---

mindmap
  root((Mermaid))
    UML
      Class Diagram
      Sequence Diagram
      Component Diagram
    Projects
      Gantt
      Timeline
    Data
      Pie Chart
      Sankey
      XY Chart

```

### Example of a Gitgraph

```mermaid

---
config:
  theme: 'base'
  themeVariables:
    git0: '#FF007F'
    git1: '#00E5FF'
    git2: '#FFEA00'
    commitLabelColor: '#FFFFFF'
    commitLabelBackground: '#111111'
    commitLabelFontSize: '14px'
---

gitGraph
    commit id: "Initial commit"
    branch develop
    checkout develop
    commit id: "Add Auth module"
    commit id: "Fix login bug"
    checkout main
    merge develop id: "Release v1.0" tag: "v1.0"
    branch hotfix
    checkout hotfix
    commit id: "Fix security flaw"
    checkout main
    merge hotfix id: "Release v1.0.1" tag: "v1.0.1"

```

### Example of a State Diagram

```mermaid

---
config:
  theme: 'base'
  themeVariables:
    primaryColor: '#C5CAE9'
    primaryBorderColor: '#3F51B5'
    lineColor: '#303F9F'
    textColor: '#1A237E'
---

stateDiagram-v2
    [*] --> AwaitingPayment
    AwaitingPayment --> Processing : Pay
    AwaitingPayment --> Cancelled : Timeout
    Processing --> Shipped : Confirmed
    Processing --> Failed : Card Error
    Shipped --> [*]
    Cancelled --> [*]
    Failed --> AwaitingPayment : Retry

```

### Example of a Pie Chart

```mermaid

---
config:
  theme: 'base'
  themeVariables:
    pie1: '#FF9999'
    pie2: '#99CCFF'
    pie3: '#99FF99'
    pie4: '#FFCC99'
    pieTitleTextSize: '22px'
---

pie title Language Distribution in Repository
    "JavaScript" : 45
    "TypeScript" : 30
    "Python" : 15
    "HTML/CSS" : 10

```

### Example of a Timeline

```mermaid

---
config:
  theme: 'base'
  themeVariables:
    c1: '#9B59B6'
    c2: '#3498DB'
    c3: '#1ABC9C'
    c4: '#E67E22'
    c5: '#E74C3C'
---

timeline
    title Release History
    2023 : Q1 : MVP Release
         : Q3 : First 1000 customers
    2024 : Q2 : International Expansion
         : Q4 : Series A Funding
    2025 : Q1 : Mobile App Launch

```

### Example of a Requirement Diagram

```mermaid

---
config:
  theme: 'base'
  themeVariables:
    primaryColor: '#F5F5F5'
    primaryBorderColor: '#757575'
    textColor: '#212121'
    lineColor: '#424242'
---

requirementDiagram
    requirement Authentication {
    id: 1
    text: The system must allow login via OAuth.
    risk: high
    verifymethod: test
    }

    element LoginModule {
    type: component
    }

    LoginModule - satisfies -> Authentication

```
